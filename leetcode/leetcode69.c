#include<stdio.h>

void main()
{
	long x=0,i=0;
	int flag=0;
	scanf("%ld",&x);
	for(i=0;i*i<=x;i++);
		if(i*i==x)
		{
			printf("%d\n",i);
			flag=1;
		}
	
	if(flag==0)
	printf("%d\n",i-1);
}
