//二级指针
#include<stdio.h>

void main()
{
/*	//定义普通变量:存储值
	int a=100;
	printf("%d\n",a);
	//一级指针变量:
	int * pa=&a;
	printf("%x %d\n",pa,*pa);
	//二级指针变量:
	int** pb=&pa;
	printf("%x %x %x %x %d %d\n",pb,&pa,*pb,&a,**pb,a);
	*/
	int i=100;
	int j=200;
	int *pj=&j;
	int *pi=&i;
	int** ppj=&pj;
	int** ppi=&pi;
	int mid=**ppj;
	**ppj=**ppi;
	**ppi=mid;
	printf("%d %d ",i,j);
	int c=*pi;
	*pi=*pj;
	*pj=c;
	printf("%d %d",i,j);

}
