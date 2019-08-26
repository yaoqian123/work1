#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
#include"sys.h"
void main()
{
       	//1:创建套接字
       	int fd=socket(AF_INET,SOCK_STREAM,0);
       	if(fd<0)
        {
      	         perror("socket fail");
       	         return;
        }
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
	//3:发起连接请求
	struct sockaddr_in saddr;
	bzero(&saddr,sizeof(saddr));
        saddr.sin_family       =AF_INET;
        saddr.sin_port         =htons(8080);
        saddr.sin_addr.s_addr  =INADDR_ANY;//inet_addr("192.168.7.114");	//发送方的地址
	if(connect(fd,(struct sockaddr*)&saddr,sizeof(saddr))<0)
	{
		perror("connect fail");
		return;
	}
	int ilen=0,total=4;
	int length=0;
	char name[20]="";
	//先接收长度
	while(total!=0 && (ilen=recv(fd,&length,4,0))>0)
	{
		total-=ilen;
	}
	printf("%d\n",length);
	while(length!=0 && (ilen=recv(fd,name,length,0))>0)
	{
		length-=ilen;
	}
	printf("%s\n",name);
	int fd1=open("a.txt",O_WRONLY|O_CREAT|O_TRUNC,0664);
	char buf[100]="";
	//接受数据
	while((ilen=recv(fd,buf,100,0))>0)
	{
		write(fd1,buf,ilen);
	}https://github.com/yaoqian123/work1
	//4:关闭
	close(fd);
	close(fd1);
}

