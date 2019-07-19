#include<stdio.h>

void main()
{
	int num=0,i=0,j=0,z=0,k=0,l=0;
	scanf("%d",&num);
	int a[100]={0};
	for(i=0;i<=num;i++)
	{
		z=i;
		for(j=0;z!=0;j++)
		{
			if(z%2==1)
				a[k]++;
			z=z/2;
		}
		k++;
	}
	for(l=0;l<=num;l++)
		printf("%d ",a[l]);
}
