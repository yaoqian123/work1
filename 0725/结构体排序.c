#include<stdio.h>
#include<string.h>
struct person
{
	char name[10];
	int age;
};
void main()
{
	int i=0,j=0,flag=0,num=0,mid=0;
	char key[10]="";
	scanf("%s",key);
	struct person s[10]=
	{{"a",20},{"b",19},{"c",18},{"d",17},{"e",16},{"f",15},
{"g",14},{"h",13},{"i",12},{"j",11}};
	for(i=0;i<10;i++)
	{
		for(j=0;j<10-i-1;j++)
		{
			flag=0;
			if(s[j].age>s[j+1].age)
			{
				mid=s[j].age;
				s[j].age=s[j+1].age;
				s[j+1].age=mid;
				flag=1;
			}
			if(flag==0)
				break;
		}
	}
	flag=0;
	for(i=0;i<10;i++)
	printf("%d",s[i].age);
	printf("\n");
	for(i=0;i<10;i++)
	{
		if(strcmp(key,s[i].name)==0)
		{
			printf("存在!\n");
			flag=1;
		}
	}
	if(flag==0)
	printf("不存在!\n");
	for(i=0;i<10;i++)
	num+=s[i].age;
	printf("%d\n",num/10);
}
