#include<stdio.h>

void erjinzhi(int n)
{
	if(n==0)
		return;
	else{
		erjinzhi(n/2);
		printf("%d",n%2);
	}
}

void main()
{
	int n=0;
	scanf("%d",&n);
	erjinzhi(n);
}
