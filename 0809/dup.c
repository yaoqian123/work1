#include"sys.h"

int main()
{
/*	int fd=dup(1);
	close(1);
	write(fd,"dasdas",6);
	//printf("sdaaf");
*/
	//screen==3
	int screen=dup(1);
	close(1);
	int fd=open("data",O_CREAT|O_WRONLY|O_TRUNC,0644);
	int i=0;
	while(i++<=100)
		printf("%d\n",i);

	close(1);
	dup(3);
	while(i++<=100)
		printf("%d\n",i);

	
}
