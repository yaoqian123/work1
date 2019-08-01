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
	int len,i;
	printf("输入长度:\n");
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		stu s={0};
		printf("输入姓名:");
		scanf("%s",s.name);
		printf("输入性别:");
		scanf("%s",s.sex);
		printf("输入年龄:");
		scanf("%d",&s.age);
		add(s,&head);
	}
	FILE* fp=fopen("./a.txt","w");
	if(NULL==fp)
	{
		perror("open fail\n");
		return;
	}
	plink p=head;
	for(p=head;p!=NULL;p=p->next)
	{
		fprintf(fp,"name=%s sex=%s age=%d\n",p->s.name,p->s.sex,p->s.age);
		fseek(fp,1,SEEK_CUR);
	}	
	fclose(fp);	
	FILE* fp1=fopen("./a.txt","r");
	if(NULL==fp1)
	{
		perror("open fail\n");
		return;
	}
	stu s;
	for(i=0;i<len;i++)
	{
		fscanf(fp1,"name=%s sex=%s age=%d\n",s.name,s.sex,&s.age);
		printf("name=%s sex=%s age=%d\n",s.name,s.sex,s.age);
		fseek(fp1,1,SEEK_CUR);
	}
	fclose(fp1);
}
