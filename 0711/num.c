//不同位数分离
#include<stdio.h>
void main()
{
	int a;
	scanf("%d",&a);
	while(a*10/10!=0)
	{
		int b,c;
		b=a/10;
		c=a-b*10;
		a=a/10;
		printf("%d",c);
	}
}
	
