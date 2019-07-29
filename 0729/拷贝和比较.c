#include<stdio.h>
#include<assert.h>
#include<string.h>
char* mystrncpy(char* des,char* src,int n)
{
	char* addr=des;
	assert((des!=NULL) && (src!=NULL));
	for(int i=0;i<n;i++)
	{
		if((*(des+i)=*(src+i))!='\0');
	}
	return addr;
}
char mystrncmp(char* des,char* src,int n)
{
	int num=0;
	assert((des!=NULL) && (src!=NULL));
	for(int i=0;i<n;i++)
	{	
		num=*(des+i)-*(src+i);
		if(num!=0 || src[i]=='\0' || des[i]=='\0')
		{
			break;
		}			
	}
	return num;	
}
void main()
{
	char buf3[10]="";
	char buf[10]="";
	char buf1[]="hello world";
	char buf2[]="hello";
	mystrncpy(buf,buf1,5);
	strncpy(buf3,buf1,5);
	printf("%d %d\n",strncmp(buf1,buf2,5),mystrncmp(buf1,buf2,5));
	printf("%s\n",buf);
	printf("%s\n",buf3);
}
