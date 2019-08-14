#include"sys.h"

//打印标题[用户名@主机名 工作路径]$
void title()
{
	struct passwd* pwd=NULL;
	pwd=getpwuid(getuid());
	char path[255];
	char host[255];
	printf("\033[33m[\033[0m");	//[
	printf("\033[32m%s\033[0m",pwd->pw_name);	//获取用户名
	gethostname(host,255);
	printf("\033[32m@%s\33[0m",host);		//主机名
	getcwd(path,255);		//获取本进程的PWD /home/yaoqian
	char* rch=strrchr(path,'/');			//倒序寻找'/'
	if(strcmp(rch,"/")!=0)	//
		rch++;
	printf("\033[33m:%s]$ \033[0m",strrchr(path,'/'));	
	//绝对路径	//yaoqian
	fflush(stdout);
}

//exit函数
void myexit(int i,char* argv[])
{
		
		if(i>2)				//参数太多
		{
			printf("exit\nmybash:%s参数太多\n",argv[0]);
			return;
		}
		//kill(getppid(),9);
		exit(atoi(argv[0]));
}
//cd函数
void mycd(int i,char* argv[])
{
		if(i==1)			//直接cd
			return;
		if(i>2)				//参数太多
		{
			printf("exit\nmybash:%s参数太多\n",argv[0]);
		}
		else if(strcmp(argv[1],"..")==0)		//..
		{
			//1: /home/yaoqian/0814		2:/
			char path[255];
			getcwd(path,255);
			if(strcmp(path,"/")!=0)
			{
				*strrchr(path,'/')='\0';		//倒序寻找'/'
				if(chdir(path)<0)
					perror(argv[0]);
			}
		}
		else if(strcmp(argv[1],".")==0)
			return;
		else
		{
			if(chdir(argv[1])<0)
			{
				perror(argv[1]);
				return;
			}
		}
}
//管道函数	ls -l / | wc -w
bool mypipe(int i,char* argv[])
{
	if(i==0)		//语法错误
	{
		printf("mybash 未预期的符号 '|' 附近有语法错误\n");
		return false;
	}
	else if(argv[i+1]!=NULL && strcmp(argv[i+1],"|")==0)
	{	
		printf("mybash 未预期的符号 '|' 附近有语法错误\n");
		return false;
	}
	//左侧由本进程执行,右侧给子进程执行
	int fd[2]={-1,-1},pid=0;
	if(pipe(fd)<0)
	{
		perror("pipe fail!\n");
		return false;
	}
	pid=fork();
	if(pid<0)
	{
		perror("pipe fail!\n");
		return false;
	}
	else if(pid==0)			//子进程接收消息
	{
		close(fd[1]);		//关闭写入
		dup2(fd[0],0);
		if(execvp(argv[i+1],argv+i+1)<0)
		{
			perror(argv[i+1]);
			return false;
		}
	}
	else				//父进程 发送消息	ls -l
	{
		close(fd[0]);		//关闭读
		dup2(fd[1],1);		//1->"|"
		argv[i]=NULL;		//截断	
		if(execvp(argv[0],argv)<0)
		{
			perror(argv[i+1]);
			return false;
		}
		return true;
	}
}
//追加重定向	>>
bool reload(int i,char* argv[])
{
	if(i==0 || argv[i+1]==NULL || strcmp(argv[i+1],">")==0 || strcmp(argv[i+1],">>")==0)
	{
		return false;
	}
	close(1);
	int fd=open(argv[i+1],O_CREAT|O_WRONLY|O_APPEND,0644);		//返回最小的未被使用的
	argv[i]=NULL;				//截断
	if(execvp(argv[0],argv)<0)
	{
		perror(argv[i+1]);
		return false;
	}
	return true;
}
//截断重定向	>
bool cutreload(int i,char* argv[])
{
	if(i==0 || argv[i+1]==NULL || strcmp(argv[i+1],">")==0 || strcmp(argv[i+1],">>")==0)
        {
                 return false;
        }
	close(1);
        int fd=open(argv[i+1],O_CREAT|O_WRONLY|O_TRUNC,0644);          //返回最小的未被使用的
        argv[i]=NULL;                           //截断
        if(execvp(argv[0],argv)<0)
        {
       		perror(argv[i+1]); 
		return false;
        }
        return true;

}
//子进程执行命令行
bool execline(char* argv[])
{
	int i=0;
	for(i=0;argv[i]!=NULL;i++)
	{
		if(strcmp(argv[i],"|")==0)		//管道
		{
			if(!mypipe(i,argv))
				return false;
			else
				return true;
		}
		else if(strcmp(argv[i],">>")==0)
		{
			reload(i,argv);
		}
		else if(strcmp(argv[i],">")==0)
		{
			cutreload(i,argv);
		}
	}
	//执行其他命令
	if(execvp(argv[0],argv)<0)
	{
		perror(argv[0]);
		return false;
	}
}
//kill函数
void mykill(int i,char* argv[])
{
 		if(i==1)                        //直接空格
		{
			printf("kill: 用法: kill [-s 信号声明 | -n 信号编号 | -信号声明] 进程号 | 任务声明 ... 或 kill -l [信号声明]\n");
		}
		else if(i==2)                        
                {
			if(strcmp(argv[1],"-l")==0)
			{	
                        printf("1");
			}
			else
			{
				printf("bash: kill: %s:选项需要一个参数\n",argv[1]);
			}
                }
		else
		{
			if(strcmp(argv[1],"-9")==0)
				exit(atoi(argv[2]));
		}
		
}

//父进程解析命令行
bool commandLine(char *argv[])
{
	char cmd[1024]="";
	fgets(cmd,sizeof(cmd)-1,stdin);		// ls -l \n
	if(strcmp(cmd,"\n")==0)			//没有命令  直接换行
		return false;
	cmd[strlen(cmd)-1]='\0';		//由于fgets自动添加\n,将\n去掉,变为\0
	argv[0]=strtok(cmd," ");
	int i=0;
	while((argv[++i]=strtok(NULL," "))!=NULL);
	//判断当前命令是否为exit
	if(strcmp(argv[0],"exit")==0)
	{
		myexit(i,argv);
		return false;
	}
	//判断当前命令是否为cd
	else if(strcmp(argv[0],"cd")==0)
	{
		mycd(i,argv);
		return false;
	}
	//判断当前命令是否为kill
	else if(strcmp(argv[0],"kill")==0)
	{
		mykill(i,argv);
		return false;
	}
	else	//除了上述命令为父进程执行,其余由子进程执行
		return true;
}
//信号处理
void handle(int sig)
{
	if(SIGCHLD==sig)
	{
		wait(NULL);
	}
}
//父进程打印标题,输入命令,解析命令行,等待子进程结束,/子进程执行命令
void main()
{
	//注册信号
//	signal(SIGCHLD,handle);
	char* argv[100]={NULL};		//指针数组	ls -l -a /home
	int pid=-1;
	while(1)
	{
		title();
		//输入解析命令行
		if(!commandLine(argv))
			continue;
		pid=fork();
		if(pid==0)
		{
			//子进程执行命令行
			if(!execline(argv))
				exit(-1);
		}
		else if(pid>0)
		{
			wait(NULL);
		}
		else
		{
			perror("fail!\n");
		}
	}
}

