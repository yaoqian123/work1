#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct Node
{
	int data;				//数据域
	struct Node* next;
}node,*pnode;
bool add(int data,pnode* phead)
{
	pnode pnew=malloc(sizeof(node));
	if(NULL==pnew)
		return false;
	pnew->data=data;
	if(NULL==*phead)
	{
		*phead=pnew;
		pnew->next=*phead;
	}
	else
	{
		pnode prear=*phead;
		while(prear->next!=*phead)
			prear=prear->next;
		prear->next=pnew;		//尾指向头
		pnew->next=*phead;
		*phead=pnew;
	}
	return true;
}
void show(pnode head)
{
	pnode ploc=head;
	while(ploc->next!=head&&ploc->next!=NULL)	//判断当前节点是否为尾节点
	{
		printf("%d\n",ploc->data);
		ploc=ploc->next;
	}
/*	pnode prear=head;
	while(prear->next!=head)
		prear=prear->next;*/
	printf("%d\n",prear->data);
}
//插入某个节点之后
bool insert(int key,pnode head,int data)
{
	pnode ploc=head;
	if(head==NULL)
		return false;
	//查找节点
	while(ploc->data!=key &&ploc-next!=head)
		ploc=ploc->next;
	//判断:查找成功
	if(ploc->data==key)
	{
		pnode pnew=(pnode)malloc(sizeof(node));
		pnew->data=data;
		pnew->next=ploc->next;
		ploc->next=pnew;
	}
}
bool delete(pnode* phead,int data)
{
	pnode ploc=*phead;
	while(ploc->data!=data)
	{
		
	}
}

void main()
{
	pnode head=NULL;	//头节点
	add(1,&head);
	add(2,&head);
	show(head);	
}
