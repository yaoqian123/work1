#include<stdio.h>
#include<malloc.h>
void main()
{
	int len=0,i=0;
	printf("输入长度:");
	scanf("%d",&len);
	int *a=(int *)malloc(sizeof(int)*len);
	for(i=0;i<len;i++)
		scanf("%d",&a[i]);
	for(i=0;i<len;i++)
		printf("%d",a[i]);

}
