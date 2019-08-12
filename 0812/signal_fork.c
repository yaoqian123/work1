#include"sys.h"

void sigfun(int sig)
{
	if(SIGCHLD==sig)
	{
		printf("子进程退出了!\n");
	}
}

void main()
{
	//注册信号
	signal(SIGCHLD,sigfun);
	int pid=fork();
	if(pid>0)
	{
		wait(NULL);
	}
	else if(pid==0)
	{
		printf("%d\n",getpid());
		exit(0);
	}
	else
	{
		perror("error!\n");
	}
}
