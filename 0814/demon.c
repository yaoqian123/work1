#include"sys.h"

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
		perror("fork fail\n");
		return;
	}
	//2:不受用户影响
	setsid();
	//3:修改文件掩码
	umask(0);
/*	//4:修改工作路径
	chdir("/");
	*/
	//5:关闭文件流
	for(int i=0;i<65535;i++)
	{
		close(i);
	}
	//6:工作任务
	int j;

	for(j=0;j<100;j++)
	{
		printf("%d\n",j);
		sleep(1);
	}
}
