#include<stdbool.h>
#include<errno.h>
#include "../msg.h"
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>

//下载文件
//200路径存在 201路径是文件夹 202权限不够 203未知错误
bool loadFile(char* root,int newfd)
{
	repost rp={200,0};	//type length
	int fd=open(root,O_RDONLY);
	if(fd<0)		//打开失败
	{
		switch(errno)
		{
			case EACCES:
			        rp.type=202;
	        	break;
			case EISDIR:
	 			rp.type=201;
			break;
			default:
				rp.type=203;
			break;
		}
		send(newfd,&rp,sizeof(rp),0);
		return false;
	}
	int len;
	char buf[100]="";
	int ilen=sizeof(root);
	//先发送长度
	send(newfd,&ilen,sizeof(ilen),0);
	//再发送数据
	send(newfd,root,ilen,0);
        while((len=read(fd,buf,100))>0)
        {
		send(newfd,buf,len,0);
        }
	close(newfd);
	close(fd);
}
//遍历文件夹
//100路径存在  101路径是文件  102路径不存在  103权限不够 
bool listDir(char* root,int newfd)
{
	//返回状态
	repost rp={100,0};//type  length
	DIR* dir=opendir(root);
	if(dir==NULL)//打开失败
	{
		switch(errno)
		{
			case ENOTDIR:
				rp.type=101;
			break;
			case EACCES:
				rp.type=103;
			break;
			case ENOENT:
				rp.type=102;
			break;
			default://未知错误
				rp.type=104;
		}
		send(newfd,&rp,sizeof(rp),0);
		return false;
	}	
	//遍历
	struct dirent* dt=NULL;
	mystat fs;//文件类型
	while((dt=readdir(dir))!=NULL)//先获取个数
		rp.length++;
	send(newfd,&rp,sizeof(rp),0);//先返加状态
	//再返节点
	rewinddir(dir);
	char path[257]="";
	while((dt=readdir(dir))!=NULL)
	{
		sprintf(path,"%s/%s",root,dt->d_name);//获取绝对路径
		//文件属性
		stat(path,&fs.st);//绝对路径
		strcpy(fs.name,dt->d_name);//名字
		send(newfd,&fs,sizeof(fs),0);
	}
	closedir(dir);
	return true;
}
//获取消息类型并返回
bool recvData(int newfd)
{
	//接收请求
	request rq;
	int total=sizeof(rq);
	int ilen=0;
	while(total>0&&(ilen=recv(newfd,&rq,total,0))>0)
	{
		total-=ilen;
	}
	if(ilen<=0)//断开连接 或失败
		return false;
	//再响应请求
	switch(rq.type)
	{
		case 1://查看路径
			printf("查看 %s\n",rq.path);
			listDir(rq.path,newfd);
		break;	
		case 2://下载文件
			printf("下载 %s\n",rq.path);
			loadFile(rq.path,newfd);
		break;
		default:
			printf("未知请求类型\n");
	}
	return true;
}
