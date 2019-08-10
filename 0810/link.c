#include"sys.h"

typedef int elem;

typedef struct Node
{
	elem data;
	struct Node* next;
}node,*pnode;

//头插
void add(pnode* phead,elem data)
{
	pnode pnew=malloc(sizeof(node));
	if(pnew==NULL)
	{
		perror("fail\n");
		return;
	}
	pnew->data=data;
	pnew->next=*phead;
	*phead=pnew;
}

//尾插
void add1(pnode* phead,elem data)
{
	pnode pnew=malloc(sizeof(node));
	if(pnew==NULL)
	{
		perror("fail\n");
		return;
	}
	pnew->data=data;
	pnew->next=NULL;
	if(*phead==NULL)
	{
		*phead=pnew;
	}
}

void main()
{
	
}
