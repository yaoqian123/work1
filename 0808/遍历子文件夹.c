#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>

void list(char* buf)
{
	DIR* dir=opendir(buf);
	if(dir==NULL)
		return;
	struct dirent* dt=NULL;
	while((dt=readdir(dir))!=NULL)
	{
		if(strcmp(dt->d_name,".")==0 || strcmp(dt->d_name,"..")==0)	//排除上一层
			continue;
		if(dt->d_type==DT_DIR)
		{
			char path[300]="";
			sprintf(path,"%s/%s",buf,dt->d_name);			//拼接
			list(path);
			printf("%s\n",path);
		}
		else
		{
			char path1[300]="";
			sprintf(path1,"%s/%s",buf,dt->d_name);
			printf("%s\n",path1);
		}
	}
}

void main()
{
	char buf[100]="";
	printf("输入需要遍历的路径");
	scanf("%s",buf);
	list(buf);
}
