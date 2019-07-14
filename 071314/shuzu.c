#include<stdio.h>

void main()
{
	int a[20]={1,1};
	scanf("%ls",a);
	int b[20]={1,1};
	scanf("%ls",b);
	int i=0,j=0,flag=1,fla=1;
	while(b[i]!='\0')
	{
		while(a[j]!='\0')
		{
			if(b[i]!=a[j])
			{
				j++;
			}
			else{
				flag=0;
				break;
			}
		}
		if(flag==0)
		{
			i++;
		}else{
			printf("no");
			fla=0;
			break;
		}
		
	}
	if(fla==1)
		printf("yes");
}
