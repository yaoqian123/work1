#include<stdio.h>

void main()
{
	//a=0,第一字节存1第二字节存2第3字节存3第4字节存4打印a
	int a=0;
	char* pa=&a;
 	*(pa+0)=1;
	*(pa+1)=2;
	*(pa+2)=3;
	*(pa+3)=4;
	printf("%d\n",a);
}
