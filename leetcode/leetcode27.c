//删除数组中指定元素
#include<stdio.h>

void main()
{
	int buf[10]={0,1,1,2,2,3,3,4,4,0};
	int val=0,i=0,j=0;
	scanf("%d",&val);
/*	for(i=0;i<10;i++)
	{
		if(buf[i]!=val)
		{
			buf[j]=buf[i];
			j++;
		}
	}
	for(i=0;i<j;i++)
		printf("%d ",buf[i]);*/
//优化解  当数组元素较少可以减少元素移动
	int n=10;
	i=0;
	while(i<n)
	{
		if(buf[i]==val)
		{
			buf[i]=buf[n-1];	//将相同元素放到数组末尾  再次遍历i
			n--;
		}else{
			i++;
		}
	}
	for(i=0;i<n;i++)
	printf("%d",buf[i]);
}

