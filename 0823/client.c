#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<pthread.h>

void* threadfun(void* arg)
{
	pthread_detach(pthread_self());
	int fd=*(int*)arg;
	int lien;
	char buf[100]="";
	while(recv(fd,buf,99,0)>0)
        {
                printf("收到%s\n",buf);
                bzero(buf,sizeof(buf));
        }
}

void main()
{
	int fd=socket(AF_INET,SOCK_DGRAM,0);
//	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,NULL,0);
	
	struct sockaddr_in myaddr;
	bzero(&myaddr,sizeof(myaddr));
	myaddr.sin_family	=AF_INET;
	myaddr.sin_port		=htons(7980);
	myaddr.sin_addr.s_addr	=INADDR_ANY;
	bind(fd,(struct sockaddr*)&myaddr,sizeof(myaddr));

	struct sockaddr_in saddr;
	bzero(&saddr,sizeof(saddr));
	saddr.sin_family	=AF_INET;
	saddr.sin_port		=htons(7979);
	saddr.sin_addr.s_addr	=inet_addr("192.168.7.114");
	
	pthread_t tid;
	pthread_create(&tid,NULL,threadfun,&fd);

	while(1)
	{
		char buf[100]="";
		printf("请输入:");
		scanf("%s",buf);
		sendto(fd,buf,strlen(buf),0,(struct sockaddr*)&saddr,sizeof(saddr));
	}
}
