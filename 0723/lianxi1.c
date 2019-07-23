#include<stdio.h>

int mystrlen(char* a)
{
	int i=0;
	for(i=0;a[i]!='\0';i++);
	return i;
}

int mystrlen1(char* a,int* b)
{
	if(*a=='\0')
		return *b;
	(*b)++;
	return mystrlen1(a+1,b);
}

void main()
{
	char a[]="niwnwiiojdiowe";
	int i=0;
	int* b=&i;
	printf("%d\n",mystrlen(a));
	printf("%d\n",mystrlen1(a,b));
}
