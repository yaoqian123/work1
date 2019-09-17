#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

class people
{
	public:
		people():id(0)
		{
			name=new char('\0');
		}
		people(const char* n,int i):id(i)
		{
			name=new char[10];
			strcpy(name,n);
		}
		people(people &s)
		{
			name=new char[10];
			strcpy(name,s.name);
		}
		void show()
		{
			cout<<name<<endl;
		}
		friend ostream& operator<<(ostream&,people&);
		~people()
		{
			if(this->name!=NULL)
			{
				//[]代表释放整个数组 不加只释放第一个元素
				delete[] name;
			}
		}
	private:
		char* name;
		int id;	
};
//重载输入输出
ostream& operator<<(ostream& output,people& p)
{
	output<<p.name;
	return output;
}
//instream
int main()
{
	people p("zhangsan",18);
	p.show();
	cout<<p<<endl;
}
