#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdlib.h>

//父进程等待子进程结束
//僵尸进程
/*
void main()
{
	int pid=0;
	int status;
	pid=fork();
	if(pid>0)			//父进程
	{
		printf("我是父进程\n");
		wait(&status);
		printf("%d\n",status);
	}
	else if(pid==0)			//子进程
	{
		sleep(5);
		printf("我是子进程\n");
	}
	else
	{
		perror("fail");
	}

}
*/
//孤儿进程:父进程退出,运行的子进程
/*
void main()
{
	int pid=fork();
	if(pid>0)			//父进程
	{
		printf("我是父进程,pid=%d\n",gitpid());
		sleep(1);
		exit(0);
		printf("父进程退出\n");
	}
	else if(pid==0)			//子进程
	{
		printf("我是子进程,pid=%d,我的父进程pid=%d\n",getpid(),getppid());
		sleep(3);	
		printf("我是子进程,pid=%d,我的父进程pid=%d\n",getpid(),getppid());
	}
	else
	{
		perror("fail");
	}
}
*/
//守护进程
void main()
{
	//1:不受终端影响
	int pid=fork();
	if(pid>0)
	{
		exit(0);
	}
	else if(pid<0)
	{
		perror("fork fail");
		return;
	}
	//2:不受用户影响
	setsid();
	//3:修改文件掩码
	umask(0);
	//4:修改工作路径
	chdir("/");
	//5:关闭文件流
	for(int j=0;j<65535;j++)
		close(j);
	//6:工作任务
	int i;
	for(i=0;i<100;i++)
	{
		printf("%d\n",i);
		sleep(1);
	}
}
