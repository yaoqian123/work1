#include"sys.h"

void twocopy()
{
	int fd=open("./a.txt",O_RDONLY,0644);
	int fd1=open("./c.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
	int ilen=lseek(fd,0,SEEK_END);
	int lenth=ilen/2;
	char buf[1024]="";
	lseek(fd,0,SEEK_SET);
	int pid=fork();
	if(pid>0)
	{
		int i=0;
		while(i<=lenth && (ilen=read(fd,buf,1024))>0)
		{
			write(fd1,buf,ilen);
			i+=ilen;
		}
		wait(NULL);
	}
	else if(pid==0)
	{
		close(fd);
		close(fd1);
		fd=open("./a.txt",O_RDONLY,0644);
		fd1=open("./c.txt",O_WRONLY,0644);
		lseek(fd,lenth,0);
		lseek(fd1,lenth,0);
		while((ilen=read(fd,buf,1024))>0)
		{
			write(fd1,buf,ilen);
		}
	}
	else
		return;
	close(fd);
	close(fd1);
}
void main()
{
	twocopy();
}
