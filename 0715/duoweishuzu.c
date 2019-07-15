//多维数组
#include<stdio.h>

void main()
{
	//二维数组:
	int score[3][5]={{11,12,13,14,15},{21,22,23,24,25},{31,32,33,34,35}};
	//sizeof()是运算符
	//printf("%d\n",sizeof(score));
	//引用
  	for(int i=0;i<3;i++)
	{
		for(int j=0;j<5;j++)
		{
			printf("%d\t",score[i][j]);
		}
		printf("\n");
	}
	int i=0,j=0;
	while(i<3)
	{
		while(j<5)
		{
			printf("%d\t",score[i][j]);
			j++;
		}
		printf("\n");
		j=0;
		i++;
	}
}
