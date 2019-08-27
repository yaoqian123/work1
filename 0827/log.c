#include<time.h>
//获取错误
void systime()
{
	time_t t; 
	time(&t);//获取服务器当前系统时间戳
	struct tm* pt=ctime(&tm);
	assert(pt!=NULL);
	printf("%d/%d/%d %d:%d:%d",pt->tm_year,pt->tm_mon,pt->tm_mday,pt->tm_hour,pt->tm_min,pt->tm_sec);

}	
//打印错误
void outerror(char* reson)
{
		
}
