#include"sys.h"

void main(int argc,char* argv[3])
{
	if(argc<3)
	{
		printf("参数不足\n");
		return;
	}
	int fd=open(argv[1],O_RDONLY,0644);
	if(fd<0)
	{
		perror("open fail\n");
	}
	char buf;
	int i=1,j=0;
	if(strcmp(argv[2],"-b")==0&&argc==3);
	{
			printf("%d",i);
			putchar(' ');
		while((j=read(fd,&buf,1))>0)
		{
			if(buf=='\n')
			{
				i++;
				printf("\n");
				putchar(' ');
				printf("%d",i);
				putchar(' ');
			}
			if(buf!='\n')
			putchar(buf);
		}
	}
}
