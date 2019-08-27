#include<stdio.h>
#include<assert.h>
#include<stdio.h>
#include"threadpool.h"
#include<stdlib.h>
#include<pthread.h>
#include "queue.h"
//指针：线程池
static CThread_pool* pool=NULL;
static void* thread_routine(void*);
//初始化－－线程数量
bool pool_init(int num)
{
	//申请空间
	pool=(CThread_pool*)malloc(sizeof(CThread_pool));
	if(pool==NULL)
		return false;
	pool->tid=(pthread_t*)malloc(sizeof(pthread_t)*num);//存储线程ｉｄ
	if(pool->tid==NULL)
	{
		free(pool);//释放
		pool=NULL;
		return false;
	}
	//初始化条件量／锁
	initQueue(&(pool->queue));
	pthread_mutex_init(&(pool->mutex),NULL);	
	pthread_cond_init(&(pool->notfull_cond),NULL);
	pool->shutdown=false;
	pool->max_thread_num=num;
	pool->cur_queue_size=0;
	//创建线程
	int i=0;
	for(i=0;i<pool->max_thread_num;i++)
	{
		//让
		pthread_create(pool->tid+i,NULL,thread_routine,NULL);
		printf("thread_%d of pool:0x%lx\n",i,pool->tid[i]);
	}
	return true;
}
//向线程池中添加任务
bool pool_add_worker(void*(*process)(void*),void* arg)
{
	CNode_task node;
	node.process=process;
	node.arg=arg;
	//多个线程共享:竞争
	pthread_mutex_lock(&(pool->mutex));
	//阻塞等待
	while(isFull(&(pool->queue)) && !pool->shutdown)
	{
		printf("任务为满,阻塞等待\n");
		pthread_cond_wait(&(pool->full_cond),&(pool->mutex));//等待消息(什么时候发送消息--不为满)
	}
	if(!push(node,&(pool->queue)))
	{
		printf("添加失败\n");
		pthread_mutex_unlock(&(pool->mutex));
		return false;
	}
	pool->cur_queue_size++;
	printf("add task:%d\n",pool->cur_queue_size);
	pthread_mutex_unlock(&(pool->mutex));
	//通知唤醒－－如果所有线程都在忙碌时，没有作用
	pthread_cond_signal(&(pool->notfull_cond));//发送执行消息--任务
	return true;
}
//线程函数---取任务（ｐｏｒｃｅｓｓ，ａｒｇ）
static void* thread_routine(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&(pool->mutex));
		while(pool->cur_queue_size==0 && !pool->shutdown)//阻塞等待信号到达，条件改变(任务达到，销毁)
		{
			pthread_cond_wait(&(pool->notfull_cond),&(pool->mutex));
		}
		printf("starting thread 0x%lx\n",pthread_self());
		if(pool->shutdown)//销毁线程
		{
			pthread_mutex_unlock(&(pool->mutex));//unlock mutex
			printf("thread 0x%lx will exit\n",pthread_self());
			pthread_exit(NULL);//exit self thread
		}
		//使用高度助手
		assert(pool->cur_queue_size!=0);
		//task comming
		CNode_task node;
		pop(&node,&(pool->queue));
		pool->cur_queue_size--;
		
		pthread_cond_signal(&(pool->full_cond));
		//unlock mutex
		pthread_mutex_unlock(&(pool->mutex));

		
		//通过此线程转向去执行此任务队中的指定函数
		node.process(node.arg);
		printf("任务完成\n");
	}
	return NULL;
}
//销毁
bool pool_destroy()
{
	if(pool->shutdown)
	{
		return false;
	}		
	//set shutdown=true
	pool->shutdown =true;
	//signal broadcast
	pthread_cond_broadcast(&(pool->notfull_cond));
	//释放结束子线程，否则僵尸线程
	int i=0;
	for(i=0;i<pool->max_thread_num;i++)
		pthread_join(pool->tid[i],NULL);
	//释放
	free(pool->tid);
	pool->tid=NULL;//恢复为0
	//销毁任务队列
	clearQueue(&(pool->queue));
	//不能忘记销毁锁
	pthread_mutex_destroy(&(pool->mutex));
	pthread_cond_destroy(&(pool->notfull_cond));
	free(pool);
	pool=NULL;
	return true;
}















