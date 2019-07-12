#include<stdio.h>

void main()
{
	char a[200]={1,1};
	scanf("%s",a);
	int q=0,w=0,e=0,r=0,i=0;
	while(a[i]!='\0')
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			q++;
		}
		else if(a[i]>='a'&&a[i]<='z')
		{
			w++;
		}
		else if(a[i]>='A'&&a[i]<='Z')
		{
			e++;
		}
		else
		{
			r++;
		}
		i++;
	}
	printf("输入的一段中:\n数字数量为:%d\n小写字母数量为:%d\n大写字母数量为:%d\n字符数量为:%d\n",q,w,e,r);
}
