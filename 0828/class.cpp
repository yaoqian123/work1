#include<iostream>
#include<stdio.h>
using namespace std;
template<typename T>
void fun(T* a,int n)
{
	int i=0,j=0,flag=0;
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				T mid=a[j];
				a[j]=a[j+1];
				a[j+1]=mid;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<"\t";
	cout<<"\n";
}
int main()
{
	int a[10]={5,7,6,4,8,3,9,1,2,0};
	float b[5]={5.0,2.1,4.0,3.0,1.0};
	fun(a,10);
	fun(b,5);
}
