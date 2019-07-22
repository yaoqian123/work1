#include<stdio.h>
#include<time.h>
#include<malloc.h>
#include<stdlib.h>

clock_t clock(void);

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
	int i=0,j=0,mid=0,flag=0,lis=0;
	for(i=0;i<n;i++)
	{
		lis=i;
		for(j=i+1;j<n;j++)
		{
			if(b[j]<b[lis])
				lis=j;
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

void main()
{
	int i=0,j=0,time[4]={0};
	clock_t start[4]={0},finish[4]={0};	
	int len=0;
	for(i=0;i<4;i++)
	{	
//		int a[10]={9,8,7,6,5,4,3,2,1,0};
//		len=10;
		printf("请输入数组长度:");
		scanf("%d",&len);
		int *a=(int *)malloc(sizeof(int)*len);	//申请内存空间
		for(j=0;j<len;j++)
		{
		printf("输入数组内容:");
		scanf("%d",&a[j]);
		}
		for(j=0;j<len;j++)
		printf("%d\n",a[j]);
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
			default:
			       break;
		}
		time[i]=finish[i]-start[i];
		printf("算法耗时:%dms\n",time[i]);
		for(j=0;j<len;j++)
		printf("%d ",a[j]);
		printf("\n");
		free(a);
	}
}
