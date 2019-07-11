//不同位数分离逆序输出
#include<stdio.h>
void main()
{
	int a;
	scanf("%d",&a);
	while(a*10!=0)
	{
		printf("%d",a%10);
		a=a/10;
	}
}
	
