#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>
//单进程拷贝
	float s,f,t;
void onecopy()
{
	int fd1=open("fork.c",O_RDONLY,0664);
	if(fd1<0)
	{
		printf("open fail\n");
	}
	int fd2=open("fork1.c",O_WRONLY|O_CREAT,0664);
	char buf[1024];
	int ilen;
	s=clock();
	while((ilen=read(fd1,buf,1024))>0)
	{
		//lseek(fd2,1,SEEK_SET);
		write(fd2,buf,ilen);
	}
	f=clock();
	t=(f-s)/CLOCKS_PER_SEC;
	printf("单进程拷贝时间:%f\n",t);
}
//双进程拷贝
void twocopy()
{
/*	int fd1=open("fork.c",O_RDONLY,0664);
	if(fd1<0)
	{
		perror("open fail\n");
	}
	int fd2=open("fork2.c",O_CREAT|O_WRONLY,0664);
	char buf[1]="";
	struct stat st;
	if(stat("fork.c",&st)<0)
	{
		perror("open fail");
		return;
	}
	long j=0;;
	int pid=fork();
	int add=0;
	printf("%ld\n",st.st_size);
	if(pid>0)
	{
		s=clock();
		while((j<=(st.st_size/2))&&(add=read(fd1,buf,1))>0)
		{
			write(fd2,buf,add);
			j=j+add;
		}
		wait(NULL);
		f=clock();
		t=(f-s)/CLOCKS_PER_SEC;
		printf("双进程拷贝时间:%f\n",t);
	}
	else if(pid==0)
	{	
		lseek(fd2,st.st_size/2,0);
		lseek(fd1,st.st_size/2,0);
		while((add=read(fd1,buf,1))>0)
		{
			write(fd2,buf,add);
		}
	}
	else
	{
		perror("fork fail");
		return;
	}

	close(fd1);
	close(fd2);
	*/

	int fd=open("./fork.c",O_RDONLY,0644);
	int fd1=open("./fork2.c",O_WRONLY|O_CREAT,0644);
	int ilen=lseek(fd,0,SEEK_END);
	int lenth=ilen/2;
	char buf[1024]="";
	lseek(fd,0,SEEK_SET);
	int pid=fork();
	if(pid>0)
	{
		s=clock();
		int i=0;
		while(i<=lenth && (ilen=read(fd,buf,1024))>0)
		{
			write(fd1,buf,ilen);
			i+=ilen;
		}
		wait(NULL);
                f=clock();
                t=(f-s)/CLOCKS_PER_SEC;
                printf("双进程拷贝时间:%f\n",t);
	}
	else if(pid==0)
	{
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
	onecopy();
	twocopy();
}
