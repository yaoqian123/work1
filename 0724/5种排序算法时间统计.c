#include<stdio.h>
#include<time.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

clock_t clock(void);
int rand(void);

void maopao(int *b,int n)
{
	int i=0,j=0,mid=0,flag=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			flag=0;
			if(b[j]>b[j+1])
			{
				mid=b[j];
				b[j]=b[j+1];
				b[j+1]=mid;
				flag=1;
			}
			if(flag==0)
				break;
		}
	}
}

void xuanze(int *b,int n)
{
	int i=0,j=0,mid=0,lis=0;
	for(i=0;i<n;i++)
	{
		lis=i;
		for(j=i+1;j<n;j++)
		{
			if(b[j]<b[lis])
			{
				lis=j;
			}
		}
		if(lis!=i)
{
			mid=b[lis];
			b[lis]=b[i];
			b[i]=mid;
		}
	}
}

void charu(int *b,int n)
{
	int i=0,j=0,mid=0;
	for(i=0;i<10;i++)
	{
		mid=b[i];
		for(j=i-1;j>=0;j--)	
		{
			if(mid<b[j])
				b[j+1]=b[j];
			else
				break;
		}
		b[j+1]=mid;
	}
}

void shell(int *a,int n)
{
	int i=0,j=0,temp=0,gap=0;
	while(gap<=n)
		gap=gap*3+1;
	while(gap>0)
	{
		for(i=gap;i<n;i++)
		{
			j=i-gap;
			temp=a[i];
			while((j>=0)&&(a[j]>temp))
			{
				a[j+gap]=a[j];
				j=j-gap;
			}
			a[j+gap]=temp;
		}
		gap=(gap-1)/3;
	}
}
void kuaisu(int *a, int left, int right)
{
    if(left >= right)                   //退出条件
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];                  //初始key
    while(i < j)
    {
        while(i < j && key <= a[j])     //从右边向左边找比key小的值放在之前i的位置
        {
            j--;
        }
        a[i] = a[j];
        while(i < j && key >= a[i])     //从左边向右边找比key大的值放在j的位置
        {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = key;                         //把key值回归
    kuaisu(a, left, i - 1);               //重复排序i左边的数组
    kuaisu(a, i + 1, right);              //重复排序i右边的数组
}

void main()
{
	int i=0,j=0;float time[5]={0};
	float start[5]={0},finish[5]={0};	
	int len=0;
	printf("请输入数组长度:");
	scanf("%d",&len);
	for(i=0;i<5;i++)
	{	
//		int a[10]={9,8,7,6,5,4,3,2,1,0};
//		len=10;
		int *a=(int *)malloc(sizeof(int)*len);	//申请内存空间
		for(j=0;j<len;j++)
		{
			a[j]=rand();
		}
	//	for(j=0;j<len;j++)
	//	printf("%d\n",a[j]);
		switch(i)
		{
			case 0:{
					start[0]=clock();
					maopao(a,len);
					finish[0]=clock();
					printf("冒泡");
			       }break;
			case 1:{
					start[1]=clock();
					xuanze(a,len);
					finish[1]=clock();
					printf("选择");
			       }break;
			case 2:{
					start[2]=clock();
					charu(a,len);
					finish[2]=clock();
		       		        printf("插入");
			       }break;
			case 3:{
					start[3]=clock();
				 	shell(a,len);
					finish[3]=clock();
					printf("希尔");	
			       }break;
			case 4:{
					start[4]=clock();
				 	kuaisu(a,0,len-1);
					finish[4]=clock();
					printf("快速排序");	
			       }break;
			default:
			       break;
		}
		time[i]=(finish[i]-start[i])/CLOCKS_PER_SEC;
		printf("算法耗时:%fs\n",time[i]);
//		for(j=0;j<len;j++)
//		printf("%d ",a[j]);
//		printf("\n");
		free(a);
	}
}
