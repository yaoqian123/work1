#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<pthread.h>
#include"sys.h"
struct fileMsg
{
	char* path;
	int nfd;
};

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
void* threadfun(void* arg)
{
	struct fileMsg* pfm = (struct fileMsg*)arg;
	int nfd=-1;
	pthread_detach(pthread_self());
	nfd = pfm -> nfd;
	//unlock
	pthread_mutex_unlock(&mutex);
        char buf[100];
	char buf1[20];
	strcpy(buf1,pfm->path);
	int fd=open(buf1,O_RDONLY);
        int len;
	send(nfd,buf1,strlen(buf1),0);
	printf("收到信号,开始发送\n");
        while((len=read(fd,buf,100))>0)
        {
		send(nfd,buf,len,0);	
        }
	close(fd);
	close(nfd);
	printf("发送完成\n");
}

void main(int argc,char* argv[])
{
	struct fileMsg fm={argv[1],-1};
	struct stat st;
	if(argc!=2 && stat(argv[1],&st))
	{
		perror("参数有误!\n");
		return;
	}
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
		fm.nfd=nfd;
		//创建线程--专门用于此客户端通信
		if(pthread_create(&pid,NULL,threadfun,&fm)<0)
		{
			pthread_mutex_unlock(&mutex);
			continue;
		}
	}
	//4:等待收发消息
	//5:关闭
	close(fd);
}
