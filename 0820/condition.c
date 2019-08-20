#include"sys.h"

pthread_cond_t cond=PTHREAD_COND_INITIALIZER;		//条件变量
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;	//锁
char buf[100]="";
//读者
void* threadfun(void* arg)
{
	while(1)
	{
	pthread_mutex_lock(&mutex);
	while(strlen(buf)==0)
	{
		pthread_cond_wait(&cond,&mutex);	//等待信号
	}
	printf("读%s\n",buf);
	sleep(2);
	buf[0]='\0';
	pthread_mutex_unlock(&mutex);	//解锁
	}
	return NULL;
}
//写者
void* writer(void* arg)
{
	while(1)
	{
	pthread_mutex_lock(&mutex);
	strcpy(buf,"hello world!\n");
	sleep(1);
	pthread_mutex_unlock(&mutex);
	pthread_cond_signal(&cond);
		sleep(1);
	}
}
void main()
{
	pthread_t tidr,tidw;
	pthread_create(&tidr,NULL,threadfun,NULL);
	pthread_create(&tidw,NULL,writer,NULL);
	pthread_join(tidr,NULL);
	pthread_join(tidw,NULL);
}
