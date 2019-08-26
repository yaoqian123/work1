#include<stdio.h>

void main()
{
	char b[10]="";
	scanf("%s",b);
	FILE* fp=fopen(b,"wb");
	if(fp==NULL)
	{
		perror("open fail\n");
		return;
	}
	char a='0';
	fseek(fp,8*1024*1024*8,SEEK_SET);
	fputc(a,fp);
	fclose(fp);
}
