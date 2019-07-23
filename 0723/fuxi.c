#include<stdio.h>

char *copy(char *des,char *src)
{
	int i=0;
	char *addr=des;
	while(des[i]!='\0')
	{
		if(src[i]!='\0')
		{
			des[i]=src[i];
		}
		else
			des[i]='\0';
		i++;
	}
	return addr;
}
void search(int *a,int n,int key)
{
	int flag=0,low=0,high=n-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]==key)
		{
			printf("存在,下标为%d:\n",mid);
			flag=1;
			break;
		}
		else if(a[mid]>key)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}

	}
	if(flag==0)
		printf("不存在");
	
}

void len(char *des)
{
	int count=0;
	for(int i=0;des[i]!='\0';i++)
		count++;
	printf("%d\n",count);
}

void main()
{
	char src[]="sad";
	char des[]="krksaknejkq";
	copy(des,src);
	printf("%s\n",des);
	int key=0;
	scanf("%d",&key);
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int n=10;
	search(a,n,key);
	len(des);
}
