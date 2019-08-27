
#ifndef __MSG__
#define __MSG__
//请求协议
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#pragma pack(1)
typedef struct REQ
{
	short type;//消息类型 1下载  2查看
	char path[255];//文件路径	
}request;
#pragma pack()

#pragma pack(1)
typedef struct RPO
{
	short type;//返回消息类型
	long length;//返回数据长度
}repost;
#pragma pack(1)
typedef struct 
{
	struct stat st;//属性
	char name[100];//名字
}mystat;
#pragma pack()

#endif









