#include<iostream>
#include<string.h>
using namespace std;
class score
{
	public:
		//无参构造
		score();
		score(int,int,int);
		void show();
	private:
		int chinese;
		int math;
		int eng;
};
score::score():chinese(0),math(0),eng(0)
{}
score::score(int c,int m,int e):chinese(c),math(m),eng(e)
{}
void score::show()
{
	cout<<"语文"<<chinese<<"数学"<<math<<"英语"<<eng<<endl;
}
class student
{
	public:
		student();
		student(int,char*,int,int,int);
		void show();
	private:
		char name[10];
		int id;
		//score类做属性
		score s;
};
student::student():id(0),s()
{
	strcpy(name,"NUL");
}
student::student(int id,char* name,int c,int m,int e):s(c,m,e),id(id)
{
	strcpy(this->name,name);
}
//访问私有属性
/*
void student.show() s.show():show()
{
	cout<<"名字"<<name<<endl;
	s.show();
}
*/
void::student::show()
{
	cout<<"姓名"<<name<<endl;
	s.show();
}
int main()
{
	score a(100,100,100);
	a.show();
	student b(1001,"zs",100,100,100);
//	student b;
	b.show();
}
