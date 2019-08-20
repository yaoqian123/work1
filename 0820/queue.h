#include"sys.h"

#define MAXSIZE 10
typedef struct Queue
{
	int buf[MAXSIZE];	//仓库
	int rear;		//尾巴
	int front;		//头
}queue,*pqueue;
extern void init(pqueue);
extern bool isfull(pqueue);
extern bool isempty(pqueue);
extern bool push(pqueue,int);
extern bool pop(pqueue,int*);
extern unsigned int queuelength(pqueue);

