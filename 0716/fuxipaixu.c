#include<stdio.h>

void main()
{
	int i=0,j=0;
	char a[]={"jhsadihhadsjknmcvxnkopyg"};

	for(i=0;a[i+1]!='\0';i++)
	{
		int lin=i;
		for(j=i+1;a[j]!='\0';j++)
		{
			if(a[lin] > a[j])
				lin = j;
		}
		if(lin!=i)
		{
			char mid=a[lin];
			a[lin]=a[i];
			a[i]=mid;
		}
	}
		printf("%s\n",a);

	char b[]="1983546487";
	i=0,j=0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10-i-1;j++)
		{
			if(b[j]>b[j+1])
			{
				char mid=b[j];
				b[j]=b[j+1];
				b[j+1]=mid;
			}
		}
	}
	printf("%s\n",b);
}

