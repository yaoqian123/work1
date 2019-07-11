//连续输入10个数比大小
#include<stdio.h>

void main()
{
	int big=0;
	int a;
	for(int i=0;i<10;i++)
	{
		scanf("%d",&a);
		if(big<a)
		big=a;
	}
	printf("%d\n",big);
}
