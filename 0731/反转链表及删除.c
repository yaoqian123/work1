#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
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
		printf("%d ",ploc->data);
		ploc=ploc->next;
	}
}
elem* find(int key,plink ploc)
{
	while(ploc!=NULL)
	{
		if(key==ploc->data)
	{
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
//删除
bool delete(elem key,plink* phead)
{
	plink pf=*phead;		//快指针
	plink pl=NULL;			//慢指针
	while(pf==NULL&&pf->data!=key)
	{
		pl=pf;			
		pf=pf->next;
	}
	if(pf==NULL)
		return false;	
	if(pf==*phead)	
		*phead=pf->next;
	pl->next=pf->next;
	free(pf);
	return true;
     
}
//循环解法
plink  fanzhuan(plink *pHead)
{
    if(*pHead==NULL)		
	    return NULL;
    plink pNewHead=NULL;	//新头结点
    plink pPrev=NULL;		
    plink pCur=*pHead;	//当前节点
    while(pCur!=NULL)
    {
 	plink pTmp=pCur->next;	//指向下一节点
        if(pTmp==NULL)
        {
            pNewHead=pCur;		//找到原来的尾换成新头结点
        }
        pCur->next=pPrev;	//后面节点指向前面
        pPrev=pCur;		
        pCur=pTmp;		//指向下一节点
    } 
    *pHead=pNewHead;
    	return *pHead;

}
//递归解法
plink fanzhuan1(plink head)
{   
/*     
*/
	if(!head||!head->next)
        return head;
    plink newhead=fanzhuan1(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}
void main()
{
	plink head=creat();
	plink NewHead=NULL;
	plink pf=NULL;
	plink pl=NULL;
	int len;
	printf("输入长度:");
	scanf("%d",&len);
	for(int i=0;i<len;i++)
	add(rand(),&head);
//	show(head);
	printf("\n");
	float s,f,t;
	s=clock();
	fanzhuan(&head);
	f=clock();
	t=(f-s)/CLOCKS_PER_SEC;
	printf("循环耗时:%fs\n",t);
//	show(head);
	s=clock();
	NewHead=fanzhuan1(head);
	f=clock();
	t=(f-s)/CLOCKS_PER_SEC;
	printf("递归耗时:%fs\n",t);
//	show(NewHead);
}
