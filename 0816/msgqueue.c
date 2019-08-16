//消息队列
#include"sys.h"

struct msgbuf
{
	long mtype;
	char mtext[100];
};
void main()
{
	//1:获取ID
	key_t key=ftok("./",1);
	if(key<0)
	{
		perror("ftok fail!\n");
		return;
	}
	printf("消息队列的key值:%d\n",key);
	int mid=msgget(key,IPC_CREAT|0666);		//此消息链表的ID
	if(mid<0)
	{
		perror("msgget fail!\n");
		return;
	}
	printf("消息队列的ID值:%d\n",mid);
	//消息类型为1000
	struct msgbuf m1={1000,"hello world!"};
	//2:写入消息
	if(msgsnd(mid,&m1,100,IPC_NOWAIT)<0)
	{
		perror("msgsnd fail!\n");
	}
	//消息类型为777
	struct msgbuf m2={777,"MY NAME IS YAOQIAN"};
	if(msgsnd(mid,&m1,100,IPC_NOWAIT)<0)
	{
		perror("msgsnd fail!\n");
	}
	//3:
}

