#include<stdio.h>

void show(int buf[][3])
{
	for(int m=0;m<2;m++)
	{
		for(int n=0;n<3;n++)
		printf("%d ",buf[m][n]);
	}
}

void main()
{
	int buf[2][3]={1,2,3,4,5,6};
	show(buf);
}
