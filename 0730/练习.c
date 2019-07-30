#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct person
{
	int id;
	char name[10];
}person,*pperson;
void assignment(pperson p,int i)
{
	printf("学号:");
	scanf("%d",&p[i].id);
	printf("姓名:");
	scanf("%s",p[i].name);
}
void paixu(pperson p,int len)
{
	int i=0,j=0;
	for(i=0;i<len;i++)
	{
		person z=p[i];
		for(j=i-1;j>=0;j--)
		{
			if(p[j].id>z.id)
				p[j+1]=p[j];
			else
				break;
		}
		p[j+1]=z;
	}
}
char* max(pperson p,int len)
{
	int i=0;
	int max=p[0].id;
	for(i=1;i<len;i++)
	{
		if(max<p[i].id)
			max=p[i].id;
	}
	for(i=0;i<len;i++)
	{
		if(max==p[i].id)
			return p[i].name;
	}	
}
bool key(pperson p,int key,int len,char* name)
{
	int i=0,flag=0;
	for(i=0;i<len;i++)
	{
		if(key==p[i].id)
		{
			strcpy(name,p[i].name);
			flag=1;
			return true;
		}
	}
	if(flag==0)
		return false;
}
void main()
{
	char name[10]="";
	pperson p=malloc(sizeof(person)*4);
	for(int i=0;i<4;i++)
	{
		assignment(p,i);
	}
	paixu(p,4);
	printf("%s\n",max(p,4));
	if(key(p,2,4,name))
	printf("%s\n",name);
	free(p);	
}
