#include"sys.h"

void main()
{
	printf("进程开始了\n");
	char* argv[]={"ps","-e",NULL};
	execv("/bin/ps",argv);		//argv[0]	argv[1]
//	execl("/bin/ls","ls","-l",NULL);
//	execvp("ps",argv);
	/*打印1-100的和*/
	printf("进程结束了\n");
}
