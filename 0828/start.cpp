#include<iostream>
#include<stdio.h>
using namespace std;
int i=20;
int main()
{
	//输出
	cout<<"hello world!\n";
	int i=10;
	::i=::i*i;
//	cin>>i;
	cout<<"i的值为"<<::i<<endl;
}
