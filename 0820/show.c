#include"sys.h"

sem_t sem;
pthread_mutex_t mutex,mutex1;
void* threadfun(void* arg)
{
	int num=(int)arg;
	pthread_mutex_unlock(&mutex1);
	sem_wait(&sem);
	printf("第%d个线程\n",num);
	sem_post(&sem);
}

void main()
{	
	sem_init(&sem,0,5);
	pthread_mutex_init(&mutex1,NULL);
	pthread_t tid[5];
	int i=0;
	for(i=0;i<5;i++)
	{
		pthread_mutex_lock(&mutex1);
		pthread_create(tid+i,NULL,threadfun,(void*)i);
			
	}
	int j=0;
	for(j=0;j<5;j++)
	{
		pthread_join(tid[j],NULL);
	}
	pthread_mutex_destroy(&mutex1);
	sem_destroy(&sem);
}

