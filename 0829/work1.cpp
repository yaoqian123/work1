#include<iostream>
#include<stdbool.h>
#include<stdio.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class list
{
	public:
		struct node *s;
		list()
		{
			s=NULL;
		}
		bool add_head(struct node**,int);
		bool add_rear(struct node**,int);
		bool alter(struct node*,int,int);
		bool erg(struct node*);
		list(list&);
	
};

//头插
bool list::add_head(struct node** p,int i)
{	
		struct node* pnew=new struct node;
		if(pnew==NULL)
		{
			printf("new fail\n");
			return false;
		}
		pnew->data=i;
		pnew->next=*p;
		*p=pnew;
			
		
}

//尾插
bool list::add_rear(struct node** p,int i)
{
		struct node* pnew=new struct node;
		if(pnew==NULL)
		{
			printf("new fail\n");
			return false;
		}
		pnew->data=i;
		pnew->next=NULL;
		if(*p==NULL)
		{
			*p=pnew;
		}
		else
		{
			struct node* prear=new struct node;
			prear=*p;
			while(prear->next!=NULL)
				prear=prear->next;
			prear->next=pnew;
		}
		return true;
	
}

bool list::alter(struct node* p,int key,int data)
{	
		while(p!=NULL)
		{
			if(p->data==key)
			{
				p->data=data;
				return true;
			}
			p=p->next;
		}
		return false;
}

bool list::erg(struct node* p)
{
	while(p!=NULL)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
}		

list::list(list& l)
{
		*this=l;
		struct node* pnew=l.s;
		struct node* pnew1=this->s;
		while(pnew!=NULL)
		{
			pnew1=new struct node(*pnew);
			pnew1=pnew1->next;
			pnew=pnew->next;
		}
/*		s=new struct node;
		s=l.s;
*/		
}

int main()
{
	list l;
	l.add_rear(&l.s,5);
	l.add_rear(&l.s,10);
	l.add_rear(&l.s,25);	


	list z(l);
	l.erg(l.s);
	l.alter(l.s,25,20);
	z.erg(z.s);
	
		
}
