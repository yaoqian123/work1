#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int elem;
typedef struct Node
{
	elem data;		
	struct Node* next;	
}node,*pnode;

bool add(elem data,pnode* phead)
{
	//申请节点空间
	pnode pnew=(pnode)malloc(sizeof(node));
	if(pnew==NULL)
	{
		printf("申请失败!");
		return false;
	}
	pnew->data=data;
		pnew->next=NULL;
		*phead=pnew;
	}
	else
	{
		pnew->next=*phead;
		*phead=pnew;
	}
	pnew->next=*phead;
	*phead=pnew;
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
elem* find(int key,pnode ploc)
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

bool change(elem key,elem data,pnode ploc)
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

bool delete(elem key,pnode *phead)
{
	int i;
	pnode ptemp;		//临时指针
	pnode ppre;		//要删除的节点的头节点
	ptemp=*phead;
	ppre=ptemp;
	while(ptemp!=NULL)
	{
		if(key==ptemp->data)
			break;
		ppre=ptemp;
		ptemp=ptemp->next;
	}
	if(ptemp==*phead)
	{
		*phead=ptemp->next;
		free(ptemp);
	}
	else
	{
		ppre->next=ptemp->next;	//链接删除前后节点
		free(ptemp);		//释放删除节点
	}
}

void main()
{
	pnode head=NULL;		//头节点
	add(1,&head);
	add(2,&head);
	add(3,&head);
	add(4,&head);
	add(5,&head);
	elem key;
	scanf("%d",&key);
	delete(key,&head);
		show(head);
}
