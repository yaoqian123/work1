#include<stdio.h>

void main()
{
	int i=0;
	char a[100]={1,5,5,6,2};
	scanf("%s",&a);
	if(a[0]>='0'&&a[0]<='9')
	{
	for(i=0;a[i]!='\0';i++)
		if(a[i]>='0'&& a[i]<='9')
		{
			printf("%c",a[i]);
		}
		else
		{
			break;
		}
	}
	else
	{
		printf("%d\n",0);
	}


}
