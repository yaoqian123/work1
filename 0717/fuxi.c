#include<stdio.h>

void main()
{
	int a[10]={8,9,3,6,5,4,7,2,1,0};
	int i=0,j=0;
	int lis=a[0];
	for(i=0;i<10;i++)
	{
		for(j=0;j<10-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
			int mid=a[j];
			a[j]=a[j+1];
			a[j+1]=mid;
			}
		}
	}
	for(i=0;i<10;i++)
	{
		if(lis<a[i])
			lis=a[i];
		printf("%d",a[i]);
	}
	printf("\n");
	printf("%d\n",lis);
}
