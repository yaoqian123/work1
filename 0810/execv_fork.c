#include"sys.h"

void main()
{
	printf("进程开始了\n");
	int pid=fork();
	if(pid>0)
	{
		wait(NULL);
	}
	else if(pid==0)
	{
//		execlp("ls","ls","-l",NULL);
		char buf[]="123,456,789";
		char *buf1[]={NULL};
		int i=0;
		buf1[i]=strtok(buf,",");
			printf("%s\n",buf1[i]);
		//execv("/bin/ls",argv);
	}else
	{
		perror("fail\n");
	}
	/*	int i=0,result=0;
		while(i<=100)
		{
			i++;
			result+=i;
		}
		printf("1-100的和:%d\n",result);
	*/	
}
