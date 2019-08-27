#include<stdio.h>
#include"net.h"
#include<errno.h>
#include<unistd.h>
#include<pthread.h>
#include"threadpool.h"
#include<sys/types.h>
#include<sys/socket.h>
#include"process.h"
static pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
void* threadfun(void*arg)
{
	int newfd=*(int*)arg;
	pthread_mutex_unlock(&mutex1);//unlock
	//接收数据
	recvData(newfd);

	//关闭套接字
	close(newfd);
	return NULL;
}
//主线程等待连接,连接任务(工作线程执行)
void main()
{
	//1初始化网络(创建,绑定,监听)
	int fd=initSock(7979,50);
	if(fd<0)
	{
		perror("initSock fail");
		return;
	}
	//初始化线程池
	pool_init(10);
	//2等待连接
	while(1)
	{
		//加锁
		pthread_mutex_lock(&mutex1);
		int newfd=accept(fd,NULL,NULL);//等待连接
		if(newfd<0 && (errno!=EAGAIN || errno!=EWOULDBLOCK || errno!=EINTR))
		{
			perror("accept fail");
			break;
		}
		//等待接收内容
		pool_add_worker(threadfun,&newfd);	
				
	}
	//销毁线程池
	pool_destroy();
	//3关闭套接字
	close(fd);
}

