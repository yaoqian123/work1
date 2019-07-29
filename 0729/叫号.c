#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<string.h>

#define MAXSIZE 100
typedef int elem;
typedef struct patient
{
	char name[10];
       	short age;
	long phonenum;
	char sex[5];
}patient,*ppatient;

typedef struct Duilie
{
	patient pa[MAXSIZE];
	short out;		
	short in;		
}duilie,*pduilie;

void InitDuilie(pduilie pd)
{
	assert(pd!=NULL);
	pd->out=pd->in=1;
}

bool isempty(pduilie pd)
{
	assert(pd!=NULL);
	if((pd->in)%MAXSIZE==(pd->out)%MAXSIZE)
		return true;
	return false;
}

bool isfull(pduilie pd)
{
	assert(pd!=NULL);
	if((pd->in+1)%MAXSIZE==(pd->out)%MAXSIZE)
		return true;
	return false;
}

unsigned short duilielength(pduilie pd)
{
	assert(pd!=NULL);
	return (pd->in-pd->out+MAXSIZE)%MAXSIZE;
}

bool push(pduilie pd,char* name1,long phone,short a,char* s)
{
	assert(pd!=NULL);
	if(isfull(pd))
		return false;
	strcpy((pd->pa[pd->in]).name,name1);
	(pd->pa[pd->in]).age=a;
	(pd->pa[pd->in]).phonenum=phone;
	strcpy((pd->pa[pd->in]).sex,s);		
	pd->in=(pd->in+1);		
	return true;
}

bool pop(pduilie pd,char* name1,long* phone,short* a,char* s)
{
	assert(pd!=NULL);
	if(isempty(pd))
		return false;
	strcpy(name1,(pd->pa[pd->out]).name);
	*a=(pd->pa[pd->out]).age;
	*phone=(pd->pa[pd->out]).phonenum;
	strcpy(s,(pd->pa[pd->out]).sex);			
	pd->out=(pd->out+1)%MAXSIZE;
	return true;
}

void menu1()
{
	printf("\n");
	printf("*************************医院叫号系统************************\n");
	printf("*************************************************************\n");
	printf("***************************1:挂号****************************\n");
	printf("*************************************************************\n");	
	printf("***************************2:叫号****************************\n");
	printf("*************************************************************\n");
	printf("************************3:查询剩余人数***********************\n");
	printf("*************************************************************\n");
	printf("***************************0:退出****************************\n");
	printf("*************************************************************\n");
printf("\n");
}
void menu5()
{
	printf("***************************挂号系统**************************\n");
	printf("*************************************************************\n");
	printf("\n");
}
void menu6()
{
	printf("**************************请输入姓名*************************\n");
	printf("*************************************************************\n");
}
void menu7()
{
	printf("\n");
	printf("**************************请输入年龄*************************\n");
	printf("*************************************************************\n");
}
void menu8()
{
	printf("\n");
	printf("**************************请输入电话*************************\n");
	printf("*************************************************************\n");
}
void menu9()
{
	printf("\n");
	printf("**************************请输入性别*************************\n");
	printf("*************************************************************\n");
}
void menu2(short num,short a)
{
	printf("\n");
	printf("**************************您的号码为****************************\n");
	printf("******************************%2d*****************************\n",num);
	printf("************************您前面还有%2d人************************\n",a);
	printf("**************************************************************\n");	
}
void menu3(short num,char* name,short age,long phonenum,char* sex)
{
	printf("*****************************叫号*****************************\n");
	printf("**************************************************************\n");
	printf("*****************************号码*****************************\n");
	printf("******************************%2d******************************\n",num);
	printf("*****************************姓名*****************************\n");
	printf("****************************%s*****************************\n",name);	
	printf("*****************************年龄*****************************\n");
	printf("******************************%d******************************\n",age);
	printf("*****************************电话*****************************\n");
	printf("**************************%ld*************************\n",phonenum);
	printf("*****************************性别*****************************\n");
	printf("******************************%s******************************\n",sex);
}
void menu4(short num)
{
	printf("*************************查询剩余人数*************************\n");
	printf("*************************************************************\n");
	printf("*************************剩余人数:%d**************************\n",num);
	printf("*************************************************************\n");	

}

void choice(pduilie pd,int *flag)
{
	int opr;
	short a;
	long phone;
	char name1[10];
	char s[5]="";
	scanf("%d",&opr);
	switch(opr)
	{
		case 0:{
				*flag=0;
		       }
		       break;
		case 1:{
			       if(isfull(pd))
			       {
				       	printf("*************************************************************\n");
			       		printf("***************************病人已满***************************\n");
			       }
			       else
			       {
				       	menu5();
					menu6();
				        scanf("%s",name1);
					menu7();
					scanf("%hd",&a);
					menu8();
					scanf("%ld",&phone);
					menu9();
					scanf("%s",s);
			      		push(pd,name1,phone,a,s);
				    	menu2(pd->in-1,pd->in-pd->out);
					printf("\n");
					printf("*************************************************************\n");
			       		printf("***************************挂号成功***************************\n");
			       }
		       }
		       break;
		case 2:{
			       if(isempty(pd)){
			       		printf("***************************已无病人***************************\n");
					printf("*************************************************************\n");
}
			       else
			       {
			       		pop(pd,name1,&phone,&a,s);
					menu3(pd->out,name1,a,phone,s);
			       }
		       }
		       break;
		case 3:{
			       menu4(duilielength(pd));
		       }
		       break;
		default:
		       printf("***************************已无病人***************************\n");
			printf("*************************************************************\n");
		       break;
	}
}
void main()
{
	int flag=1;
	duilie d={0};
	pduilie pd=&d;
	InitDuilie(pd);
	while(flag==1)
	{
		menu1();
		choice(pd,&flag);
	}
}
