#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"Link.h"

pnode creat()
{
	pnode head=NULL;
	return head;
}
bool add(elem data,pnode* phead)
{
	pnode pnew=malloc(sizeof(node));
	if(pnew==NULL)
	{
		perror("fail!");
		return false;
	}
	pnew->data=data;
	pnew->next=*phead;
	*phead=pnew;
	return true;
}
bool add1(elem data,pnode* phead)
{ 
	pnode pnew=malloc(sizeof(node));
	if(pnew==NULL)
	{
		perror("fail!");
		return false;
	}
	pnew->data=data;
	pnew->next=NULL;
	if(*phead==NULL)
		*phead=pnew;
	else
	{
		pnode prear=*phead;
		while(prear->next==NULL)
			prear=prear->next;
		prear->next=pnew;
	}
	return true;
}
bool delete(elem data,pnode* phead)
{
	pnode pf=*phead;
	pnode ps=NULL;
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
		ps->next=pf->next;
	free(pf);
	return true;
}
bool change(elem key,elem data,pnode phead)
{
	pnode ploc=phead;
	while(ploc!=NULL&&ploc->data!=key)
		ploc=ploc->next;
	if(ploc==NULL)
		return false;
	ploc->data=data;
	return true;
}
void show(pnode head)
{
	pnode ploc=head;
	while(ploc!=NULL)
	{
		printf("%d\n",ploc->data);
		ploc=ploc->next;
	}
}
elem* find(elem key,pnode ploc)
{
	while(ploc!=NULL)
	{
		if(key==ploc->data)
			return &(ploc->data);
		ploc=ploc->next;
	}
}


