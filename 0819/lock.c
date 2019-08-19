#include"sys.h"

//WC:临界资源
//线程==2
//竞争
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
void threadfun(void* arg)
{
	int num=(int)arg;
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

	pthread_mutex_init(&mutex,NULL);
	pthread_t tid[2];
	int i=0;
	for(i=0;i<2;i++)
	{
		pthread_create(tid+i,NULL,threadfun,(void*)i);
	}
	for(i=0;i<2;i++)
	{
		pthread_join(tid[i],NULL);
	}
}
