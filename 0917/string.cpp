#include<iostream>
#include<string.h>
using namespace std;

class string1
{
	public:
		string1();
		string1(const char*);
		string1(const string1&);
		~string1();
		friend ostream& operator<<(ostream&,string1&);
		friend istream& operator>>(istream&,string1&);
		string1 operator+(string1&);
		int lenth()
		{
			int i=0;
			while(this->buf!=NULL&& this->buf[i++]!='\0');
			return i;
		}
	private:
		char* buf;
};

string1::string1()
{
	buf=new char('\0');
}

string1::string1(const char* buf)
{
	this->buf=new char(strlen(buf)+1);
	if(this->buf!=NULL)
		memcpy(this->buf,buf,strlen(buf)+1);
}

string1::string1(const string1& s)
{
	this->buf=new char(strlen(s.buf)+1);
	if(this->buf!=NULL)
		memcpy(this->buf,s.buf,strlen(buf)+1);
}

string1::~string1()
{
	if(this->buf!=NULL)
		delete[] this->buf;
}

ostream& operator<<(ostream& output,string1& s)
{
	output<<s.buf;
	return output;
}

istream& operator>>(istream& input,string1& s)
{
	input>>s.buf;
	return input;
}

string1 string1::operator+(string1& s)
{
	string1 result;
	result.buf=new char(this->lenth()+s.lenth()+1);
	memcpy(result.buf,this->buf,this->lenth());
	memcpy(result.buf+this->lenth()-1,s.buf,s.lenth());
	return result;
}

int main()
{
//	string1 s1("hello");
	string1 s1="hello";
//	string1 s2(" world");
	string1 s2=" world";
//	string1 s3(s1+s2);
	string1 s3=s1+s2;
	cout<<s3<<endl;
	string1 s4;
	cin>>s4;
	cout<<s4<<endl;
}
