#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<pthread.h>
#include<sys/time.h>

void main()
{
	int fd=socket(AF_INET,SOCK_DGRAM,0);
	if(fd<0)
	{
		perror("socket fail");
		return;
	}
	//允许地址复用
	int opt=1;
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,(const void*)&opt,sizeof(opt));
	//绑定
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
	//收发信息
	int ret;
	struct sockaddr_in caddr;
	socklen_t ilen=sizeof(caddr);
	char buf[100]="";
	fd_set rset;		//读
	while(1)
	{
		//添加想监管的文件描述符
		//清空
		FD_ZERO(&rset);
		//添加
		FD_SET(0,&rset);
		FD_SET(fd,&rset);
		ret=select(fd+1,&rset,NULL,NULL,NULL);	//死等
		if(ret>0)
		{
			if(FD_ISSET(0,&rset)==1)	//是键盘发生了改变
			{
				read(0,buf,100);	
				printf("屏幕内容:%s\n",buf);
			}
			if(FD_ISSET(fd,&rset))
			{
				recvfrom(fd,buf,100,0,(struct sockaddr*)&caddr,&ilen);
				sendto(fd,"copy",4,0,(struct sockaddr*)&caddr,sizeof(caddr));
				printf("网络有内容来了:%s\n",buf);
			}
		}
		else if(ret<0)
		{
			perror("select fail");
		}
	}
}
