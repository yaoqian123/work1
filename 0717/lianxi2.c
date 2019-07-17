//通过pch统计里面有多少个单词
//通过pch讲小写字符转换为大写字符
//查找第一次出现的子字符串，并告诉方位。
#include<stdio.h>

void main()
{
	char buf[]="my name is yaoqian,what is your name?";
	char* pch=buf;
/*	while(*(pch++)!='\0');
//	printf("%ld\n",pch-buf-1);
	int n=pch-buf-1;
	printf("%d\n",n);
	pch=buf;
	for(int i=0;i<n;i++)
	{
		if(*pch!=' '&&*pch!=','&&*pch!='?')
		*pch=*pch-32;
		pch++;
	}
	printf("%s\n",buf);
	*/
	pch=buf;

	char sbuf[]="what";
	char* spch=sbuf;
	for(int i=0;i<37;i++)
	{
		if(pch[i]=='w')
		{
			if(pch[i+1]=='h')
			{
				if(pch[i+2]=='a')
				{
					if(pch[i+3]=='t')
					{
						printf("yes %d %d %d %d\n",i,i+1,i+2,i+3);
					}
				}
			}
		}
	}
	
/*	int flag=1,fla=1,i=0,j=0;
	while(buf[j]!='\0')
	{
		while(buf[i]!='\0')
		{
			if(buf[i]!=sbuf[j])
			{
				i++;
			}
			else{
				flag=0;
				break;
			}
		}
	if(flag==0)
	{
		j++;
	}else{
		printf("no\n");
		fla=0;
		break;
	}	
	}
	if(fla==1)
	{
		i=0;	
		while(buf[i]!=sbuf[0])
		{
			i++;
		}
		printf("yes,%d\n",i);
	}
*/
}

