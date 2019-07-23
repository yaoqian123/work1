//斐波那契数列
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//递归解法

clock_t clock(void);

long feibo(int n)
{
	if(n<=1)
		return n;
	else
		return feibo(n-1)+feibo(n-2);
}

//改进方法一:迭代解法
long feibo1(int n)
{
	if(n<=0)
		printf("输入有误!");
	int i=1;
	long f1=1,f2=1,sum=1;
	if(n<=2)
		return 1;
	for(int i=3;i<=n;i++)
	{
		sum=f1+f2;
		f1=f2;
		f2=sum;
	}
	return sum;
}

//改进方法二:
void main()
{
	float start=0,finish=0,time=0;
	int n=0;
	start=clock();
	scanf("%d",&n);
	long m=feibo(n);
//	long m=feibo1(n);
	finish=clock();
	printf("第%d个斐波那契数为%ld\n",n,m);
	time=(finish-start)/CLOCKS_PER_SEC;
	printf("耗时%fs\n",time);
}
