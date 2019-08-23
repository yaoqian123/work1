#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
void main()
{
        //1:创建套接字
        int fd=socket(AF_INET,SOCK_STREAM,0);
        if(fd<0)
        {
                perror("socket fail");
                return;
        }
	//2:绑定
	struct sockaddr_in myaddr;
        bzero(&myaddr,sizeof(myaddr));
        myaddr.sin_family       =AF_INET;
        myaddr.sin_port         =htons(7980);
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
        saddr.sin_port         =htons(7979);
        saddr.sin_addr.s_addr  =INADDR_ANY;//inet_addr("192.168.7.114");	//发送方的地址
	if(connect(fd,(struct sockaddr*)&saddr,sizeof(saddr))<0)
	{
		perror("connect fail");
		return;
	}
	while(1)
	{
		char buf[100]="";
		scanf("%s",buf);
		send(fd,buf,strlen(buf),0);
	}
	//4:关闭
	close(fd);
}

