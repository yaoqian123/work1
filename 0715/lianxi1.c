#include<stdio.h>

void main()
{
	int i=0,j=0;
	int a[4][5]={{81,74,65,75,93},{45,21,68,75,14},{56,67,89,14,94},{100,45,56,34,85}};
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("请输入第%d个班的第%d位学生成绩:",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	printf("第一题:");
	for(j=0;j<5;j++)
	{
		printf("%d\t",a[3][j]);
	}
	printf("\n");

	printf("第二题:");
	for(j=4;j>=0;j--)
	{
		printf("%d\t",a[0][j]);
	}
	printf("\n");

	printf("第三题:");
	for(i=0;i<4;i++)
	{
		printf("%d\t",a[i][2]);
	}
	printf("\n");

	printf("第四题:");
	float b[4]={0,0,0,0};
	for(i=0;i<4;i++)
	{
		for(int j=0;j<5;j++)
		{
			b[i]=b[i]+a[i][j];
		}
	}
	for(i=0;i<4;i++)
	printf("第%d个班的平均分为%f:\n",i+1,b[i]/4);
	int max=b[0];
	for(i=1;i<4;i++)
	{
		if(max<b[i])
		{
			max=b[i];
		}
	}
	for(i=0;i<4;i++)
	{
		if(max == b[i])
		printf("第%d个班的平均分最高:\n",i+1);
	}
	printf("\n");

	printf("第五题:");
	max=a[0][0];
	int min=a[0][0];
	for(i=0;i<4;i++)
	{
		min=a[i][0];
		max=a[i][0];
		for(j=1;j<5;j++)
		{
			if(min>a[i][j])
				min=a[i][j];
			if(max<a[i][j])
				max=a[i][j];
		}
		printf("第%d个班的最高分为%d\t最低分为%d\n",i+1,max,min);
	}
	min=a[0][0];
	max=a[0][0];
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			if(min>a[i][j])
				min=a[i][j];
			if(max<a[i][j])
				max=a[i][j];
		}
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			if(max == a[i][j])
				printf("最高分在第%d个班:分数是%d\n",i+1,max);
			if(min == a[i][j])
				printf("最低分在第%d个班:分数是%d\n",i+1,min);
		}
	}
}
