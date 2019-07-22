#include<stdio.h>

void search(int *a,int key,int len)
{
	int flag=0;
	for(int i=0;i<len;i++)
	{
		if(a[i]==key)
		{
			printf("存在!下标为%d\n",i);
			flag=1;
		}
	}
	if(flag==0)
		printf("NULL");
}
void main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int key=0,len=10;
	scanf("%d",&key);
	search(a,key,len);
}
