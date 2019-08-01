#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
typedef int elem;
typedef struct Student
{
	char name[10];
	char sex[5];
	int age;
}stu,*pstu;
typedef struct Link
{
	stu s;
	struct Link* next;
}link,*plink;
plink creat()
{
	plink head=NULL;
	return head;
}

bool add(stu s,plink* phead)
{
	plink pnew=(plink)malloc(sizeof(link));
	if(pnew==NULL)
	{
		printf("无可用空间!\n");
		return false;
	}
	strcpy(pnew->s.name,s.name);
	strcpy(pnew->s.sex,s.sex);
	pnew->s.age=s.age;
	pnew->next=*phead;
	*phead=pnew;
	return true;
}
void main()
{
	plink head=creat();
	int len=100,i=0;	
	FILE* fp1=fopen("./a.txt","r");
	FILE* fp=fopen("./b.txt","w+");
	if(NULL==fp1)
	{
		perror("open fail\n");
		return;
	}
	plink p=head;
	char c;
	c=fgetc(fp1);
	while(c!=EOF)
	{
		c=fgetc(fp1);
		fputc(c,fp);
	}
	fclose(fp1);
	fclose(fp);	

}
