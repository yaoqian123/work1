#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include"threadpool.h"

//print 1-num  slee 1
//看似线程函数，只是线程函数中间接调用本函数
void* myprocess(void* arg)
{
	int num=*(int*)arg;
	while(num--)
	{
		printf("tid=%lx,num=%d\n",pthread_self(),num);
		sleep(1);
	}
}

void main()
{
	//initializer pool
	pool_init(5);
	//add task
	int i=0;
	int num[20];
	for(i=0;i<20;i++)
	{
		num[i]=10;
		pool_add_worker(myprocess,&num[i]);
	}
	//销毁
	sleep(200);
	pool_destroy();
	sleep(10);
}




