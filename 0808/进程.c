#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void main()
{
	int i=100;
	//进程:分配资源
//	printf("本进程的PID号:%d\n",getpid());
//	printf("父进程的PID号:%d\n",getppid());
	printf("程序开始运行,pid=%d\n",getpid());
	int pid=fork();
	if(pid>0)		//父进程
	{
		i=99;
		printf("父进程:生成的进程ID为%d,本进程的PID=%d,i=%d\n",pid,getpid(),i);
		sleep(3);
	}
	else if(pid==0)		//子进程
	{
		sleep(1);
		printf("子进程:我的进程ID为%d,我的父进程的PID=%d,i=%d\n",getpid(),getppid(),i);
	}
	else			//fail
	{
		perror("fork fail");
		return;
	}
}
