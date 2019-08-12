#include"sys.h"

void main()
{
	char buf[]="***yaoqian@yaoqian:~/桌面/0810$*** ";
	char cmd[255]="";
	int pid;
	while(1)
	{
		printf("%s",buf);
		gets(cmd);
		pid=fork();
		if(pid>0)
		{
			wait(NULL);
		}
		else if(pid==0)
		{
			char* buf1[5]={NULL};
			int i=0;
			buf1[0]=strtok(cmd," ");
			while((buf1[++i]=strtok(NULL," "))!=NULL)
			{
				execvp(buf1[0],buf1);
			}
		}
		else
		{
			perror("fail\n");
		}
