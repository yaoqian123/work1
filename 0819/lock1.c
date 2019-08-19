#include"sys.h"

//WC:临界资源
//线程==2
//竞争
pthread_mutex_t mutex,mutex1;//=PTHREAD_MUTEX_INITIALIZER;
void threadfun(void* arg)
{
	int num=*(int*)arg;
	pthread_mutex_unlock(&mutex1);
	//上锁
	pthread_mutex_lock(&mutex);
	printf("%d进入洗手间\n",num);
	sleep(2);
	printf("%d退出洗手间\n",num);
	//解锁
	pthread_mutex_unlock(&mutex);
}
void main()
{
	//初始化
	pthread_mutex_init(&mutex,NULL);
	pthread_mutex_init(&mutex1,NULL);
	pthread_t tid[4];
	int i=0,j;
	for(i=0;i<4;i++)
	{
		pthread_mutex_lock(&mutex1);
		pthread_create(tid+i,NULL,threadfun,&i);
	}
	for(j=0;j<4;j++)
	{
		pthread_join(tid[j],NULL);
	}
}
