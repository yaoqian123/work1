#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
//初始化网络
//port 端口
int initSock(int port,int ls)
{
	//创建套接字
	int fd=socket(AF_INET,SOCK_STREAM,0);
	do
	{
		if(fd<0)
			break;
	//允许套接字复用
		int opt=1;
		if(setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt))<0)
			break;
		//bind
		struct sockaddr_in myaddr;
		bzero(&myaddr,sizeof(myaddr));
		myaddr.sin_family	=AF_INET;
		myaddr.sin_port		=htons(port);
		myaddr.sin_addr.s_addr	=INADDR_ANY;
		if(bind(fd,(struct sockaddr*)&myaddr,sizeof(myaddr))<0)
			break;
		//监听
		if(listen(fd,ls)<0)
			break;
	}while(fd<0);
	if(fd<0)
	{
		close(fd);
		fd=-1;
	}
	return fd;
}



