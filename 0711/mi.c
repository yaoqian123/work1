//判断一个数是否是4的幂
//循环解法
#include<stdlib.h>
#include<stdio.h>
/*
void main()
{
	int num=1;
	int n=1;
	int m=0;
	scanf("%d",&num);
	if(num==1)
	printf("为4的幂");
	while(n<num)
	{
		n*=4;
		if(n==num)
		{
			printf("为4的幂");
			m=1;
		}		
	}
	if(m==0)
		printf("不为4的幂");        
}
*/

//递归解法
int digui(int n)
{
	if(n==1)
		return 0;
	else
		return 1+log4(n>>2);
}
void main()
{
	int num=0;
	scanf("%d",&num);
	if(num&(num-2))
	printf("shi");
	else 
	printf("bushi");
}

		

