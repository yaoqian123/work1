#include<stdio.h>

void main()
{
	int buf[]={1,3,4,3,6,7,5,8,9,7,0,8,5,4};
	int *p=(int *)buf;
	int i=0,j=0,z=0,flag=0,l=0;
	int a[14]={0};
	for(i=0;i<14;i++)
	{
		for(j=i+1;j<14;j++)
		{
			flag=0;
			if(*(p+i)==*(p+j))
			{
				flag=1;
				break;		
			}
		}
		if(flag==0)
		{
			a[l]=*(p+i);
			l++;
		}

	}
	for(i=0;i<l;i++)
		printf("%d",a[i]);
	printf("\n");
}
