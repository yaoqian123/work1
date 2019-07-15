#include<stdio.h>

void main()
{
	int i=0,j=0;
	int buf[5][5]={{5,4,3,2,1},{10,9,8,7,6},{15,14,13,12,11},{20,19,18,17,16},{25,24,23,22,21}};
/*	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("请输入第%d班第%d位同学的成绩:",i+1,j+1);
			scanf("%d",&buf[i][j]);
		}
	}*/
	int key=0,flag=0;
	printf("请输入要查找的值:");
	scanf("%d",&key);
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(key==buf[i][j])
			{
				printf("该值存在!");
				flag=1;
			}
		}
	}
	if(flag==0)
		printf("该值不存在");
	int lin=0;
	//以班级为单位排序
	for(i=0;i<5;i++)
	{
		printf("第%d个班级成绩排序为:",i+1);
		for(j=0;j<5;j++)
		{
			lin=j;
			for(int k=j+1;k<5;k++)
			{
				if(buf[i][lin]<buf[i][k])
				{
					lin=k;
				}
				int mid=buf[i][lin];
				buf[i][lin]=buf[i][k];
				buf[i][k]=mid;
			}
			printf("%d\t",buf[i][j]);
		}
		printf("\n");		
	}
	//以年级为单位排序
	int x=0,c=0,v=0,b=0;
	for(i=0;i<25;i++)
	{
		x=i/5;
		c=i%5;
		for(j=i+1;j<25;j++)
		{
			v=j/5;
			b=j%5;
			if(buf[x][c]>buf[v][b])
			{
			int mi=buf[x][c];
			buf[x][c]=buf[v][b];
			buf[v][b]=mi;
			}
		}	
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			printf("%d\t",buf[i][j]);
	}
	
	
}
