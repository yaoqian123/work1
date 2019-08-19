#include<stdio.h>

void main()
{
	FILE* fp=fopen("./a.txt","wb");
	if(fp==NULL)
	{
		perror("open fail\n");
		return;
	}
	char a='0';
	fseek(fp,8*1024*1024,SEEK_SET);
	fputc(a,fp);
	fclose(fp);
}
