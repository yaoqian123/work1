#include"sys.h"

void main()
{
	//通过key("./",0)获取消息队列id
	key_t key=ftok("./",0);
	if(key<0)
	{
		perror("fail!\n");
	}
	int mid=msgget(key,IPC_CREAT|0666);
	if(mid<0)
	{
		if(errno==EEXIST)
		{
			perror("msgget fail!\n");
			return;
		}
	}
	//2:读取	msgtyp	>1000取出type为1000 =0 -1000 -代表<
	char buff[100]="";
	//取第一个
	if(msgrcv(mid,buff,100,0,MSG_NOERROR|IPC_NOWAIT)>0)
	{
		printf("%s\n",buff);
	}
}
