#include"sys.h"
#include"queue.h"

sem_t car,content;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
//消费者
void* consumer(void* arg)
{
	pqueue q=(pqueue)arg;
	while(1)
	{
		//p car-1
		sem_wait(&car);
		pthread_mutex_lock(&mutex);
		int carid;
		pop(q,&carid);
		//printf("取出来的元素:%d\n",carid);
		sleep(rand()%1);
		printf("tid=%lx,消费的汽车id:%d\n",pthread_self(),carid);
		pthread_mutex_unlock(&mutex);
		//v content +1
		sem_post(&content);
	}
	return NULL;
}
//生产者
void* produce(void* arg)
{
	pqueue q=(pqueue)arg;
	while(1)
	{
		//生产
		int carid=rand()%100000;
		//p content-1
		sem_wait(&content);
		pthread_mutex_lock(&mutex);
		push(q,carid);
		//printf("存进去的元素:%d\n",carid);
		sleep(rand()%3);
		printf("tid=%lx,生产汽车id:%d\n",pthread_self(),carid);
		pthread_mutex_unlock(&mutex);
		//v car+1
		sem_post(&car);
		sleep(1);
	}
	return NULL;
}

int main()
{
	//初始化
	sem_init(&car,0,0);
	sem_init(&content,0,MAXSIZE);
	//汽车队列
	queue q;
	init(&q);
	int i=0;
	//创建线程
	pthread_t c[2],p[4];		//c消费  p生产
	for(i=0;i<2;i++)
	{
		pthread_create(c+i,NULL,consumer,&q);
	}
	for(i=0;i<4;i++)
	{
		pthread_create(p+i,NULL,produce,&q);
	}
	for(i=0;i<2;i++)
	{
		pthread_join(c[i],NULL);
	}
	for(i=0;i<4;i++)
	{
		pthread_join(p[i],NULL);
	}
}
