#include<stdio.h>

void main()
{
	char a[10]={9,8,7,6,5,4,3,2,1,0};
	char *pa=a;
	int i=0,j=0,mid=0,flag=0;
	for(i=0;i<10;i++)
	{
		flag=0;
		for(j=0;j<10-i-1;j++)
			if(pa[j]>pa[j+1])
			{
				mid=pa[j+1];
				pa[j+1]=pa[j];
				pa[j]=mid;
				flag=1;
			}
		if(flag==0)
			break;
	}
	for(i=0;i<10;i++)
		printf("%d",a[i]);
	printf("\n");
}

