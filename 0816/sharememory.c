#include"sys.h"

void main()
{
	//获取ID 通过key
	key_t key=ftok("./",5);
	if(key<0)
	{
		perror("ftok fail!");
		return;
	}
	//申请内存空间
	int sid=shmget(key,100,IPC_CREAT|0777);
	if(sid<0)
	{
		perror("shfmget fail");
		return;
	}
	int pid=fork();
	//父进程写入消息
	if(pid>0)
	{
		//映射
		char* addr=(char*)shmat(sid,NULL,SHM_EXEC);
		strcpy(addr,"hello");
		wait(NULL);
	}
	//子进程读取消息
	else if(pid==0)
	{
		sleep(1);	//控制同步
		//映射
		char* addr=(char*)shmat(sid,NULL,SHM_EXEC);
		printf("%s\n",addr);
	}
	else
	{
		perror("fork fail!");
	}
}
