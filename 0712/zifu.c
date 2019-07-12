#include<stdio.h>
#include<string.h>
void main()
{
/*	printf("%d\n",sizeof("hello\0world"));
	printf("%d\n",strlen("hello\0world"));
	printf("%s\n","hello\0world\0");
	*/
	char name[8]={'y','a','o','q','i','a','n'};
	printf("%d\n",sizeof(name));
	printf("%s\n",name);
	for(int i=0;name[i]!='\0';i++)
	{
		printf("%c",name[i]);
	}
}
	
