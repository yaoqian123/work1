#include<stdio.h>

void main()
{
	int num[10]={0,1,2,3,4,5,6,7,8,9};
	int target=0;
	int i=0,j=0;
	scanf("%d",&target);
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(num[i]+num[j]==target)
				printf("{%d %d}",i,j);
		}
	}
}

