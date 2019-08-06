#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 4
typedef int elem;
typedef struct Stack
{
	elem buf[MAXSIZE];
	int top;
}stack,*pstack;
void init(pstack ps)
{
	ps->top=-1;
}
bool isempty(pstack ps)
{
	if(ps->top==-1)
		return true;
	return false;
}
bool isfull(pstack ps)
{
	if(ps->top==MAXSIZE-1)
		return true;
	return false;
}
bool push(pstack ps,elem data)
{
	if(isfull(ps))
		return false;
	ps->buf[++ps->top]=data;
	return true;
}
bool pop(pstack ps,elem* data)
{
	if(isempty(ps))
		return false;
	*data=ps->buf[ps->top--];
	return true;
}
void main()
{
	int i=0;
	stack s={0};
	pstack ps=&s;
	init(ps);
	elem data;
	for(i=0;i<=MAXSIZE;i++)
	{
		if(push(ps,i))
			printf("susses\n");
		else
			printf("fail\n");
	}
	for(i=0;i<=MAXSIZE;i++)
	{
		if(pop(ps,&data))
		{
			printf("susses%d\n",data);
		}
		else
			printf("fail\n");
	}
}
