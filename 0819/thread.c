#include"sys.h"
#include<pthread.h>

//线程路径
void* threadfun(void* arg)
{
	//分离
	pthread_detach(pthread_self());
	int num=(int)arg;
	printf("第%d个线程\n",num);
}

void main()
{
	pthread_t tid[5];
	//创建线程
	int i=0;
	for(i=0;i<5;i++)
	{
		pthread_create(tid+i,NULL,threadfun,(void*)i);
			
	}
	//等待子线程结束
	int j=0;
	for(j=0;j<5;j++)
	{
		pthread_join(tid[j],NULL);
	}
}

