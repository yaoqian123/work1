//10进制转化为浮点型二进制
#include<stdio.h>

void main()
{
	double num=0,n=0;
	int a=0,b=0,c[10]={0},i=0;
	scanf("%lf",&num);
	a=num;
	b=num;
	if(a==0)
		printf("0");
	while(a!=0)
	{
		c[i]=a%2;
		a=a/2;
		i++;
	}
	for(i=i-1;i>=0;i--)
	{
		printf("%d",c[i]);
	}
	printf(".");
	n=num-b;
	for(i=0;i<8;i++)
	{
		n*=2;
		if(n>=1)
		{
			n=n-1;
			printf("1");
		}
		else{
			printf("0");
	}
	}	
}

