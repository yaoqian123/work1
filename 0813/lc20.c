#include"sys.h"

#define MAXSIZE 10

typedef char elem;
typedef struct Stack
{
	elem* buf[MAXSIZE];
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
bool push(pstack ps,elem* data)
{
	if(isfull(ps))
		return false;
	ps->buf[++ps->top]=malloc(sizeof(stack));
	strcpy(ps->buf[ps->top],data);
	return true;
}
bool pop(pstack ps,elem** data)
{
	if(isempty(ps))
		return false;
	strcpy(*data,ps->buf[ps->top--]);
	return true;
}
bool kuohao(pstack ps)
{
	elem* data;
	char* buf[10]={"{","}","[","(","]",")",NULL};
	int i=0;
	while(buf[i]!=NULL)
	{
		if(buf[i]=="{"||buf[i]=="["||buf[i]=="(")
		{
			push(ps,buf[i]);
		}
		else if(buf[i]=="}"||buf[i]=="]")
		{
			pop(ps,&data);
			if(strcmp(data,buf[i])!=2 && strcmp(data,buf[i])!=-2)
			{
				return false;
			}
		}
		else
		{
			pop(ps,&data);
			if(strcmp(data,buf[i])!=1 && strcmp(data,buf[i])!=-1)
			{
				return false;
			}
		}
		i++;
	}
	if(isempty(ps))
		return true;
	return false;
}
void main()
{
	int i=0;
	stack s={NULL};
	pstack ps=&s;
	init(ps);
	if(kuohao(ps))
		printf("合法!\n");
	else
		printf("不合法!\n");
}
