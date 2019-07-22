#include<stdio.h>

void fh(char *a)
{
	int i=0;
	while(a[i]!='\0')
	{
		if('A'<a[i] && a[i]<'Z')
			a[i]+=32;
		i++;
	}
}
void main()
{
	char a[]="sdASDSFsfasqASDFSns";
	fh(a);
	printf("%s\n",a);
}
