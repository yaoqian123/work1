#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int elem;
typedef struct Link
{
	elem data;
	struct Link* next;
}link,*plink;
plink creat()
{
	plink head=NULL;
	return head;
}

bool add(elem data,plink* phead)
{
	plink pnew=(plink)malloc(sizeof(link));
	if(pnew==NULL)
	{
		printf("无可用空间!\n");
		return false;
	}
	pnew->data=data;
	pnew->next=*phead;
	*phead=pnew;
	return true;
}

void show(plink ploc)
{
	while(ploc!=NULL)
	{
		printf("%d\n",ploc->data);
		ploc=ploc->next;
	}
}
void swap(int* a,int* b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
->next}

void xuanze(plink pHead)
{
	if (pHead==NULL)
		return;
	plink pHead1,pHead2,pHead3;
	for (pHead1=pHead;pHead1->next!=NULL;pHead1=pHead1->next)
	{
		pHead3=pHead1;
		for(pHead2=pHead1->next;pHead2->next!=NULL;pHead2=pHead2->next)
		{
			if (pHead2->next->data<pHead3->data)
			{
				pHead3=pHead2->next;
			}
		}
		if(pHead3!=pHead1)
		{
			swap(&(pHead3->data),&(pHead1->data));
		}
	}
}

void main()
{
	plink head=creat();
	int len;
	printf("输入长度:");
	scanf("%d",&len);
	for(int i=0;i<len;i++)
	add(i,&head);
	show(head);
	xuanze(head);
	show(head);
}
