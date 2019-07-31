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
//头插
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
//尾插
bool add2(elem data,plink* phead)
{
	plink pnew=(plink)malloc(sizeof(link));
	if(pnew==NULL)
	{
		printf("无可用空间!\n");
		return false;
	}
	pnew->data=data;
	pnew->next=NULL;
	if(*phead==NULL)
		*phead=pnew;
	else
	{
		//查找尾节点
		plink prear=*phead;
		while(prear->next!=NULL)
			prear=prear->next;
		prear->next=pnew;
	}	
}
void show(plink ploc)
{
	while(ploc!=NULL)
	{
		printf("%d\n",ploc->data);
		ploc=ploc->next;
	}
}
elem* find(int key,plink ploc)
{
	while(ploc!=NULL)
	{
		if(key==ploc->data)
	{
		//	printf("查找成功!\n");
			return &(ploc->data);
		}
		else
			ploc=ploc->next;
	}
	return NULL;
}

bool change(elem key,elem data,plink ploc)
{
	int flag=0;
	while(ploc!=NULL)
	{
		if(data==ploc->data)
		{
			ploc->data=key;
			flag=1;
		}
		ploc=ploc->next;
	}
	if(flag==0)
		return false;
	return true;
}

bool delete(elem key,plink *phead)
{
	int flag=0;	
	plink ptemp=*phead;
	plink ppre=ptemp;
	while(ptemp!=NULL)
	{
		if(key==ptemp->data)
		{
			flag=1;
			break;
		}
		ppre=ptemp;
		ptemp=ptemp->next;
	}
	if(flag==0)
		return false;
	if(ptemp==*phead)
	{
		*phead=ptemp->next;
		free(ptemp);
	}
	else
	{
		ppre->next=ptemp->next;	
		free(ptemp);		
	}
	return true;
}

void main()
{
	plink head=creat();
	add(1,&head);
	add(2,&head);
	add(3,&head);
	add(4,&head);
	add(5,&head);
//	show(head);
	elem key;
	scanf("%d",&key);
/*	if(find(key,head)!=NULL)
	{
		printf("存在!\n");
		printf("%d\n",*find(key,head));
	}
	else{
		printf("不存在!\n");
	}

	if(change(2,1,head))
		show(head);
*/
	if(delete(key,&head))
		show(head);
	else
		printf("要删除的值不存在!\n");
}
