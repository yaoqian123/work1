#include<stdio.h>

void main()
{
//	short a;//分配2个字节
//	printf("%d\n",a);
//	printf("&a=%x\n",&a);
	//定义指针变量
//	short* pa=&a;
//	printf("%d\n",sizeof(pa));
	//引用指针变量
//	printf("%d\n",pa);
	//引用指针变量指向的内容
//	printf("%d\n",*pa);
	
	int a=131073;
	//定义指针变量:分配空间8Byte
	short* pa=&a;
	int* pb=&a;
	printf("%d %d %d %x %x\n",a,*pa,*pb,pb,pa);
	
}
