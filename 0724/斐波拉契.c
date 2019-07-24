#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//递归解法

//clock_t clock(void);

long feibo(int n)			50位耗时一分35S
{
	if (n<=1)
		return n;
	else
		return feibo(n-1)+feibo(n-2);
}

//改进方法一:迭代解法			50位耗时0.000160s
long feibo1(int n)
{
	if(n<=0)
	{
		printf("输入有误!");
		return 1;
	}
	int i=1;
	long f1=1,f2=1,sum=1;
	if(n<2)
		return 1;
	for(int i=2;i<=n;i++)
	{
		sum=f1+f2;
		f1=f2;
		f2=sum;
	}
	return sum;
}
//改进方法二:尾递归优化法		50位耗时0.000233s
long feibo2(int n,long f1,long num)
{
	if(n<=0)
	{
		printf("输入有误!");
		return -1;
	}
	if((n<=1)&&(n>0))
		return num;
	return feibo2(n-1,num,f1+num);
}	
	
void main()
{
	float start=0,finish=0,time=0;
	int n=0;
	scanf("%d",&n);
	start=clock();
	long m=feibo(n);
//	long m=feibo1(n);
//	long m=feibo2(n,1,1);
	finish=clock();
	printf("第%d个斐波那契数为%ld\n",n,m);
	time=(finish-start)/CLOCKS_PER_SEC;
	printf("耗时%fs\n",time);
}
