#include<stdio.h>
int main()
{
	int num=0,a=0,i=0;
	int b[100]={0};
	scanf("%d",&num);
	for(i=num;i>=0;i--)
	{
		a=i;
		while(a)
		{
	       		a=a&(a-1);
	      		b[i]++;
		}
	}
	for(i=0;i<=num;i++)
	{
		printf("%d ",b[i]);
	}
}
