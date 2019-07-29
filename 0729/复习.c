#include<stdio.h>
#include<assert.h>
//循环
int erfen(int* a,int low,int high,int key)
{
	if(high<low)
		return -1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid]>key)
			high=mid-1;
		else
			low=mid+1;
	}
//	printf("不存在此值!\n");	
}
//递归
int erfen1(int *a,int low,int high,int key)
{
	if(high<low)
		return -1;
	int mid=(high+low)/2;
	if(a[mid]==key)
		return mid;
	else if(a[mid]>key)
		return erfen1(a,low,mid-1,key);
	else
		return erfen1(a,mid+1,high,key);
}
void kuaisu(int* a,int low,int high)
{
	if(low>=high)
		return;
	int i=low;
	int j=high;
	int key=a[low];
	while(i<j)
	{
		while(i<j && a[j]<=key)
			j--;
		a[i]=a[j];
		while(i<j && a[i]>=key)
			i++;
		a[j]=a[i];
	}
	a[i]=key;
	kuaisu(a,low,i-1);
	kuaisu(a,i+1,high);
}

void main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int n=sizeof(a)/sizeof(int);
	int key;
	scanf("%d",&key);
	printf("%d\n",erfen(a,0,n-1,key));
	printf("%d\n",erfen1(a,0,n-1,key));
	kuaisu(a,0,n-1);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
