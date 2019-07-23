#include<stdio.h>

int add(int a,int b)
{
	int result=0;
	result=a+b;
	return result;
}
int jian(int a,int b)
{
	int result=0;
	result=a-b;
	return result;
}
int cheng(int a,int b)
{
	int result=0;
	result=a*b;
	return result;
}
int chu(int a,int b)
{
	int result=0;
	result=a/b;
	return result;
}
void main()
{
	int data1,data2;
	char opr;
	scanf("%d%c%d",&data1,&opr,&data2);
	int (* pfun)(int,int)=add;
	if(opr=='+')
		pfun=add;
	else if(opr=='-')
		pfun=jian;
	else if(opr=='*')
		pfun=cheng;
	else if(opr=='/')
		pfun=chu;
	else
		printf("输入非法!");
	printf("%d%c%d=%d\n",data1,opr,data2,pfun(data1,data2));
}
