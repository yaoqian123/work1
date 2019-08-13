#include"sys.h"

void main()
{
	int fd[2];
	pipe(fd);
	int pid=fork();
	if(pid>0)
	{
		wait(NULL);
		close(fd[1]);
		dup2(fd[0],0);			//读
		execlp("wc","wc","-w",NULL);
	}
	else if(pid==0)
	{
		close(fd[0]);
		dup2(fd[1],1);			//写
		execlp("ls","ls","/",NULL);
	}
	else
	{
		perror("fail!\n");
		return;
	}
}
