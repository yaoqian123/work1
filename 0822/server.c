#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
typedef struct 
{
	int fd;
	struct sockaddr_in addr;
}yq,*pyq;

void* threadfun(void* arg)
{
	pyq PYQ=(pyq)arg;
	PYQ->addr.sin_port	=htons(8080);
	 while(1)
                {
                        char buf[100]="";
     //                   printf("please input:");
                        scanf("%s",buf);
                        sendto(PYQ->fd,buf,strlen(buf),0,(struct sockaddr*)&(PYQ->addr),sizeof(PYQ->addr));
                }
}

void main()
{
	//1:创建套接字 打开设备
	int fd=socket(AF_INET,SOCK_DGRAM,0);
	yq YQ={0};
	YQ.fd=fd;
	//2:绑定套接字:IP/prot端口
	struct sockaddr_in addr;
	bzero(&addr,sizeof(addr));
	addr.sin_family		=AF_INET;	//ipv4
	addr.sin_addr.s_addr	=INADDR_ANY;//inet_addr("192.168.7.114");	//ip
	addr.sin_port		=htons(7979);
	if(bind(fd,(struct sockaddr*)&addr,sizeof(addr))<0)
	{
		perror("bind fail");
		return;
	}
	YQ.addr=addr;
	pthread_t tid;
	pthread_create(&tid,NULL,threadfun,&YQ);
	//3:等待收消息
	char buf[100]="";
	int ilen=0;
	while((ilen=(recv(fd,buf,99,0)))>0)
	{
		printf("%s\n",buf);
		buf[ilen]='\0';
	}
	//4:关闭
	close(fd);
	pthread_join(tid,NULL);
}
