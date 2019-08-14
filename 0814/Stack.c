#include"sys.h"

#define MAXSIZE 3
typedef int elem;
typedef struct Stack
{
	elem data[MAXSIZE];
	int top;
}stack,*pstack;

bool init(pstack ps)
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
	ps->data[++ps->top]=data;
	return true;
}
bool pop(pstack ps,elem* data)
{
	if(isempty(ps))
		return false;
	*data=ps->data[ps->top--];
	return true;
}
void main()
{
	stack s={0};
	pstack ps=&s;
	elem data;
	init(ps);
	int i;
	for(i=0;i<=MAXSIZE;i++)
	{
		if(push(ps,i))
			printf("%d\nsusses!\n",i);
		else
			printf("fail\n");
	}
	for(i=0;i<=MAXSIZE;i++)
	{
		if(pop(ps,&data))
			printf("%d\nsusses!\n",data);
		else
			printf("fail\n");
	}
}
