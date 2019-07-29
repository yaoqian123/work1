#include<stdio.h>
#include<assert.h>
#include<stdbool.h>	//#define true 1 #define false 0 typedef char BOOL;
#define MAXSIZE 3
//定义栈
typedef int elemType;
typedef struct Stack
{
	elemType buf[MAXSIZE];
	int top;
}stack,*pstack;		//typedef struct Stack stack;
			//typedef struct Stack* pstack;

//初始化栈
void Initstack(pstack ps)
{
	assert(ps!=NULL);
	ps->top=-1;
}
//空栈 返回1为空 0为非空  true为真  false为假
bool IsEmpty(pstack ps)
{
	assert(ps!=NULL);
	if(ps->top==-1)
		return true;
	return false;
}
//满栈
bool IsFull(pstack ps)
{
	assert(ps!=NULL);
	if(ps->top==MAXSIZE-1)
		return true;
	return false;
}
//栈中元素个数
unsigned short StackLength(pstack ps)
{
	assert(ps!=NULL);
	return ps->top+1;
}
//进栈
bool Push(pstack ps,elemType data)
{
	assert(ps!=NULL);
	if(IsFull(ps))
		return false;
	ps->buf[++ps->top]=data;
	return true;
}
//出栈
bool Pop(pstack ps,elemType* data)
{
	assert(ps!=NULL);
	if(IsEmpty(ps))
		return false;
	ps->buf[ps->top--]=*data;
	return true;
}

void choice(pstack ps,int* flag)
{
	printf("\n");	
	printf("请选择操作:\n");
	printf("0:退出\n");
	printf("1:入栈\n");
	printf("2:出栈\n");
	printf("3:查看栈中还有多少元素\n");
	int opr,data;
	scanf("%d",&opr);
//	Push(&s,1);
//	printf("成功\n");
	switch(opr)
	{
		case 0:{
				*flag=0;
		       }
		       break;
		case 1:{
			       if(IsFull(ps))
				       printf("栈已满!\n");
			       else
			       {
				       scanf("%d",&data);
			      		Push(ps,data);
			       		printf("进栈成功!\n");
			       }
		       }
		       break;
		case 2:{
			       if(IsEmpty(ps))
			       		printf("栈已空!\n");
			       else
			       {
			       		Pop(ps,&data);
			       		printf("出栈成功!\n");
					printf("%d\n",data);
			       }
		       }
		       break;
		case 3:{
			       printf("栈中元素个数为:%d\n",StackLength(ps));
		       }
		       break;
		default:
		       printf("输入了错误的指令!\n");
		       break;
	}
}
void main()
{
//定义变量
	stack s={0};	//struct Stack
	pstack ps=&s;	//struct Stack*
	Initstack(&s);
	int flag=1;
	while(flag==1)
	{
		choice(ps,&flag);
	}
}
