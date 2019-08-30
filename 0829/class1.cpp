#include<iostream>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
typedef int elem;

		typedef struct Node
		{
			elem data;
			struct Node* next; 
		}node,*pnode;
class link
{
	public:
		pnode phead;
		//无参构造
		link()
		{
			phead=NULL;
		}
		//拷贝函数
		link(link &s)
		{
		/*	*this=s;
			pnode pnew=this->phead;
			pnode pnew1=s.phead;
			while(pnew1!=NULL)
			{
				pnew=new node(*pnew1);
				pnew1=pnew1->next;
				pnew=pnew->next;
			}
			*/
			phead=new node;
			phead=s.phead;
		}
		bool add(elem data,pnode* phead)
		{
			pnode pnew=new node;
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
			pnode pnew=new node;
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
				while(prear->next!=NULL)
					prear=prear->next;
				prear->next=pnew;
			}
			return true;
		}
		bool Delete(elem data,pnode* phead)
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
			while(ploc!=NULL)
			{
				if(ploc->data==key)
				{
					ploc->data=data;
					return true;
				}
				ploc=ploc->next;
			}
			return false;
		}
		void show(pnode phead)
		{
			pnode ploc=phead;
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

};

int main()
{
	link lk1;
	lk1.add1(1,&lk1.phead);
	lk1.add1(2,&lk1.phead);
	link lk2(lk1);
	lk1.show(lk1.phead);
	lk2.show(lk2.phead);
	printf("\n");
	lk1.change(1,3,lk1.phead);
	lk2.change(2,4,lk1.phead);

	lk1.show(lk1.phead);
	lk2.show(lk2.phead);
}
