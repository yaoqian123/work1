#include<iostream>
#include<string.h>
using namespace std;

class people
{
	public:
		char name[20];
		int id;
	protected:
		int money;
	private:
		unsigned short age;
	public:
		unsigned short getage()
		{
			return age;
		}
		unsigned short setage()
		{
			age=23;
			return age;
		}
		people()
		{
			strcpy(name,"yaoqian");
			id=1000;
			money=100;
			age=20;
		}
};

int main()
{
	people yq;
	cout<<yq.name<<endl;
	cout<<yq.getage()<<endl;
	cout<<yq.setage()<<endl;
}
