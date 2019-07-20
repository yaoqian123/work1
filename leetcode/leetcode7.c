//反转整数
#include<stdio.h>

void main()
{
	int a=0,n=0,m=0;
	scanf("%d",&a);
	for(int i=0;a!=0;i++)
	{
		n=a%10;
		a/=10;
		m=m*10+n;
	}
	printf("%d\n",m);
	
}
	
	
