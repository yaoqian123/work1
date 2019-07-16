#include<stdio.h>

void main()
{
	int a=100;
	//printf("%d %x\n",a,&a);//引用：引用空间内容
	//printf("%x %d\n",&a,*(&a)); 
	//错误：*地址
	
	//定义指针变量
	short* p=&a;
	printf("%d\n",*p);
}
