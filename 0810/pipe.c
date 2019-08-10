#include"sys.h"

void main()
{
	int fd[2];
	pipe(fd);
	int pid=fork();
	if(pid>0)
	{
		close(fd[0]);
		write(fd[1],"ilove you\n",11);
		close(fd[1]);
		wait(NULL);
	}
	else if(pid == 0)
	{
		//关闭写
		close(fd[1]);
		char ch;
		while(read(fd[0],&ch,1)>0)
			printf("%c",ch);
		close(fd[0]);
	}
	else{
		perror("error\n");
	}
}
