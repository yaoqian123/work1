#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void main()
{
	int a=100;
	int* pa=NULL;
	assert(pa!=NULL);
	printf("%d\n",*pa);
/*	
	//底层
	if(pa!=NULL);
	{
		printf("%d\n",*pa);
	}else//条件为假
	{
		perror("pa!=NULL");
		abort();
	}
	*/

}
