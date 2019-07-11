//连续输入10个数比大小
#include<stdio.h>

void main()
{
	int a=0;
	scanf("%d",&a);
	int big=a;
	for(int i=0;i<9;i++)
	{
		scanf("%d",&a);
		if(big<a)
		big=a;
	}
	printf("%d\n",big);
}
