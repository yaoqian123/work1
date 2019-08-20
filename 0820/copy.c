#include"sys.h"

pthread_mutex_t mutex,mutex1;
typedef struct file
{
	char a[20];
	char b[20];
	int i;	
	int len;		//4分之1的长度
}file,*pfile;

void* threadfun(void* arg)
{
	pfile p=(pfile)arg;
	int fd1=open(p->a,O_RDONLY,0644);
	if(fd1<0)
	{
		perror("open fd1 fail!");
		return NULL;
	}
	int fd2=open(p->b,O_WRONLY|O_CREAT,0644);
	if(fd2<0)
	{
		perror("open fd2 fail!");
		return NULL;
	}
	int i=0;
	char buf[1];
	lseek(fd1,p->i*p->len,SEEK_SET);
	lseek(fd2,p->i*p->len,SEEK_SET);
	//printf("%d\n",(p->i)*(p->len));
	//printf("fun函数%d\n",p->i);
	if(i=3)
	{
		while(read(fd1,buf,1)>0)
		{
			write(fd2,buf,1);
		}
	}
	else
	{
		while(i<=p->len && read(fd1,buf,1)>0)
		{
			write(fd2,buf,1);
		}
	}
	close(fd1);
	close(fd2);
	pthread_mutex_unlock(&mutex1);
}

void main(int argc,char* argv[])
{
	pthread_mutex_init(&mutex,NULL);
	pthread_mutex_init(&mutex1,NULL);
	file f={0};
	pthread_t tid[4];
	strcpy(f.a,argv[1]);
	strcpy(f.b,argv[2]);
	struct stat st;
	stat(argv[1],&st);
	int len;
	printf("文件长度为%ld\n",st.st_size);
	len=st.st_size/4;
	f.len=len;
	//创建线程
	int i=0,j;
	printf("拷贝开始\n");
	for(i=0;i<4;i++)
	{
		pthread_mutex_lock(&mutex1);
		f.i=i;
	//	printf("主函数内I:%d\n",f.i);
		pthread_create(tid+i,NULL,threadfun,&f);
		printf("拷贝进度%d%%\n",25*f.i);
	}
	printf("拷贝完成\n");
	for(j=0;j<4;j++)
	{
		pthread_join(tid[j],NULL);
	}	
}

