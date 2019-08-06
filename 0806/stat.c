#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/sysmacros.h>
void main()
{
	struct stat st;
	//获取文件属性
	if(stat("./a.data",&st)<0)
	{
		perror("open fail");
		return;
	}
	//打印属性
	printf("gid=%ld\n",st.st_ino);
	printf("uid=%d\n",st.st_uid);
	//类型 文件权限
	printf("mode=%d\n",st.st_mode);
	switch(st.st_mode & /*0770000*/S_IFMT)
	{
		case S_IFREG: 	//普通
		printf("普通\n");
		break;
		case S_IFSOCK:	//网络
		printf("网络\n");
		break;
		case S_IFLNK:	//链接
		printf("链接\n");
		break;
		case S_IFBLK:	//块
		printf("块\n");
		break;
		case S_IFDIR:	//文件夹
		printf("文件夹\n");
		break;
		case S_IFCHR:	//字符设备
		printf("字符设备\n");
		break;
		case S_IFIFO:	//管道
		printf("管道\n");
		break;
	}
	printf("文件的长度:%ld\n",st.st_size);
}
