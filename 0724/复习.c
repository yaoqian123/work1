//二分查找2种方法
#include<stdio.h>
//递归
int erfen(int *a,int n,int key,int high,int low)
{
	if(a[low]>a[high])
		return -1;
	int mid=(high+low)/2;
	if(a[mid]==key)
	{
		printf("存在!\n");
		return mid;
	}
	else if(a[mid]>key)
	{
		high=mid-1;
		return erfen(a,n,key,high,low);		
	}else
	{
		low=mid+1;
		return erfen(a,n,key,high,low);
	}
	if(high<=low)
		printf("不存在\n");
}
//循环
int erfen1(int *a,int n,int key,int high,int low)
{
	if(a[high]<a[low])
		return -1;
	int i=0;
	while(high>=low)
	{
		int mid=(high+low)/2;
		if(a[mid]==key)
		{
			printf("存在\n");
			return mid;
		//	break;
		}else if(a[mid]>key)
		{
			high=mid-1;
		}else
		{
			low=mid+1;
		}
	}
	if(high<=low)
		printf("不存在\n");
}

void main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int n=10,low=0,high=n-1,key=0;
	printf("输入要查找的数:");
	scanf("%d",&key);
	printf("%d\n",erfen(a,n,key,high,low));
	printf("%d\n",erfen1(a,n,key,high,low));
}
