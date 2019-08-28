#include<iostream>
#include<string.h>
using namespace std;

class people
{
	public:
		char name[10];
		int id;
	protected:
		short money;
	private:
		short age;
	public:
		void show()
		{
			cout<<"我是show函数"<<endl;
		}
		//在类内定义接口访问保护和私有属性
		int getage();
		int setage()
		{
			age=20;
			return age;
		}
		//有参构造
		student(char* name,int id,short age,short money)
		{
			strcpy(this->name,name);
			this->id=id;
			this->age=age;
			this->money=money;
		}
		//无参构造
		people()
		{
			strcpy(name,"yaoqian");
			age=23;
			money=100;
			id=1001;
		}
};
int people::getage()
{
	return age;
}
int main()
{
	people yq;
	cout<<yq.name<<endl;
	cout<<yq.getage()<<endl;
	cout<<yq.setage()<<endl;
}
