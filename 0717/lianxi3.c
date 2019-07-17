//指针数组
#include<stdio.h>

void main()
{
/*	int a=1,b=2,c=13,d=4,i=0;
	int* pbuf[4]={&a,&b,&c,&d};
	for(;i<4;i++)
	{
		printf("%d\n",*(*(pbuf+i)));
	}
	*/
	int a=100;
	int buf[]={1,2,3,4,5};
	int c=200;
	int buf1[]={21,22,23,24,25};
	int* pbuf[]={&a,buf,&c,buf1,NULL};
	printf("%d\n",**pbuf);
	for(int i=0;i<5;i++)
	{
		printf("%d\t",*(*(pbuf+1)+i));
	}
	printf("\n%d\n",**(pbuf+2));
	for(int i=0;i<5;i++)
	{
		printf("%d\t",*(*(pbuf+3)+i));
	}
	printf("\n");
}
