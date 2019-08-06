#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
void main()
{
	//打开
	int fd=open("./a.data",O_CREAT|O_WRONLY,0664);
	if(fd<0)
	{
		printf("open fail\n");
		return;
	}
	lseek(fd,0,SEEK_END);
	char buf[100]="123456";
	write(fd,buf,strlen(buf));
	printf("%d\n",fd);
	//关闭
	close(fd);
	//write(1,"hello",5);
	/*char buf[100]="";
	read(0,buf,100);
	printf("%s\n",buf);*/
}

