#include<stdio.h>
void jiecheng(int n,int *p)
{
	if(n<1)
		return;
	(*p)*=n;
	jiecheng(n-1,p);
}

void main()
{
	int n=0,mut=1;
	int *p=&mut;
	scanf("%d",&n);
	jiecheng(n,p),mut;
	printf("%d\n",mut);
}
