#include<stdio.h>

void main()
{
	char* buf[]={"hello","one","name","initiazation","ok","love"};
	int i=0,b=0,p=0,o=0;
	for(i=0;i<6;i++)
	{
		b=0;
		for(int j=0;(*(*(buf+i)+j))!='\0';j++)
		{
			b++;
		}
		if(p<b)
		{
			p=b;
			o=i;
		}
	}
	printf("%s\n",*(buf+o));

}
