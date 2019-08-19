#include"sys.h"

void handle(int sig)
{
	if(sig==SIGUSR1)
		return;
}
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
		while(1)
		{
			printf("please input:");
			scanf("%s",addr);
			//向子进程发送信号
			kill(pid,SIGUSR1);
		}
		shmdt(addr);
		wait(NULL);
	}
	//子进程读取消息
	else if(pid==0)
	{
		signal(SIGUSR1,handle);
		//屏蔽信号集
		sigset_t sig;
		sigfillset(&sig);
		sigdelset(&sig,SIGUSR1);
		sigprocmask(SIG_BLOCK,&sig,NULL);
		//映射
		char* addr=(char*)shmat(sid,NULL,SHM_EXEC);
		while(1)
		{
			pause();		//等待信号到来
			printf("子进程收到:%s\n",addr);
		}
		shmdt(addr);
	}
	else
	{
		perror("fork fail!");
	}
}
