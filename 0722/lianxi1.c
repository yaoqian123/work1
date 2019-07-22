#include<stdio.h>

void sort(int *a,int len)
{
	for(int i=0;i<len;i++)
	{
		int mid=i;
		for(int j=i+1;j<len;j++)
		{
			if(a[j]>a[mid])
				mid=j;
		}
		if(mid!=i)
		{
			int lis=a[mid];
			a[mid]=a[i];
			a[i]=mid;
		}
	}
}

void main()
{
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	sort(a,10);
	for(int i=0;i<10;i++)
		printf("%d",a[i]);
	printf("\n");
}
