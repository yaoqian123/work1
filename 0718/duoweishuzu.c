#include<stdio.h>

void main()
{
	//指针+n 向右移动n个元素	p+n=p=sizeof（类型）*n
//	int* p=NULL;	//0
//	printf("%d %d %d\n",p,p+1,p+2);
	//一维数组
/*	short buf[]={1,2,3,4,5};
	//数组名：首地址
	printf("%x %x %x\n",buf+0,buf+1,buf+2);
	short* p=buf;
	printf("%x %x %x %d %d %d\n",p,p+1,p+2,*p,*(p+1),*(p+2));
	*/
	//二维数组
	short buf[3][4]={1,2,3,4,11,12,13,14,21,22,23,24};
	//行指针
	//printf("%x %x\n",buf+1,buf+2);
	//列指针
/*	printf("%x %x\n",&buf[0][1],buf[0]+1);
	char (*pch)[4]=buf;
	printf("%x %x %x %x\n",pch+0,pch+1,buf+0,buf+1);
	*/
	char (*pch)[4]=buf;
	printf("%d %d\n",buf[0][0],pch[0][0]);
	printf("%d %d\n",*(*(buf+0)+0),*(*(pch+0)+0));
}
