#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<pthread.h>
#include"sys.h"

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
void* threadfun(void* arg)
{
	pthread_detach(pthread_self());
	int nfd=*(int*)arg;
	//unlock
	pthread_mutex_unlock(&mutex);
	char buf1[100]="a.txt";
	int fd1=open(buf1,O_RDONLY,0664);
        if(fd1<0)
        {
                perror("open fail!\n");
                return NULL;
        }
        char buf[100]="";
        int len;
	send(nfd,buf1,strlen(buf1),0);
	printf("收到信号,开始发送\n");
        while((len=read(fd1,buf,100))>0)
        {
		send(nfd,buf,len,0);	
        }
        close(fd1);
	close(nfd);
	printf("发送完成\n");
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
        myaddr.sin_port         =htons(8080);
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
