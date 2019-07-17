#include<stdio.h>

void main()
{
	char buf[]="182930465";
	char* pch=buf;
	int i=sizeof(buf),j=0;
	for(i=sizeof(buf);i>=0;i--)
	{
		printf("%c %c %c %c\n",buf[i],pch[i],*(buf+i),*(pch+i));
	}
	for(i=0;i<sizeof(buf);i++)
	{
		for(j=0;j<sizeof(buf)-i-1;j++)
		{
			if(*(pch+j)<*(pch+j+1))
			{
				int mid=*(pch+j);
				*(pch+j)=*(pch+j+1);
				*(pch+j+1)=mid;
			}
		}
	}
	for(i=0;i<sizeof(buf);i++)
		printf("%c",*(pch+i));
	printf("\n");
}
