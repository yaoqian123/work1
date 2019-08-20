#include"sys.h"
#include"queue.h"
//队满
bool isfull(pqueue p)
{
	if((p->rear+1)%MAXSIZE==p->front)
		return true;
	return false;
}

//初始化
void init(pqueue p)
{
	p->rear=p->front=0;
}

//队空
bool isempty(pqueue p)
{
	if(p->rear == p->front)
		return true;
	return false;
}

//进队
bool push(pqueue p,int data)
{
	if(isfull(p))
		return false;
	p->buf[p->rear]=data;
	p->rear=(p->rear+1)%MAXSIZE;
	return true;
}
//出队
bool pop(pqueue p,int* data)
{
	if(isempty(p))
		return false;
	*data=p->buf[p->front];
	p->front=(p->front+1)%MAXSIZE;
	return true;
}
