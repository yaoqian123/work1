//输入一个数判断是否为回文
#include<stdio.h>

void main()
{
	int a,c;
	printf("请输入需要判断的数字\n");
	scanf("%d",&a);
	c=a;
	int b=0;
	while(c*10/10!=0)
	{
		c=c/10;
		b++;
	}
	switch(b)
	{
		case 2:
			{
				int q,w;
				q=a/10;
				w=a-q*10;
				if(w==q)
				printf("是回文");
				else
					printf("不是回文");
			}break;
		case 3:
			{
				int q,w,e;
				q=a/100;
				e=(a-q*100)/10;
				w=a-q*100-e*10;
				if(w==q)
				printf("是回文");
				else
					printf("不是回文");
			}break;
		case 4:
			{

				int q,w,e,r;
				q=a/1000;
				e=(a-q*1000)/100;
				r=(a-q*1000-e*100)/10;
				w=a-q*1000-e*100-r*10;
				if(w==q && e==r)
				printf("是回文");
				else
					printf("不是回文");
			}break;
		case 5:
			{

				int q,w,e,r,t;
				q=a/10000;
				e=(a-q*10000)/1000;
				r=(a-q*10000-e*1000)/100;
				t=(a-q*10000-e*1000-r*100)/10;
				w=a-q*10000-e*1000-r*100-t*10;
				if(w==q && e==t)
				printf("是回文");
				else
					printf("不是回文");
			}
	}
}
