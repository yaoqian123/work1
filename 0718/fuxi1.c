#include<stdio.h>

void main()
{
	char* name[6]={"zhao","qian","sun","li","wang",NULL};
	//选择法
	short listen,i,j;//最大的索引
	for(i=0;*(name+i)!=NULL;i++)
	{
		listen=i;
		for(j=i+1;*(name+j)!=NULL;j++)
		{
			if(**(name+listen)<name[j][0])
			{
				listen=j;
			}
			if(i!=listen)
			{
				char* pch=*(name+i);
				*(name+i)=name[listen];
				name[listen]=pch;
			}
		}
	}
	for(i=0;name[i]!=NULL;i++)
		printf("%s\n",*(name+i));
}
