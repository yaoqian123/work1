#include<stdio.h>

void main()
{
	int a[4]={1,2,3,4};
	//0   4       8      12       16   
	//[1000000 00000000000000000000000] [01000000 30] [11 30] [100 29]
	int *ptr1=(int *)(&a-1);
	int *ptr2=(int *)((int)a+1);		//截断错误
	printf("%x %x",ptr1[-1],*ptr2);
	system("pause");
}
