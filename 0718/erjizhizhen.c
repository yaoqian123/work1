//选择排序对二维组用二级指针排序
#include<stdio.h>

void main()
{
	char a[3][4]={{1,2,3,4},{11,12,12,13},{21,22,23,24}};
	char (*pa)[4]=a;
	int i=0,j=0,flag=a[0][0],fla=a[0][0];
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			int lis=j;
			for(int z=j+1;z<4;z++)
			{
				if((*(*(pa+i)+z))>(*(*(pa+i)+lis)))
					lis=z;
			}
			if(lis!=j)
			{
				int b=*(*(pa+i)+j);
				*(*(pa+i)+j)=*(*(pa+i)+lis);
				*(*(pa+i)+lis)=b;
			}
		}
	}
	for(i=0;i<3;i++)
	{
		printf("第%d个班级最好成绩为%d:\n",i+1,*(*(pa+i)));
		for(j=0;j<4;j++)
			printf("%d ",*(*(pa+i)+j));
		printf("\n");
	}
	printf("\n");
	char *pb=(char *)a;
	for(i=0;i<12;i++)
	{
		int lin=i;
		for(j=i+1;j<12;j++)
		{
			if(*(pb+j)>*(pb+lin))
			{
				lin=j;
			}
		}
		if(lin!=i)
		{
			int c=*(pb+i);
			*(pb+i)=*(pb+lin);
			*(pb+lin)=c;
		}
	}
	printf("全校最好成绩为%d\n",*pb);
	for(i=0;i<12;i++)
		printf("%d ",*(pb+i));
	printf("\n");
}
