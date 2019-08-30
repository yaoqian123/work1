#include<iostream>
#include<string.h>
#include<stdarg.h>
#include<malloc.h>
using namespace std;

class array
{
	public:
		array();
		array(int ,...);
		friend array operator+(array &ar1,array &ar2);
		void show();
	private:
			int len;
			int a[100];
};
array::array()
{
	len=100;
//	int* a=(int *)malloc(sizeof(int)*len);
}
array::array(int ilen,...)
{
	va_list vl;
	va_start(vl,ilen);
	len=ilen;
//	int* a=(int *)malloc(sizeof(int)*len);
	int i=0;
	for(i=0;i<ilen;i++)
	{
		a[i]=va_arg(vl,int);
	}
	va_end(vl);
}
array operator+(array &ar1,array &ar2)
{
	array result;
	result.len=ar1.len+ar2.len;
	int i=0;
	for(i=0;i<ar1.len;i++)
		result.a[i]=ar1.a[i];
	for(i=ar1.len;i<result.len;i++)
		result.a[i]=ar2.a[i-ar1.len];
	return result;
}
void array::show()
{
	int i;
	for(i=0;i<len;i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	array a1(5,1,2,3,4,5);
	array a2(5,6,7,8,9,10);
	a1.show();
	cout<<endl;
	a2.show();
	cout<<endl;
	array result=a1+a2;
	result.show();
}
