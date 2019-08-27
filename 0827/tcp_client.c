#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include"../msg.h"
void main()
{
	//1 socket
	int fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd<0)
	{
		perror("socket fail");
		return;
	}
	int opt=-1;
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
	//2 bind
	struct sockaddr_in myaddr;
	bzero(&myaddr,sizeof(myaddr));
	myaddr.sin_family	=AF_INET;
	myaddr.sin_port		=htons(7980);
	myaddr.sin_addr.s_addr	=INADDR_ANY;
	if(bind(fd,(struct sockaddr*)&myaddr,sizeof(myaddr))<0)
	{
		perror("bind fail");
		return ;
	}
	//3发起连接请求
	struct sockaddr_in saddr;
	bzero(&saddr,sizeof(saddr));
	saddr.sin_family	=AF_INET;
	saddr.sin_port		=htons(7979);//端口
	saddr.sin_addr.s_addr	=INADDR_ANY;//inet_addr("192.168.7.114");//发送方的地址
	
	if(connect(fd,(struct sockaddr*)&saddr,sizeof(saddr))<0)
	{
		perror("connect fail");
		return;
	}
while(1)
{
	//4发送
	int flag=0;
	char path[255]="";
	printf("请选择操作:\n");
	printf("1:查看\n");
	printf("2:下载\n");
	scanf("%d",&flag);
	printf("请输入路径\n");
	scanf("%s",path);
	request rq={flag,"/"};
	strcpy(rq.path,path);
	send(fd,&rq,sizeof(rq),0);
	//先接收状态
	repost rp={0,0};
	mystat fs;
	int total=sizeof(rp);
	int ilen;
	while(total>0&&(ilen=recv(fd,&rp,total,0))>0)
		total-=ilen;
	if(ilen<=0)
	{
		perror("recv fail");
	}
	else
	{
		if(flag=1)
		{	
			if(rp.type==100)
			{
			//数据个数
				int i=0;
				for(i=0;i<rp.length;i++)
				{
					total=sizeof(fs);
					while(total>0 && ((ilen=recv(fd,&fs,total,0))>0))
					{
						printf("%s\n",fs.name);
					}
						
		
				}
			}
			else
			{
				printf("fail:%d\n",rp.type);
			}
		}
		else if(flag=2)
		{
			if(rp.type==200)
			{
				int total=4;
				int len=0,i=0;
				char *buf1[20]={NULL};
				char name[20]="";
				while(ilen >0 && (len=recv(fd,buf1,len,0))>0)
				{
					len-=ilen;
				}
				while((buf1[++i]=strtok(NULL,"/"))!=NULL)
				{
					strcpy(name,buf1[i]);
				}
				int nfd=open(name,O_WRONLY|O_CREAT|O_TRUNC,0664);
				char buf[100]="";
				//接受数据
				while((ilen=recv(fd,buf,100,0))>0)
				{
					write(nfd,buf,ilen);
				}
			}
			else	
			{
				printf("fail:%d\n",rp.type);		
			}			
		}
	}
	
}
	//5关闭
	close(fd);
}	





