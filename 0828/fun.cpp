#include<iostream>
#include<stdio.h>
using namespace std;

//函数模板
/*
int fun(int a,int b)
{
	return a+b;
}
float fun(float a,float b)
{
	return a+b;
}
*/
template<typename T>
T fun(T a,T b)
{
	return a+b;
}
int main()
{
	//根据传入参数自动选择类型
	//函数体一样
	cout<<fun(1,2)<<endl;
	cout<<fun(1.1,1.2)<<endl;
}
