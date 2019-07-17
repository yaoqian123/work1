#include<stdio.h>

void main()
{
	char* group_name[11]={"a","b""c","d","e","f","g","h","i","j",NULL};
	int num=0;
	scanf("%d",&num);
	printf("%s",*(group_name+num-1));

}
