#include<stdio.h>

void main()
{
	int buf[]={1,3,4,3,6,7,5,8,9,7,0,8,5,4};
	int i=0,j=0,z=0,k=0,l=0,flag=0;
	for(i=0;i<13-k;i++)
	{
		for(j=0;j<14-k;j++)
		{
			if(buf[i]==buf[j])
			{
				k++;
				flag=buf[j];
				for(z=j;z=14-k;z++)
				{
					buf[z]=buf[z+1];
				}
				buf[z+1]=flag;
			}
		}
	}
	for(i=0;i<13;i++)
		printf("%d",buf[i]);
}
