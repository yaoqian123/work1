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
	long ilen=0;
        char buf[100];
	int fd=open(pfm->path,O_RDONLY);
        int len;
	char buf1[20]="";
	strcpy( buf1 , pfm->path );
	ilen=strlen(buf1);
	//先发送长度
	send(nfd,&ilen,sizeof(ilen),0);
	//再发送数据
	send(nfd,buf1,ilen,0);
        while((len=read(fd,buf,100))>0)
        {
		send(nfd,buf,len,0);	
        }
	close(fd);
	close(nfd);
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
