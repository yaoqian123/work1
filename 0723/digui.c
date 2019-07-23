#include<stdio.h>

void show(int i,int* p)
{
	if(i<1)
		return;
	*p+=i;
	printf("%d\n",i);
	//递归
	show(i-1,p);
}

void main()
{
	int sum=0;
	int* p=&sum;
	show(100,p);
	printf("%d\n",sum);
}
