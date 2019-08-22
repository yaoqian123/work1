#include"sys.h"

void* pthreadfuna(void* arg)
{
	int i,j,flag,m=0;
	for(i=2;i<=100000;i++)
	{
		flag=0;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			m++;
	}
	printf("2-100000的质数有%d个\n",m);
}

void* pthreadfunb(void* arg)
{
	int i,j,flag,m;
	for(i=100000;i<=200000;i++)
	{
		flag=0;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			m++;
	}
	printf("100000-200000的质数有%d个\n",m);
}
void main()
{
	pthread_t tid;
	pthread_create(&tid,NULL,pthreadfuna,NULL);
	pthread_create(&tid,NULL,pthreadfunb,NULL);
	pthread_join(tid,NULL);
}
