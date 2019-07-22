#include<stdio.h>

char *copy(char *des,char* src)
{
	char* addr=des;
	for(int i=0;des[i]!='\0';i++)
	{
		if(src[i]!='\0')
			des[i]=src[i];
		else
		{
			des[i]='\0';
			break;
		}
		
	}
	return addr;
}

void main()
{
	char src[]="sad";
	char des[]="bfesadsaa";
	copy(des,src);
	printf("%s\n",des);
}
