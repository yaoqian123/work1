#include<stdio.h>

void main()
{
	int a[6]={1,3,6,5,2,4};
	int n=sizeof(a)/4;
	printf("%d",n);				//归并算法,a为数组,n表示数组大小
	merge_sort(a,n)
	{
		merge_sort_c(a,0,m);
	}
}
int merge_sort(a,6)				//调用递归函数
{
	if (p>=r) 
	return ;  				//递归中止条件
	int q=(p+r)/2;                    	//取p到r之间中间的位置 q
	//分治递归
	merge_sort_c(a,p,q);
	merge_sort_c(a,q+1,r);
	//将 a[p...q]和a[q+1+++r]合并为a[merge(a[p...r])],a[p...q],a[q+1...r]
}
merge(a[p...r],a[p...q],a[q+1...r])
	var i :=p,j :=q+1
