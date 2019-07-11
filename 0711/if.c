#include<stdio.h>

void main()
{
	int num;
	int i;
	printf("请输入成绩:\n");
	scanf("%d",&num);
	if(num<=100 && num>=80)
	{
		i=0;
	}
	else if(num<80 && num>=60)
	{
		i=1;
	}
	else if(num<60 && num >=0)
	 {
	 	 i=2;
	 }
	else {
		printf("输入了错误的成绩!");
	}
	switch(i)
	{
		case 0:
			{
				printf("成绩优秀!");
			}
			break;
		case 1:
			
			{
				printf("成绩良好!");
			}
			break;
		case 2:
			{
				printf("成绩不及格!");
			}
			break;
		default:
			break;
	}
}
