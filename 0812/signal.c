#include"sys.h"
//用户自处理信号
void sigfun(int sig)
{
	if(sig==SIGINT)
	{
		printf("按下了ctrl+c\n");
		execl("/bin/ls","ls","-l",NULL);
	}
}

void main()
{
	//注册信号
	//系统默认处理
	//signal(SIGINT,SIG_DFL);
	//忽略
	//signal(SIGINT,SIG_IGN);
	signal(SIGINT,sigfun);
	while(1)
	{
		printf("I an working\n");
		sleep(1);
	}
}
