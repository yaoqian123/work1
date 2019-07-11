//5到1阶乘相加一个循环内完成
#include<stdio.h>

void main(){

	int num1=1,num2=1,num3=1,num4=1,num5=1;
	for(int i=1;i<6;i++)
	{
		num1*=i;
		if(i>2)
			num2*=(i-1);
		if(i>3)
			num3*=(i-2);
		if(i>4)
			num4*=(i-3);
		if(i>5)
			num5*=(i-4);
	}
	printf("%d\n",num1+num2+num3+num4+num5);
}
