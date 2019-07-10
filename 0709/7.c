#include<stdio.h>
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int n=10;
	int low=0;
	int high=n-1;
	int num,mid;
	int b=0;
	scanf("%d",&num);
	while(low<=high)
	{
		 mid=(low+high)/2;
		if(a[mid]==num)
		{
			b=1;
			printf("存在");
			break;
		}
		else if(a[mid]<num)
		{
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
	if(b==0)
		printf("不存在");
}
