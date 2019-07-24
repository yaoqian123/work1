//汉诺塔
#include<stdio.h>
#include<time.h>
void move(char x,char y)
{
	printf("%c->%c\n",x,y);
}
void hn(int n, char x, char y, char z)    
{
	if(n<=0)
		return;
	else if(n == 1);
//	move(x,z);
     else
     {
    	hn(n-1,x,z,y);		//从第一个移动至第二个柱子
//        move(x,z);
        hn(n-1,y,x,z);		//从第2个柱子移动至第3个柱子
     }

}


int main()
{
    //A,B,C分别代表三个柱子
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'C';

	float t=0,s=0,f=0;
    int n;   //n代表圆盘的个数
    printf("请输入圆盘的个数：");
    scanf("%d",&n);
    s=clock();
    hn(n,ch1,ch2,ch3);
    f=clock();
    t=(f-s)/CLOCKS_PER_SEC;
    printf("耗时%fs\n",t);
    return 0;
}
