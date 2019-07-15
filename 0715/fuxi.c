#include<stdio.h>

void main()
{
	int i=0;
	int a[10]={5,4,2,54,78,354,231,45,21,34};
	for(i=0;i<10;i++)
	{
		printf("请输入数组中的第%d个元素:",i+1);
		scanf("%d",&a[i]);
	}
	int choice=0;
	printf("选择排序方法:\n");
	printf("1:冒泡\n");
	printf("2:插入\n");
	printf("3.选择\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		{
			for(i=0;i<10;i++)
			{
				for(int j=0;j<10-i-1;j++)
				{
					if(a[j]>a[j+1])
					{
						int mid=a[j];
						a[j]=a[j+1];
						a[j+1]=mid;
					}
				}
			}
		for(i=0;i<10;i++)
			printf("%d\n",a[i]);
		printf("最大值为%d",a[9]);
		}
		break;
	case 2:
		{
		for(i=1;i<10;i++)
		{
			int j=i-1;
			int temp=a[i];
			for(;j>=0;j--)
			{
				if(a[j]>temp)
				{
					a[j+1]=a[j];
				}else{
					break;
				}		
			}
			a[j+1]=temp;
		}			
		for(i=0;i<10;i++)
			printf("%d\n",a[i]);
		printf("最大值为%d",a[9]);
		}
		break;
	case 3:
		{
		for(i=0;i<10;i++)
		{
			int j=i+1;
			for(;j<10;j++)
			{
				if(a[i]>a[j])
				{
					int mid=a[i];
					a[i]=a[j];
					a[j]=mid;
				}
			}
		}
	
		for(i=0;i<10;i++)
			printf("%d\n",a[i]);
		printf("最大值为%d",a[9]);
		}
		break;
	default:
		break;
	}

}

