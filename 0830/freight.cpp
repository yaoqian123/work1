#include<iostream>
using namespace std;
class point
{
	public:
		point():x(0),y(0)
		{}
		point(int a,int b):x(a),y(b)
		{}
		friend point operator+(point &p1,point &p2);
		void show()
		{
			cout<<"x:"<<x<<"\n"<<"y:"<<y<<endl;
		}
	private:
		int x;
		int y;
};

point operator+(point &p1,point &p2)
{
	point result;
	result.x=p1.x+p2.x;
	result.y=p1.y+p2.y;
	return result;
}

int main()
{
	point p1(1,2);
	point p2(3,4);
	point result=p1+p2;
	result.show();
}

