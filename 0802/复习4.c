#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef int elem;
#define MAXSIZE	3
typedef struct Stack
{
	elem buf[MAXSIZE];
	int top;
}stack,*pstack;

void initstack(pstack ps)
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
unsigned short length(pstack ps)
{
	return ps->top+1;
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
	stack s={0};
	pstack ps=&s;
	initstack(ps);
	elem data;
	if(push(ps,1))
		printf("success!\n");
	if(push(ps,2))
		printf("success!\n");
	if(push(ps,3))
		printf("success!\n");
	if(push(ps,4))
		printf("success!\n");
	if(pop(ps,&data))
		printf("%d\n",data);
	if(pop(ps,&data))
		printf("%d\n",data);
	if(pop(ps,&data))
		printf("%d\n",data);
	if(pop(ps,&data))
		printf("%d\n",data);
}
