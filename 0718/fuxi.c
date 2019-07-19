#include<stdio.h>

void main()
{
	int n=0,i=0,num=0,j=0;
	int a[10]={9,8,7,6,5,4,3,2,1,0};
	n=10;
	scanf("%d",&num);	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	for(i=0;i<10;i++)
	printf("%d",a[i]);
}

