#include"sys.h"

int main()
{
	int fd=open("data2",O_CREAT|O_WRONLY|O_TRUNC,0644);
	dup2(fd,1);
//	write(1,"213",3);
	printf("afshf\n");
}
