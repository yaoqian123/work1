//ifndef 如果没有POOL宏，则包含
#ifndef __POOL__
#define __POOL__
#define MAXSIZE 100
#include<pthread.h>
#include<stdbool.h>
typedef struct //任务节点
{
	//回调函数
	void* (*process) (void*);
	//参数
	void* arg;
}CNode_task;
typedef struct //队列节点
{
	CNode_task buf[MAXSIZE];
	int rear;//尾
	int front;//头
}CThread_worker;
//线程池
typedef struct worker
{
	//任务队列
	CThread_worker queue;
	//线程组
	pthread_t *tid;
	//是否销毁
	bool shutdown;
	//锁－条件量
	pthread_cond_t notfull_cond;	//不为满:执行任务
	pthread_cond_t full_cond;	//为满:让指定等待
	pthread_mutex_t mutex;
	//线程数量
	int max_thread_num;
	//等待任务的数量
	int cur_queue_size;
}CThread_pool;

extern bool pool_init(int);
extern bool pool_add_worker(void*(*)(void*),void* arg);
extern bool pool_destroy();


#endif
