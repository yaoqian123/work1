#include<stdio.h>

void main()
{
	int num[10]={9,8,7,6,5,4,3,2,1,0};
	int i=0,j=0;
	for(i=0;i<10;i++)
	{
		int lis=i;
		for(j=i+1;j<10;j++)
		{
			if(*(num+lis)>*(num+j))
				lis=j;
		}
		if(lis!=i)
		{
			int mid=*(num+i);
			*(num+i)=*(num+lis);
			*(num+lis)=mid;
		}
	}
	for(i=0;i<10;i++)
	printf("%d",*(num+i));
}
