#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

#define MAXSIZE 4
typedef int elem;
typedef struct Duilie
{
	elem buf[MAXSIZE];
	short out;		//队头
	short in;		//对尾
}duilie,*pduilie;
//初始化队列
void InitDuilie(pduilie pd)
{
	assert(pd!=NULL);
	pd->out=pd->in=0;
}
//空队列
bool isempty(pduilie pd)
{
	assert(pd!=NULL);
	if((pd->in)%MAXSIZE==(pd->out)%MAXSIZE)
		return true;
	return false;
}
//满队列
bool isfull(pduilie pd)
{
	assert(pd!=NULL);
	if((pd->in+1)%MAXSIZE==(pd->out)%MAXSIZE)
		return true;
	return false;
}
//队列中元素个数
unsigned short duilielength(pduilie pd)
{
	assert(pd!=NULL);
	return (pd->in-pd->out+MAXSIZE)%MAXSIZE;
}
//进队列
bool push(pduilie pd,elem data)
{
	assert(pd!=NULL);
	if(isfull(pd))
		return false;
	pd->buf[(pd->in)]=data;			//进队
	pd->in=(pd->in+1)%MAXSIZE;		
	return true;
}
//出队列
bool pop(pduilie pd,elem* data)
{
	assert(pd!=NULL);
	if(isempty(pd))
		return false;
	*data=pd->buf[(pd->out)%MAXSIZE];	//出队
	pd->out=(pd->out+1)%MAXSIZE;
	return true;
}

void choice(pduilie pd,int* flag)
{
	printf("\n");	
	printf("请选择操作:\n");
	printf("0:退出\n");
	printf("1:进入队列\n");
	printf("2:出队列\n");
	printf("3:查看队列中还有多少元素\n");
	int opr,data;
	scanf("%d",&opr);
//	push(pd,1);
//	printf("成功\n");
	switch(opr)
	{
		case 0:{
				*flag=0;
		       }
		       break;
		case 1:{
			       if(isfull(pd))
				       printf("队列已满!\n");
			       else
			       {
				        scanf("%d",&data);
			      		push(pd,data);
			       		printf("进队列成功!\n");
			       }
		       }
		       break;
		case 2:{
			       if(isempty(pd))
			       		printf("队列已空!\n");
			       else
			       {
			       		pop(pd,&data);
			       		printf("出队列成功!\n");
					printf("%d\n",data);
			       }
		       }
		       break;
		case 3:{
			       printf("队列中元素个数为:%d\n",duilielength(pd));
		       }
		       break;
		default:
		       printf("输入了错误的指令!\n");
		       break;
	}
}
void main()
{
	duilie d={0};
	pduilie pd=&d;	
	InitDuilie(pd);
	int flag=1;
	while(flag==1)
	{
		choice(pd,&flag);
	}
}
