#include<stdio.h>

void main()
{
	int num=0;
	scanf("%d",&num);
	int a[100]={0};
	for(int i=1;i<=num;i++)			//通过奇偶性判断
	{
		if(i%2==1)
		{
			a[i]=a[i-1]+1;		//奇数位等于偶数位加末尾1
		}else{
			a[i]=a[i/2];		//偶数除2等于右移一位 1的数量不变
		}
	}
	for(int i=0;i<=num;i++)
	printf("%d ",a[i]);
}
