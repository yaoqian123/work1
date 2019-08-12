#include"sys.h"

void sigfun(int sig)
{
	if(SIGKILL==sig)
	{
		printf("中断\n");
	}
}
void main()
{
	//if(signal(SIGKILL,SIG_IGN)==SIG_ERR)
	if(signal(SIGKILL,sigfun)==SIG_ERR)
	{
		perror("signal fail");
	}
	while(1)
	{
		printf("I am working...\n");
		sleep(1);
	}
}
