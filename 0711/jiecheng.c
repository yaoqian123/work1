//求输入数字的阶乘
#include<stdio.h>

void main()
{
	int a=0;
	int num=1;
	scanf("%d",&a);
	while(a != 0)
	{
		num=num*a;
		a--;
	}
	printf("%d\n",num);
}
