#include<stdio.h>
#include<time.h>
#include<stdlib.h>

clock_t clock(void);
void main()
{
	clock_t start,finish;
	int time;
	//测量一个事件持续的时间
	start=clock();
	int a=0;
	finish=clock();
	time=(int)(finish-start);
	printf("耗时:%dms\n",time);
}

