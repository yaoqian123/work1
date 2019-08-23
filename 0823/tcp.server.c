#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<pthread.h>

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
void* threadfun(void* arg)
{
	pthread_detach(pthread_self());
	int nfd=*(int*)arg;
	//unlock
	pthread_mutex_unlock(&mutex);
	int ilen;
	char buf[100]="";
	while((ilen=recv(nfd,buf,99,0))>0)
	{
		buf[ilen]='\0';
		printf("recv:%s\n",buf);
	}
	close(nfd);
}

void main()
{
	//1:创建套接字
	int fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd<0)
	{
		perror("socket fail");
		return;
	}
	//允许地址复用
	int opt=1;
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,(const void*)&opt,sizeof(opt));
	//2:绑定
	struct sockaddr_in myaddr;
	bzero(&myaddr,sizeof(myaddr));
	myaddr.sin_family       =AF_INET;
        myaddr.sin_port         =htons(7979);
        myaddr.sin_addr.s_addr  =INADDR_ANY;
        if(bind(fd,(struct sockaddr*)&myaddr,sizeof(myaddr))<0)
	{
		perror("bind fail");
		return;
	}
	//3:监听
	listen(fd,20);
	int nfd;
	pthread_t pid;
	while(1)
	{
		nfd=accept(fd,NULL,NULL);
		if(nfd<0)
			break;
		pthread_mutex_lock(&mutex);
		//创建线程--专门用于此客户端通信
		if(pthread_create(&pid,NULL,threadfun,&nfd)<0)
		{
			pthread_mutex_unlock(&mutex);
			continue;
		}
	}
	//4:等待收发消息
	//5:关闭
	close(fd);
}
