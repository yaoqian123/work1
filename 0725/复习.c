#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>
void kuaisu(int *a,int left,int right)
{
	while(left>=right)
		return;
	int i=left;
	int j=right;
	int key=a[left];
	while(i<j)
	{
		while(i<j && a[j]>=key)
			j--;
		a[i]=a[j];
		while(i<j && a[i]<=key)
			i++;
		a[j]=a[i];
	}
		a[i]=key;
		kuaisu(a,left,i-1);
		kuaisu(a,i+1,right);
}
void main()
{
	int len,i;
	printf("请输入数组长度:");
	scanf("%d",&len);
	int *a=(int *)malloc(sizeof(int)*len);
	for(i=0;i<len;i++)
		a[i]=rand();
	float t,s,f;
	s=clock();
	kuaisu(a,0,len-1);
	f=clock();
	t=(f-s)/CLOCKS_PER_SEC;
	printf("耗时%fs\n",t);
	for(i=0;i<len;i++)
		printf("%d\n",a[i]);
        free(a);
}
}
