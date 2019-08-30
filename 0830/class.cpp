#include<iostream>
#include<string.h>
using namespace std;

class student
{
	student();
	student(int,char*);
	friend void fun();

	private:
		int id;
		char name[10];
};
//1:作用域 2:方法名
student::people()
{
	id=0;
	strcpy(name,"NULL");
}
student::student(int i,char* name)
{
	id=i;
	strcpy(this->name,name);
}
void fun()
{
	student stu;
	//私有属性
	cout<<stu.id<<endl;
}
int main()
{
	fun();
}
