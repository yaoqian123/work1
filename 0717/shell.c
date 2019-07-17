//希尔排序
#include<stdio.h>

void main()
{
	int i=0,j=0,temp=0;                
	int gap = 0;
	int a[10] = {5,3,4,2,1};
	for(int i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	const int n=10;
	while(gap<=n)
	{
		gap=gap*3+1;
	}
	while(gap>0)
	{
		for(i=gap;i<n;i++)
		{
			j=i-gap;
			temp=a[i];
			while((j>=0)&&(a[j]>temp))
			{
				a[j+gap]=a[j];			//对指定增量元素排序
				j=j-gap;
			}
			a[j+gap]=temp;
		}
		gap=(gap-1)/3;
	}
	for(i=0;i<n;i++)
		printf("%d",a[i]);
}
