#include<stdio.h>

void main()
{
	int b=0;
	int c=0;
	int i;
	int a[5]={5,4,3,2,1};
	for(i=0;i<5;i++)
	{
		if(a[i]>b)
		{
			c=b;
			b=a[i];
		}
	}
	printf("%d,%d\n",b,c);
}

