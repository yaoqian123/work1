#include<stdio.h>

void main()
{
	int a=0;
	char *pa=&a;
	printf("%d %d %d %d\n",*(pa+3),*(pa+2),*(pa+1),*(pa+0));
}
