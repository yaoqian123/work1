#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sort(int *a, int left, int right)
{
    if(left >= right)			//退出条件
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];			//初始key
    while(i < j)                            
    {
        while(i < j && key <= a[j])	//从右边向左边找比key小的值放在之前i的位置
        {
            j--;
        }
        a[i] = a[j];
        while(i < j && key >= a[i])	//从左边向右边找比key大的值放在j的位置
        {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = key;				//把key值回归
    sort(a, left, i - 1);		//重复排序i左边的数组
    sort(a, i + 1, right);		//重复排序i右边的数组
}
void main()
{
	float time=0,start=0,finish=0;
	int len,i=0,j=0;
	printf("请输入数组长度:");
	scanf("%d",&len);
	int *a=(int *)malloc(sizeof(int)*len);	//申请内存空间
	for(j=0;j<len;j++)
	{
		a[j]=rand();
	}
//	int a[10]={9,1,8,2,7,3,6,4,5,10};
	start=clock();
	sort(a,0,9);
	finish=clock();
	time=(finish-start)/CLOCKS_PER_SEC;
	printf("耗时%fs\n",time);
//	for(int i=0;i<10;i++)
//		printf("%d\n",a[i]);
	free(a);
}
