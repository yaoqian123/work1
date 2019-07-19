//
#include<stdio.h>

void main()
{
	int buf[]={1,3,4,3,6,7,5,8,9,7,0,8,5,4};
	int j=1,z=0;
	for(int i=0;i<13;i++)
	{
		for(j=i+1;j<14;j++)
		{
			if(buf[j]==buf[i])
			{
				z++;	
			}
		}	
	}
	printf("%d\n",14-z);
}
