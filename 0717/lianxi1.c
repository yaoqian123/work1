//求某个字符数组串的长度
//比较两个字符数组的大小
//char buf【】=“0123456789”
//char* pch=buf
//通过pch讲buf置反
#include<stdio.h>

void main()
{
	int n=0;
	scanf("%d",&n);
	char a[]={"dshfshfuisdf"};
	char b[]={"mxnvcirwqevc"};
	char* pa=a;
	char* pb=b;
	int i=0,j=0;
	switch(n)
	{
		case 1:
			{
				while(*pa!='\0')
				{
					pa++;
					i++;
				}
				printf("%d\n",i);			
			}break;
		case 2:
			{
				scanf("%s",a);
				scanf("%s",b);
				while(*pa!='\0')
				{
					pa++;i++;
				}
				while(*pb!='\0')
				{
					pb++;j++;
				}
				if(i>j)
				{
					printf("数组a大");
				}else if(j>i){
					printf("数组B大");
				}else{
					pa=a;pb=b;int m=0;
					while(*pa!='\0')
					{
						if(*pa==*pb)
						{
							pa++;pb++;m++;
						}else if(*pa>*pb){
							printf("a大");break;
						}else{
							printf("b大");break;
						}
					}
				}			
			}break;
		case 3:
			{
				char buf[]="0123456789";
				char* pch=buf;
				i=0;
				int mid=0;
				for(i=0;i<5;i++)
				{
					mid=*(buf+10-i-1);
					*(buf+10-i-1)=*pch;
					*pch=mid;
					pch++;
				}
				printf("%s\n",buf);
			}break;
	}
}
