//求最小公倍数
#include<stdio.h>
void main()
{
	int a,b;
	int c=1;
	scanf("%d",&a);
	scanf("%d",&b);
	while(c%a!=0 || c%b!=0)
	{
		c++;
	}
	printf("%d",c);
}


