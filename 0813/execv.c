#include"sys.h"

void main()
{
	int fd[2];
	pipe(fd);
	int pid=fork();
	if(pid>0)
	{
		close(fd[1]);		//关闭写
		wait(NULL);
		char ch;
		read(fd[0],a,)
		close(fd[0]);		//关闭读
	}
	else if(pid==0)
	{
		close(fd[0]);
		execlp("ls","ls","-l");
	}
	else
	{
		perror("fork fail!\n");
	}
}
