#include"sys.h"

typedef int elem;
typedef struct Node
{
	elem data;
	struct Node* next;	
}node,*pnode;
//头插
bool add(pnode* phead,elem data)
{
	pnode pnew;
	pnew=malloc(sizeof(node));
	if(pnew==NULL)
	{
		printf("fail!");
		return false;
	}
	pnew->data=data;
	pnew->next=*phead;
	*phead=pnew;
	return true;
}
//尾插
bool add1(pnode* phead,elem data)
{
	pnode pnew;
	pnew=malloc(sizeof(node));
	if(pnew==NULL)
	{
		printf("fail!");
		return false;
	}
	pnew->data=data;
	pnew->next=NULL;
	if(*phead==NULL)
	{
		*phead=pnew;
	}
	else
	{
		pnode prear=*phead;
		while(prear->next!=NULL)
			prear=prear->next;
		prear->next=pnew;
	}
	return true;
}
//删除一个
bool delete(pnode* phead,elem data)
{
	pnode pfast=*phead;
	pnode pslow=NULL;
	while(pfast!=NULL&&(pfast->data!=data))
	{
		pslow=pfast;
		pfast=pfast->next;
	}
	if(pfast==NULL)
		return false;
	if(pfast==*phead)
	{
		*phead=pfast->next;
	}
	else
	{
		pslow->next=pfast->next;
	}
	free(pfast);
	return true;
}

void show(pnode ploc)
{
	while(ploc!=NULL)
	{
		printf("%d ",ploc->data);
		ploc=ploc->next;
	}
}
void main()
{
	pnode phead=NULL;
	add(&phead,1);
	add(&phead,2);
	add(&phead,3);
	add(&phead,4);
	show(phead);
	printf("\n");
	delete(&phead,1);
	delete(&phead,3);
	delete(&phead,4);
	show(phead);
	printf("\n");
	add1(&phead,1);
	add1(&phead,1);
	add1(&phead,2);
	add1(&phead,3);
	add1(&phead,4);
	add1(&phead,2);
	add1(&phead,3);
	add1(&phead,4);
	show(phead);
	printf("\n");
}
