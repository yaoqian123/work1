#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct Student			//学生
{
	int id;
	char name[10];
	char addr[100];
	char sex[5];
	short age;
	int num;
}student,*pstudent;

typedef struct Node			//链表
{
	student s;
	struct Node* next;
}node,*pnode;
bool find(int,pnode);
pnode creat()				//创建链表
{
	pnode head=NULL;
	return head;
}

bool add(student s,pnode* phead)	//插入
{
	pnode pnew=malloc(sizeof(node));
	if(pnew==NULL)
	{
		printf("*********系统已满*********\n");
		return false;
	}
	if(find(s.id,*phead))
		return false;
	pnew->s.id=s.id;		//数据插入
	pnew->s.age=s.age;
	strcpy(pnew->s.name,s.name);
	strcpy(pnew->s.addr,s.addr);
	strcpy(pnew->s.sex,s.sex);
	pnew->s.num=s.num;
	pnew->next=*phead;
	*phead=pnew;
	return true;
}

//通过学号删除学生
bool delete(int id,pnode* phead)
{
	pnode pf=*phead;
	pnode ps=NULL;
	while(pf!=NULL&&pf->s.id!=id)
	{
		ps=pf;
		pf=pf->next;
	}
	if(pf==NULL)
		return false;
	if(pf==*phead)
		*phead=pf->next;
	else
		ps->next=pf->next;
	free(pf);
	return true;
}

//通过学号修改学生信息
bool change(int id,pstudent ps,pnode phead)
{
	pnode ploc=phead;
	while(ploc!=NULL&&ploc->s.id==ps->id)
		ploc=ploc->next;
	if(ploc==NULL)
		return false;
	strcpy(ploc->s.name,(ps)->name);
	strcpy(ploc->s.addr,(ps)->addr);
	strcpy(ploc->s.sex,(ps)->sex);
	ploc->s.id=(ps)->id;
	ploc->s.age=(ps)->age;
	ploc->s.num=ps->num;
	return true;
}

//通过学号寻找学生是否存在
bool find(int id,pnode phead)
{
	pnode ploc=phead;
	while(ploc!=NULL)
	{
		if(id==ploc->s.id)
			return true;
		ploc=ploc->next;
	}
	return false;
}

//单个打印
void show1(pnode ploc,int id)
{
	while(ploc!=NULL&&ploc->s.id!=id)
		ploc=ploc->next;
	if(ploc->s.id==id)
	{
	printf("****************************\n");
	printf("*         学号:%d          *\n",ploc->s.id);
	printf("*         姓名:%s          *\n",ploc->s.name);
	printf("*         地址:%s          *\n",ploc->s.addr);
	printf("*         性别:%s          *\n",ploc->s.sex);
	printf("*         年龄:%hd         *\n",ploc->s.age);
	printf("*         成绩:%hd         *\n",ploc->s.num);
	printf("****************************\n");
	}
}

//全部打印
void show(pnode ploc)
{
	while(ploc!=NULL)
	{
	printf("****************************\n");
	printf("*         学号:%d          *\n",ploc->s.id);
	printf("*         姓名:%s          *\n",ploc->s.name);
	printf("*         地址:%s          *\n",ploc->s.addr);
	printf("*         性别:%s          *\n",ploc->s.sex);
	printf("*         年龄:%hd         *\n",ploc->s.age);
	printf("*         成绩:%hd         *\n",ploc->s.num);
	printf("****************************\n");
	ploc=ploc->next;
	}
}

//判断学号是否重复
void repeat(pnode head,int* id)
{
	pnode ploc=head;
	while(ploc->next!=NULL && ploc->s.id!=*id)
	{
		ploc=ploc->next;
	if(ploc->s.id!=*id)
		return;
	else
	{
		printf("*********重复学号*********\n");
		printf("*********重新输入*********\n");
		scanf("%d",id);
		repeat(head,id);
	}
	}
}

//判断学号是否为指定格式
void xuehaogeshi(int* id)
{
	if(*id>10000000&&*id<100000000)
		return;
	if(*id<10000000 || *id>100000000)
	{
		printf("**请按照格式输入数字学号**\n");
		printf("********学号为8位数*******\n");
		scanf("%*[^\n]");
		scanf("%d",id);
		xuehaogeshi(id);
	}
}

void menu1()
{
	printf("********请输入姓名********\n");
}

void menu2()
{
	printf("********请输入学号********\n");
}

void menu3()
{
	printf("********请输入地址********\n");
}

void menu4()
{
	printf("**************************\n");
	printf("*       请输入性别       *\n");
	printf("*          1:男          *\n");
	printf("*          2:女          *\n");
	printf("**************************\n");
}

void menu5()
{
	printf("********请输入年龄********\n");
}

void menu6()
{
	printf("********请输入成绩*********\n");
}

//清空 初始化
void clear(pnode* phead)
{
	//遍历删除
	pnode ploc=*phead;
	while(ploc!=NULL)
	{
		*phead=(*phead)->next;
		free(ploc);	//释放
		ploc=*phead;
	}
}
//求学生数量
unsigned int lenth(pnode phead)
{
	unsigned int i=0;
	while(phead!=NULL)
	{
		i++;
		phead=phead->next;
	}
	return i;
}

//学号升序排序
void xuehaopaixu1(pnode pHead)
{
student stu={0};
	if (pHead==NULL)
		return;
	pnode pHead1,pHead2,pHead3;
	for (pHead1=pHead;pHead1->next!=NULL;pHead1=pHead1->next)
	{
		pHead3=pHead1;
		for(pHead2=pHead1->next;pHead2->next!=NULL;pHead2=pHead2->next)
		{
			if (pHead2->next->s.id<pHead3->s.id)
			{
				pHead3=pHead2->next;
			}
		}
		if(pHead3!=pHead1)
		{
			stu=pHead3->s;
			pHead3->s=pHead1->s;
			pHead1->s=stu;	
		}
	}
}

//成绩升序排序
void chengjipaixu1(pnode pHead)
{
student stu={0};
	if (pHead==NULL)
		return;
	pnode pHead1,pHead2,pHead3;
	for (pHead1=pHead;pHead1->next!=NULL;pHead1=pHead1->next)
	{
		pHead3=pHead1;
		for(pHead2=pHead1->next;pHead2->next!=NULL;pHead2=pHead2->next)
		{
			if (pHead2->next->s.num<pHead3->s.num)
			{
				pHead3=pHead2->next;
			}
		}
		if(pHead3!=pHead1)
		{
			stu=pHead3->s;
			pHead3->s=pHead1->s;
			pHead1->s=stu;	
		}
	}
}

//姓名升序排序
void xingmingpaixu1(pnode pHead)
{
	student stu={0};
	if (pHead==NULL)
		return;
	pnode pHead1,pHead2,pHead3;
	for (pHead1=pHead;pHead1->next!=NULL;pHead1=pHead1->next)
	{
		pHead3=pHead1;
		for(pHead2=pHead1->next;pHead2->next!=NULL;pHead2=pHead2->next)
		{
			if (strcmp(pHead2->next->s.name,pHead3->s.name)<0)
			{
				pHead3=pHead2->next;
			}
		}
		if(pHead3!=pHead1)
		{
			stu=pHead3->s;
			pHead3->s=pHead1->s;
			pHead1->s=stu;	
		}
	}
}

//学号降序排序
void xuehaopaixu2(pnode pHead)
{
student stu={0};
	if (pHead==NULL)
		return;
	pnode pHead1,pHead2,pHead3;
	for (pHead1=pHead;pHead1->next!=NULL;pHead1=pHead1->next)
	{
		pHead3=pHead1;
		for(pHead2=pHead1->next;pHead2->next!=NULL;pHead2=pHead2->next)
		{
			if (pHead2->next->s.id>pHead3->s.id)
			{
				pHead3=pHead2->next;
			}
		}
		if(pHead3!=pHead1)
		{
			stu=pHead3->s;
			pHead3->s=pHead1->s;
			pHead1->s=stu;	
		}
	}
}

//成绩降序排序
void chengjipaixu2(pnode pHead)
{
student stu={0};
	if (pHead==NULL)
		return;
	pnode pHead1,pHead2,pHead3;
	for (pHead1=pHead;pHead1->next!=NULL;pHead1=pHead1->next)
	{
		pHead3=pHead1;
		for(pHead2=pHead1->next;pHead2->next!=NULL;pHead2=pHead2->next)
		{
			if (pHead2->next->s.num>pHead3->s.num)
			{
				pHead3=pHead2->next;
			}
		}
		if(pHead3!=pHead1)
		{
			stu=pHead3->s;
			pHead3->s=pHead1->s;
			pHead1->s=stu;	
		}
	}
}

//姓名降序排序
void xingmingpaixu2(pnode pHead)
{
	student stu={0};
	if (pHead==NULL)
		return;
	pnode pHead1,pHead2,pHead3;
	for (pHead1=pHead;pHead1->next!=NULL;pHead1=pHead1->next)
	{
		pHead3=pHead1;
		for(pHead2=pHead1->next;pHead2->next!=NULL;pHead2=pHead2->next)
		{
			if (strcmp(pHead2->next->s.name,pHead3->s.name)>0)
			{
				pHead3=pHead2->next;
			}
		}
		if(pHead3!=pHead1)
		{
			stu=pHead3->s;
			pHead3->s=pHead1->s;
			pHead1->s=stu;	
		}
	}
}
void menu8()
{
			printf("*********输入错误*********\n");
			printf("*********重新输入*********\n");
}
//按0返回上一层
void fanhui(int flag)
{
	printf("**************************\n");
	printf("*      按0返回上一层     *\n");
	printf("**************************\n");
	while(flag!=0)
	{
		scanf("%d",&flag);
		if(flag!=0)
		{
			menu8();
		}else
		{
			return;
		}
	}
}

//求最高分
int maxnum(pnode phead)
{
	pnode ploc=phead;
	int maxnum=phead->s.num;
	while(ploc!=NULL)
	{
		if(maxnum<ploc->s.num)
		{
			maxnum=ploc->s.num;
		}
		ploc=ploc->next;
	}
	return maxnum;
}

//性别判断
void mysex(char* sex,int opr)
{
					if(opr==1)
					{
						strcpy(sex,"男");
						return;
					}
					else if(opr==2)
					{
						strcpy(sex,"女");
						return;
					}
					else
					{
						menu8();
		scanf("%*[^\n]");
						scanf("%d",&opr);
						mysex(sex,opr);
					}
}

//年龄判断
void myage(short* age)
{
	if(*age>10 && *age<30)
	{
		return;
	}
	if(*age<10 ||*age>30)
	{
		menu8();
		printf("*******年龄为10-30********\n");
		scanf("%*[^\n]");
		scanf("%hd",age);
		myage(age);
	}
}

//成绩判断
void score(int* num)
{
	if(*num>=0&&*num<=100)
	{
		return;
	}
	if(*num<0||*num>100)
	{
		printf("输入错误\n");
		menu8();
		printf("*******成绩为0-100*******\n");
		scanf("%*[^\n]");
		scanf("%d",num);
		score(num);
	}
}

void menu9()
{
			printf("**************************\n");
			printf("*        查找成功        *\n");
			printf("*        是否打印        *\n");
			printf("*          1:是          *\n");
			printf("*          2:否          *\n");
			printf("**************************\n");
}

//查找学号打印
void chazhaodayin(pnode phead,int id)
{			
			int i,j;
					scanf("%*[^\n]");
			scanf("%d",&i);
			if(i==1)
			{
			show1(phead,id);
			j=1;
			fanhui(j);
			}
			else if(i!=1&&i!=2)
			{
				menu8();
				chazhaodayin(phead,id);
			}
			else
				return;
}

//查找成绩打印
void chazhaodayin1(pnode phead,int num)
{
	pnode ploc=phead;
	int i,j;
					scanf("%*[^\n]");
	scanf("%d",&i);
	if(i==1)
	{
		while(ploc!=NULL)
		{
			if(ploc->s.num==num)
			{
				 printf("****************************\n");
			         printf("*         学号:%d          *\n",ploc->s.id);
	      	  		 printf("*         姓名:%s          *\n",ploc->s.name);
  			         printf("*         地址:%s          *\n",ploc->s.addr);
			         printf("*         性别:%s          *\n",ploc->s.sex);
			         printf("*         年龄:%hd         *\n",ploc->s.age);
	       			 printf("*         成绩:%d          *\n",ploc->s.num);
			         printf("****************************\n");
			}
			ploc=ploc->next;
		}
		i=1;
		fanhui(i);
	}
	else if(i==2)
	{
		return;
	}
/*	else if(i==0)
	{
		j=0;
		fanhui(j);
	}*/
	else
	{
			menu8(); 
					scanf("%*[^\n]");
                        scanf("%d",&i);
			chazhaodayin1(phead,num);
	}
}

//学生信息录入
void xinxiluru(pstudent ps,pnode* phead)
{
					int j;		
					menu2();
					scanf("%*[^\n]");
					scanf("%d",&(ps->id));
					xuehaogeshi(&(ps->id));
					if(*phead!=NULL)
					repeat(*phead,&(ps->id));
					menu1();
					scanf("%s",ps->name);
					menu3();
					scanf("%s",ps->addr);
					menu4();
					scanf("%*[^\n]");
					scanf("%d",&j);
					mysex(ps->sex,j);
					menu5();
					scanf("%*[^\n]");
					scanf("%hd",&(ps->age));
					myage(&(ps->age));
					menu6();
					scanf("%*[^\n]");
					scanf("%d",&(ps->num));
					printf("%d\n",ps->num);
					score(&(ps->num));
}

void menu10()
{
		printf("**************************\n");
		printf("* 请选择升序还是降序排序 *\n");
		printf("*         1:升序         *\n");
		printf("*         2:降序         *\n");
		printf("**************************\n");
}

//调用排序
void diaoyongpaixu(pnode phead,int opr)
{
	int i;
	if(opr==1)
	{
		menu10();
					scanf("%*[^\n]");
		scanf("%d",&i);
		if(i==1)
		{
			xuehaopaixu1(phead);
		}
		else if(i==2)
		{
			xuehaopaixu2(phead);
		}
		else
		{
			menu8();
			diaoyongpaixu(phead,opr);
		}	
	}
	else if(opr==2)
	{
		menu10();
					scanf("%*[^\n]");
                scanf("%d",&i);
                if(i==1)
                {
                        chengjipaixu1(phead);
                }
                else if(i==2)
                {
                        chengjipaixu2(phead);
                }  
                else
                {
                        menu8();
                        diaoyongpaixu(phead,opr);
                }
	}
	else if(opr==3)
	{
		menu10();
					scanf("%*[^\n]");
                scanf("%d",&i);
                if(i==1)
                {
                        xingmingpaixu1(phead);
                }
                else if(i==2)
                {
                        xingmingpaixu2(phead);
                }
                else
                {
                        menu8();
                        diaoyongpaixu(phead,opr);
                }
	}
	else if(opr==4)
	{
		return;
	}
	else
	{
		menu8();
					scanf("%*[^\n]");
		scanf("%d",&opr);
		diaoyongpaixu(phead,opr);
	}
}

//改变信息
void xinxichange(pnode* phead)
{
	int id,j;
	student s={0};
	pstudent ps=&s;
					scanf("%*[^\n]");
			scanf("%d",&id);
						xuehaogeshi(&s.id);
						if(find(s.id,*phead))
						{
							printf("***请输入改变后的学生信息***\n");
							xinxiluru(ps,phead);
							if(change(id,&s,*phead))
							{
								printf("*********改变成功*********\n");
							fanhui(1);
							}
							else
							{
								printf("*********改变失败*********\n");
								fanhui(1);
							}
						}
						else
						{
								printf("********学号不存在*******\n");
								printf("********请重新输入*******\n");
								xinxichange(phead);
						}
}

//初始化判断
void clearpanduan(int *i)
{
	if( *i==1 || *i==0)
	{
		return;
	}
	else
	{
		menu8();
					scanf("%*[^\n]");
		scanf("%d",i);
		clearpanduan(i);
	}
}

//1:添加学生
void addstudent(pstudent ps,pnode*phead)
{
					system("clear");
					xinxiluru(ps,phead);
					if(add(*ps,phead))
					{
						printf("*********添加成功*********\n");
					}	
					else
					{
						printf("*********添加失败*********\n");
					}
						fanhui(1);
}

//2删除学生
void deletestudent(pstudent ps,pnode* phead)
{
system("clear");
					printf("*请输入要删除的学生的学号*\n");
					scanf("%*[^\n]");
					scanf("%d",&(ps->id));
					xuehaogeshi(&ps->id);
					if(delete(ps->id,phead))
					{
						printf("*********删除成功*********\n");
					}
					else
					{
						printf("*********删除失败*********\n");
						printf("********不存在此人********\n");
					}
						fanhui(1);
}
//3:查找学生
void findstudent(pstudent ps,pnode phead)
{
system("clear");
					printf("*请输入要查找的学生的学号*\n");
					scanf("%*[^\n]");
					scanf("%d",&ps->id);
					xuehaogeshi(&ps->id);
					if(find(ps->id,phead))
					{ 
						menu9();
						chazhaodayin(phead,ps->id);
					}
					else
					{
						printf("*********查找失败*********\n");
						printf("********不存在此人********\n");
						fanhui(1);
					}
}

//4:查找最高分
void findmax(pnode phead)
{
						system("clear");
						if(phead==NULL)
						{
						printf("********无学生成绩********\n");
						}
						else
						{
						int num=maxnum(phead);
						printf("*       最高分为:%d      *\n",num);
						printf("**************************\n");
						printf("*     是否打印学生信息    *\n");
						printf("*          1:是          *\n");
						printf("*          2:否          *\n");
						printf("**************************\n");
						chazhaodayin1(phead,num);
						}
}

//5:改变学生信息
void changestudent(pnode* phead)
{
				system("clear");
				printf("*请输入需要改变的学生的学号*\n");
				xinxichange(phead);
}

//6:对学生排序
void sortstudent(pnode phead)
{
int i;
						system("clear");
						printf("**************************\n");
						printf("*     1:按照学号排序     *\n");
						printf("*     2:按照成绩排序     *\n");
						printf("*     3:按照姓名排序     *\n");
						printf("*      4:返回上一层      *\n");
						printf("**************************\n");
					scanf("%*[^\n]");
						scanf("%d",&i);
						diaoyongpaixu(phead,i);
						printf("*********排序成功*********\n");
						fanhui(1);
}

//7:求学生数量
void studentnum(pnode phead)
{
					system("clear");
					printf("********学生数量:%d********\n",lenth(phead));
					fanhui(1);
}

//8:初始化系统
void clearsystem(pnode* phead)
{
					int i;
					printf("**************************\n");
					printf("*    你确定要初始化吗    *\n");
					printf("*         1:确定         *\n");
					printf("*      0:返回上一层      *\n");
					printf("**************************\n");
					scanf("%d",&i);
					clearpanduan(&i);
					if(i==1)
					{
						clear(phead);
						printf("********初始化成功********\n");
					fanhui(1);
					}
}

//9:写入文件
void writefile(pnode phead)
{					
					FILE* fp=fopen("./a.txt","wb");
					if(NULL==fp)
					{
						printf("******打开文件失败*******\n");
						return;
					}
					pnode p=phead;
					for(p;p!=NULL;p=p->next)
					{
						fwrite(p,sizeof(student),1,fp);
//							fseek(fp,1,SEEK_CUR);
					}	
							fclose(fp);
							system("clear");
							printf("********写入成功********");
					fanhui(1);	
}

//10:读取文件
void readfile(pnode* phead)
{
				int i;
				FILE* fp1=fopen("./a.txt","rb");
				if(NULL==fp1)
				{
					printf("******打开文件失败*******\n");
					return;
				}
				i=0;
				student s={0};
				pnode ploc=*phead;
				while(fread(&s,sizeof(student),1,fp1)>0)
				{
					add(s,phead);
				}
				fclose(fp1);
				system("clear");
				printf("*********读取成功*********");
				fanhui(1);
}

//11:打印学生信息
void dayinstudent(pnode phead)
{
			printf("*************************\n");
			printf("*      选择打印方式     *\n");
			printf("*   1:打印全部学生信息  *\n");
			printf("*   2:打印指定学生信息  *\n");
			printf("*     0:返回上一层      *\n");
			printf("*************************\n");
			int i,id,j;
				scanf("%d",&i);
				if(i==1)
				{
					show(phead);
					fanhui(1);
				}
				else if(i==2)
				{
					printf("*****请输入指定学生学号*****\n");
					scanf("%*[^\n]");
					scanf("%d",&id);
					if(find(id,phead))
					{
						show1(phead,id);
					}
					else
					{
						printf("********不存在此人********\n");
					}
					fanhui(1);
				}
				else if(i==0)
				{
					return;
				}
				else
				{
					menu8();
					dayinstudent(phead);
				}
}

//12:查询指定学生排名
void findpaiming(pnode phead)
{
	int num,id,i=-1;
	printf("***请输入要查找的学生学号***\n");
					scanf("%*[^\n]");
	scanf("%d",&id);
	if(find(id,phead))
	{
		i=1;
		pnode ploc=phead;
		while(ploc!=NULL)
		{
			if(ploc->s.id==id)
			{
				num=ploc->s.num;
			}
			ploc=ploc->next;
		}
		pnode ploc1=phead;
		while(ploc1!=NULL)
		{
			if(num<ploc1->s.num)
				i++;
			ploc1=ploc1->next;
		}
	}
		if(i==-1)
		{
			printf("******该学生不存在*******\n");
		}
		else
		{
			printf("*****该学生排名为:%d******\n",i);
		}
		fanhui(1);
}

//13:平均分
void pingjun(pnode phead)
{
	int num=0,i=0;
	pnode ploc=phead;
	if(phead==NULL)
	{
		printf("*****还未录入成绩*****\n");
		fanhui(1);
		return;
	}
	while(ploc!=NULL)
	{
		i++;
		num+=ploc->s.num;
		ploc=ploc->next;
	}
	printf("***我校学生平均分为:%5.2f分***\n",num/(float)i);
	fanhui(1);
}

//教师端
void choice(pnode* phead)
{
	int flag=1;
	student s={0};
	pstudent ps=&s;
	int id;
	char name[10];
	int opr,i,j=1;
	while(flag==1)
	{
		system("clear");
		printf("***********************************************\n");
		printf("*             学生管理系统---教师端           *\n");
		printf("*                  1:添加学生                 *\n");
		printf("*                  2:删除学生                 *\n");
		printf("*                  3:查找学生                 *\n");
		printf("*                 4:查找最高分                *\n");
		printf("*                5:改变学生信息               *\n");
		printf("*                 6:对学生排序                *\n");
		printf("*                 7:求学生数量                *\n");
		printf("*                 8:初始化系统                *\n");
		printf("*                  9:写入文件                 *\n");
		printf("*                 10:读取文件                 *\n");
		printf("*               11:打印学生信息               *\n");
		printf("*             12:查询指定学生排名             *\n");
		printf("*                 13:查询平均分               *\n");
		printf("*                 0:返回上一层                *\n");
		printf("***********************************************\n");
		scanf("%d",&opr);
		switch(opr)
		{
			case 0:
				flag=0;
				break;
	  		case 1:
				{
					addstudent(ps,phead);
				}
				break;
			case 2:
				{
					deletestudent(ps,phead);
				}
				break;
			case 3:
				{
					findstudent(ps,*phead);
				}
				break;
			case 4:
				{
					findmax(*phead);
				}
				break;
			case 5:
				{
					changestudent(phead);	
				}
				break;
			case 6:
				{
					sortstudent(*phead);	
				}
				break;
			case 7:
				{	
					studentnum(*phead);	
				}
				break;
			case 8:
				{	
					clearsystem(phead);	
				}
				break;
			case 9:
				{
					writefile(*phead);
				}
				break;
			case 10:
				{
					readfile(phead);
				}
				break;
			case 11:{	
					dayinstudent(*phead);
				}
				break;
			case 12:
				{
					findpaiming(*phead);
				}
				break;
			case 13:
				{
					pingjun(*phead);
				}
				break;
			default:
				{
					menu8();
					scanf("%*[^\n]");
					scanf("%d",&opr);
				}
				break;
		}	
	}
}

//学生端
void choice1(pnode* phead)
{
	int opr,flag;
	student s={0};
	pstudent ps=&s;
	while(flag==1)
	{
                  system("clear");
                  printf("***********************************************\n");
                  printf("*             学生管理系统---学生端           *\n");
                  printf("*                  1:查找学生                 *\n");
                  printf("*                 2:查找最高分                *\n");
		  printf("*                 3:查询平均分                *\n");
		  printf("*                  4:读取文件                 *\n");
                  printf("*                 0:返回上一层                *\n");
                  printf("***********************************************\n");
		scanf("%d",&opr);
		switch(opr)
		{
			case 0:
				flag=0;
				break;
	  		case 1:
				{
					findstudent(ps,*phead);
				}
				break;
			case 2:
				{
					findmax(*phead);
				}
				break;
			case 3:
				{
					pingjun(*phead);
				}
				break;
			case 4:
				{
					readfile(phead);
			       }
				break;
			default:
				break;
		}
	}
}

//密码
int serect(char * buf)
{
	int i=3,p=0;
	char ch1[]={"123456"};
	char ch2[]={"1234567"};
	char input1[20]={0};
	char pwd[255]="";
	char ch;
	while (i)
	{
		printf("*********请输入你的登录账号*********:\n");
		scanf("%s",input1);
		printf("*********请输入你的登录密码*********:\n");
		strcpy(pwd,getpass(""));
/*		while((ch=getchar())!='\r') 
        	{ 	 
        	    if((ch<'9' && ch>'0') || (ch<'Z'&&ch>'A') || (ch<'z'&&ch>'a'))	//判断是否是数字或字符  
		    {
        	    	putchar('*');
        	    	pwd[p++]=ch;
		    }
       		 } 
		*/ 
		if(strcmp(input1,buf)==0)
		{
			if(strcmp(buf,"yao")==0)
			{
				if(strcmp(ch1,pwd)==0)
				{
					return 0;
				}
			}
			if(strcmp(buf,"qian")==0)
			{
				if(strcmp(ch2,pwd)==0)
				{
					return 0;
				}
			}
		}
			i--;
			printf("****账号或密码错误,剩余尝试次数:%d****\n",i+1);
	}
	if(i == 0)
	{
		return(-1);
	}
}

//登录
void login(int i,int* flag)
{
	if(i==1)
	{
		int num=serect("yao");
    		if(num==0)
   		{
        		printf("**************登录成功!**************\n");
			printf("*************任意键继续**************\n");
			sleep(1);
			system("pause");

    		}	
    		else if(num==-1)
   	 	{	
       	 		printf("***输入次数已经用尽，系统将自动退出***\n");
			printf("*************任意键继续**************\n");
			*flag=0;
    		}
	}
	if(i==2)
	{
		int num=serect("qian");
		if(num==0)
                {
                        printf("**************登录成功!**************\n");
			printf("*************任意键继续**************\n");
			system("pause");
			sleep(1);

                }
                else if(num==-1)
                {
                        printf("***输入次数已经用尽，系统将自动退出***\n");
			printf("*************任意键继续**************\n");
                        *flag=0;
                }
	}

}

void main()
{
	int flag=1;
	while(flag==1)
	{
		system("clear");
        printf("***********************************************\n"); 
	printf("*         学生管理系统---登录客户端           *\n");
        printf("*                  1:教师端                   *\n");
        printf("*                  2:学生端	              *\n");
     	printf("*                 0:退出系统                  *\n");
        printf("***********************************************\n");
	int opr;
	scanf("%d",&opr);
	if(opr==1)
	{
		login(1,&flag);
		pnode head=creat();
		choice(&head);
	}
	else if(opr==2)
	{
		login(2,&flag);
		pnode head=creat();
		choice1(&head);
	}
	else if(opr==0)
	{
		return;
	}
	else
	{
		menu8();
		fanhui(1);
	}
	}
}
