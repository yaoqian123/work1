//通过指针将0移动到数组末尾,其余元素保持不变
#include<stdio.h>

void main()
{
	int buf[10]={0,2,4,0,3,5,0,3,9,0};
	char* pbuf=(char *)buf;
	int i=0,j=0;
	for(i=0;i<10;i++)
	{
		if(*(buf+i)!=0)
		{
			*(buf+j)=*(buf+i);
			j++;
		}
	}
	while(j<10)
		*(buf+j++)=0;
	for(i=0;i<10;i++)
		printf("%d ",*(buf+i));
}
