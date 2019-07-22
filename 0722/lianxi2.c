#include<stdio.h>

int length(char *a)
{
	int i=0;
	while(a[i]!='\0')
		i++;
	return i;
}

void main()
{
	char a[]="fsdknjferdenjak";
	int len=0;
	len=length(a);
	printf("%d\n",len);
}
