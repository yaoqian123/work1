#include<iostream>
#include<sys/types.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<errno.h>
#include<stdio.h>
#include<unistd.h>
using namespace std;

int main()
{
	int sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
	{
		perror("sock fail");
		return -1;
	}
	int opt=1;
	setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,(const void*)&opt,sizeof(opt));
	struct sockaddr_in myaddr;
	myaddr.sin_family		=AF_INET;
	myaddr.sin_port			=htons(8080);
	myaddr.sin_addr.s_addr		=INADDR_ANY;
	if(bind(sock,(struct sockaddr*)&myaddr,sizeof(myaddr))<0)
	{
		perror("bind fail");
		return -1;
	}
	if(listen(sock,10)<0)
	{
		perror("listen fail");
		return -1;
	}
	while(1)
	{
		int newsock=accept(sock,NULL,NULL);
		if(newsock<0)
			break;
		char buf[10240]="";
		recv(newsock,buf,10239,0);
		cout<<buf<<endl;
	}
		close(sock);
}
