#include<stdio.h>
#include<assert.h>
char* mystrncpy(char* des,char* src,int n)
{
	char* addr=des;
	assert((des!=NULL) && (src!=NULL));
	for(int i=0;i<n;i++)
	{
		if((*(des+i)=*(src+i))!='\0');
			*(des+i)=*(src+i);
	}
	return addr;
}
char mystrncmp(char* des,char* src,int n)
{
	int num=0;
	assert((des!=NULL) && (src!=NULL));
	for(int i=0;i<n;i++)
	{
		if((*(des+i)=*(src+i))==0 && *(src+i)!='\0')
		num=(*(des+i)-*(src+i));
	}
	return num;	
}
void main()
{
	char buf[10]="";
	char buf1[]="hello world";
	char buf2[]="hello";
	mystrncpy(buf,buf1,5);
	printf("%d\n",mystrncmp(buf1,buf2,5));
	printf("%s\n",buf);
}
