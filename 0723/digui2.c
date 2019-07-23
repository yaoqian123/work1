#include<stdio.h>
int f(int n)
{
	if(n==1)
		return 1;
	return n*f(n-1);
}
int s(int n)
{
	if(n==1)
		return f(1);
	return f(n)+s(n-1);
}

void main()
{
	printf("%d\n",s(6));
}
