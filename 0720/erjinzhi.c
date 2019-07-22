#include<stdio.h>

void main()
{
	int num=0;
	scanf("%d",&num);
	int a=num,b[20]={0},i=0;
	while(a!=0)
	{
		b[i]=a%2;
		i++;
		a=a/2;
	}
	for(i=i-1;i>=0;i--)
	printf("%d",b[i]);
}
