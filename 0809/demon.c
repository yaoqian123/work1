#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdlib.h>

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
