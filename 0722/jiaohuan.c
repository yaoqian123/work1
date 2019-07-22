#include<stdio.h>

void swap(int *pa,int *pb)
{
	*pa=*pa+*pb;
	*pb=*pa-*pb;
	*pa=*pa-*pb;
	printf("%d %d\n",*pa,*pb);
}

void main()
{
	int a=1,b=2;	
	int *pa=&a;
	int *pb=&b;
	swap(pa,pb);
	printf("%d %d\n",a,b);
}
