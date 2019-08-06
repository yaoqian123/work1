#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 4
typedef int elem;
typedef struct Queue
{
	elem buf[MAXSIZE];
	int rear;		//尾
	int front;		//头
}queue,*pqueue;
void init(pqueue pq)
{
	pq->rear=pq->front=0;
}
bool isempty(pqueue pq)
{
	if(pq->rear==pq->front)
		return true;
	return false;
}
bool isfull(pqueue pq)
{
	if((pq->rear+1)%MAXSIZE==pq->front)
		return true;
	return false;
}
unsigned short lenth(pqueue pq)
{
	return (pq->rear-pq->front+MAXSIZE)%MAXSIZE;
}
bool push(pqueue pq,elem data)
{
	if(isfull(pq))
		return false;
	pq->buf[pq->rear++]=data;
	return true;
}
bool pop(pqueue pq,elem* data)
{
	if(isempty(pq))
		return false;
	*data=pq->buf[pq->front++];
	return true;
}
void main()
{
	int i=0;
	queue q={0};
	pqueue pq=&q;
	init(pq);
	elem data;
	for(i=0;i<MAXSIZE;i++)
	{
		if(push(pq,i))
			printf("susses\n");
		else
			printf("fail\n");
	}
	for(i=0;i<MAXSIZE;i++)
	{
		if(pop(pq,&data))
		{
			printf("susses%d\n",data);
		}
		else
			printf("fail\n");
	}
}
