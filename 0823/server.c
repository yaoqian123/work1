#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>

void main()
{
	int fd=socket(AF_INET,SOCK_DGRAM,0);
	if(fd<0)
	{
		perror("socket fail");
		return;
	}
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,NULL,0);
	struct sockaddr_in addr;
	bzero(&addr,sizeof(addr));
	addr.sin_family		=AF_INET;
	addr.sin_addr.s_addr	=INADDR_ANY;//inet_addr("192.168.7.129");
	addr.sin_port		=htons(7979);
	if(bind(fd,(struct sockaddr*)&addr,sizeof(addr))<0)
	{
		perror("bind fail");
		return;
	}
	char buf[100]="";
	struct sockaddr_in caddr;
	int ilen;
	socklen_t addrlen=sizeof(struct sockaddr_in);
	while((ilen=recvfrom(fd,buf,99,0,(struct sockaddr*)&caddr,&addrlen))>0)
	{
		buf[ilen]='\0';	
		printf("[%s/%d]:%s\n",inet_ntoa(caddr.sin_addr),caddr.sin_port,buf);
		sendto(fd,"copy",4,0,(struct sockaddr*)&caddr,sizeof(caddr));
	}
	close(fd);
}
