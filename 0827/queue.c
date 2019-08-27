#include"threadpool.h"
#include<stdbool.h>
#include<assert.h>

void initQueue(CThread_worker* ptw)
{
	assert(ptw!=NULL);
	ptw->front=0;
	ptw->rear=0;
}
bool isEmpty(CThread_worker* ptw)
{
	assert(ptw!=NULL);
	if(ptw->rear == ptw-> front)
		return true;
	return false;
	
}
bool isFull(CThread_worker* ptw)
{
	assert(ptw!=NULL);
	if( (ptw->rear + 1)%MAXSIZE==ptw->front)
		return true;
	return false;
}
bool push(CNode_task node,CThread_worker* ptw)
{
	assert(ptw!=NULL);
	if(isFull(ptw))
		return false;
	ptw->buf[ptw->rear]=node;
	ptw->rear=(ptw->rear+1)%MAXSIZE;
	return true;
}
bool pop(CNode_task* pnode,CThread_worker* ptw)
{
	assert(ptw!=NULL);
	if(isEmpty(ptw))
		return false;
	*pnode=ptw->buf[ptw->front];
	ptw->front=(ptw->front+1)%MAXSIZE;
	return true;
}
//清空
void clearQueue(CThread_worker* ptw)
{
	assert(ptw!=NULL);
	ptw->rear=ptw->front=0;
}




