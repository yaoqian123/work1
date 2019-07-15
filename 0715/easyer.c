//简单的二分查找
#include<stdio.h>

void main()
{
	int a[20]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	int num=0;
	printf("请输入要查找的元素:\n");
	scanf("%d",&num);
	int high=20-1;
	int low=0;
	int flag=0;
	while(low<=high)
	{
		int mid=(high+low)/2;
		if(a[mid]>num)
		{
			high=mid-1;
		}
		else if(a[mid]<num)
		{
			low=mid+1;
		}
		else
		{
			printf("找到此数!");
			flag=1;
			break;
		}
	}
	if(flag==0)
	printf("查无此数!");
}
