#include<stdio.h>

void show(char **pa)
{
	int i=0;
	for(i=0;pa[i]!=NULL;i++)
	{
		printf("%s\n",pa[i]);
	}
}
int len(char **pa)
{
	int i=0;
	for(i=0;pa[i]!=NULL;i++);
	return i;
}
void show1(char **pa)
{
	if(*pa == NULL)
		return;
	show1(pa+1);
	printf("%s\n",*pa);
}
void main()
{
	char *buf[10]={"hello","world","what is your name","yes",NULL};
	show(buf);
	printf("%d\n",len(buf));
	show1(buf);
}
