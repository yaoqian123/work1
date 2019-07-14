#include<stdio.h>

void main()
{
	int num=0;
	scanf("%d",&num);
	int b=num;
	int i=0;
	int c[20];
	while(b!=0)
	{	
		c[i]=b%2;
		b=b/2;
		i++;
				
	}
	for(int j=i-1;j>=0;j--)
	{
		printf("%d",c[j]);
	}
		
}
