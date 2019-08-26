#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef int elem;
typedef struct Node
{
	elem data;
       	struct Node* next;	
}node,*pnode;
bool add1(elem data,pnode* phead)
{
	pnode pnew=malloc(sizeof(node));
	if(pnew==NULL)
	{
		perror("创建失败!");
		return false;
	}
	pnew->data=data;
	pnew->next=*phead;
	*phead=pnew;
	return true;
}
bool add2(elem data,pnode* phead)
{
	pnode pnew=malloc(sizeof(node));
	if(pnew==NULL)
	{
		perror("创建失败!");
		return false;
	}
	pnew->data=data;
	pnew->next=NULL;
	if(*phead==NULL)
		*phead=pnew;
	else
	{
		pnode prear=*phead;
		while(prear->next!=NULL)
			prear=prear->next;
		prear->next=pnew;
	}
}
bool delete(elem data,pnode* phead)
{
	pnode pf=*phead;
	pnode ps=pf;
	while(pf!=NULL&&pf->data!=data)
	{
		ps=pf;
		pf=pf->next;
	}
	if(pf==NULL)
		return false;
	if(pf==*phead)
		*phead=pf->next;
	else
	{
		ps->next=pf->next;
	}
		free(pf);
		return true;
}
void show(pnode ploc)
{
	while(ploc!=NULL)
	{
		printf("%d\n",ploc->data);
		ploc=ploc->next;
	}
}
void main()
{
	pnode head=NULL;
	add1(1,&head);
	add2(2,&head);
	add1(3,&head);
	add2(4,&head);
	show(head);
//	delete(3,&head);
//	delete(4,&head);
	delete(1,&head);
//	delete(5,&head);
	show(head);
}
