#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

void main()
{
	int fd=open("./a.data",O_RDONLY);
	if(fd<0)
	{
		perror("open fail");
		return;
	}
	char buf[100]="";
	int ilen;
	ilen=read(fd,buf,100);
	printf("ilen=%d %s\n",ilen,buf);
	close(fd);
}
