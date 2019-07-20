//删除有序数组中的重复元素
#include<stdio.h>

void main()
{
	int num[10]={0,0,1,1,2,2,3,3,4,4};
	int i=0,j=0,k=0;
	for(j=1;j<10;j++)
	{
		if(num[i]!=num[j])
		{
			i++;
			num[i]=num[j];
		}	
	}
	for(k=0;k<i+1;k++)
	printf("%d ",num[k]);

}
