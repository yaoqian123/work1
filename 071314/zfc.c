#include<stdio.h>

void main()
{
	char a[20]={0,0};
	scanf("%s",a);
	char b[20]={0,0};
	char c[20]={0,0};
	char d[20]={0,0};
	int i=0,v=0,m=0,n=0;
	while(a[i]!='\0')
	{
		if(a[i]>='a'&&a[i]<='z')
		{
			b[v]=a[i];
			v++;
		}
		else if(a[i]>='A'&&a[i]<='Z')
		{
			c[m]=a[i];
			m++;
		}else{
			d[n]=a[i];
			n++;
		}
		i++;
	}
	
	printf("%s%s%s\n",b,d,c);
}
