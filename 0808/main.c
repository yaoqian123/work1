#include<stdio.h>
#include"Link.h"
void main()
{
	pnode head=creat();
	add1(1,&head);
	add(2,&head);
	add1(3,&head);
	add(4,&head);
	show(head);
	delete(1,&head);
	delete(3,&head);
	delete(4,&head);
	show(head);
	change(2,3,head);
	show(head);
}
