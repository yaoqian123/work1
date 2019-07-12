//基本排序算法练习
#include<stdio.h>

void main()
{
	int a[10]={0,0,0,0,0,0,0,0,0,0};
	for(int i=0;i<10;i++)
	{
		printf("请输入数组中第%d个元素:",i+1);
		scanf("%d",&a[i]);
	}
	printf("请选择排序算法:\n");
	printf("1:冒泡排序\n");         //稳定排序
	printf("2.插入排序\n");		//稳定排序
	printf("3.选择排序\n");		//不稳定排序
	int choice=0;
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{
				for(int z=0;z<10;z++)
				{
					int flag=0;  			//提前退出循环标志位:降低代码时间复杂度(优化)
					for(int x=0;x<10-z-1;x++)
					{
						if(a[x]>a[x+1])		//交换
						{
							int mid=a[x];
							a[x]=a[x+1];
							a[x+1]=mid;
							flag=1;		//有数据交换
						}
					}
					if(flag==0)
						break;
				}
				printf("请选择正序打印或者逆序打印:\n");
				printf("1.正序打印\n");
				printf("2.逆序打印\n");
				int cho=0;
				scanf("%d",&cho);
				if(cho==1)
				{
					printf("排序后依次输出为:\n");
					for(int c=0;c<10;c++)
						printf("%d\n",a[c]);
				}
				if(cho==2)
				{
					printf("排序后依次输出为:\n");
					for(int v=10;v>=0;v--)
						printf("%d\n",a[v]);
				}
			}
			break;
		case 2:
			{
				for(int z=1;z<10;z++)
				{
					int x=a[z];
					int j=z-1;
					for(j=z-1;j>=0;j--)				//寻找插入位置
					{
						if(a[j]>x)			//比较想要排序的数字之前的数字是否大于它
						{
							a[j+1]=a[j];		//数据移动 向后加一
						}else{
							break;
						}
					}
						a[j+1]=x;  				//插入数据
				}
				printf("请选择正序打印或者逆序打印:\n");
				printf("1.正序打印\n");
				printf("2.逆序打印\n");
				int cho=0;
				scanf("%d",&cho);
				if(cho==1)
				{
					printf("排序后依次输出为:\n");
					for(int c=0;c<10;c++)
						printf("%d\n",a[c]);
				}
				if(cho==2)
				{
					printf("排序后依次输出为:\n");
					for(int v=10;v>=0;v--)
						printf("%d\n",a[v]);
				}
			}
			break;
		case 3:
			{
				for(int z=0;z<10;z++)
				{
					int j=z+1;				//z为已排序  j为取最值
					for(j=z+1;j<10;j++)
					{
						if(a[z]>a[j])
						{
							int mid=a[z];
							a[z]=a[j];
							a[j]=mid;
						}
					}
				}
				printf("请选择正序打印或者逆序打印:\n");
				printf("1.正序打印\n");
				printf("2.逆序打印\n");
				int cho=0;
				scanf("%d",&cho);
				if(cho==1)
				{
					printf("排序后依次输出为:\n");
					for(int c=0;c<10;c++)
						printf("%d\n",a[c]);
				}
				if(cho==2)
				{
					printf("排序后依次输出为:\n");
					for(int v=10;v>=0;v--)
						printf("%d\n",a[v]);
				}
			}
			break;
		default:
			break;
	}
}
