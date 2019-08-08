#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void main()
{
	int i=1;
	int pid;
	for(i=1;i<=5;i++)
	{
		pid=fork();
		if(pid==0)				//子进程
		{
			sleep(1);
			break;
		}
	}
	//父子进程
	if(pid==0)
	{
		printf("我是%d号进程\n",i);
	}
}
