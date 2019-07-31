#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAXSIZE 4
typedef int elem;
typedef struct Queue
{
	elem buf[MAXSIZE];
	int front;			//头
	int rear;			//尾
}queue,*pqueue;
void initqueue(pqueue pq)
{
	pq->front=pq->rear=0;
}
bool isempty(pqueue pq)
{
	if(pq->front==pq->rear)
		return true;
	return false;
}
bool isfull(pqueue pq)
{
	if((pq->rear+1)%MAXSIZE==pq->front%MAXSIZE)
		return true;
	return false;
}
unsigned short length(pqueue pq)
{
	return ((pq->rear-pq->front+MAXSIZE)%MAXSIZE);
}
bool push(pqueue pq,elem data)
{
	if(isfull(pq))
		return false;
	pq->buf[pq->rear]=data;
	pq->rear=(pq->rear+1)%MAXSIZE;
	return true;
}
bool pop(pqueue pq,elem* data)
{
	if(isempty(pq))
		return false;
	*data=pq->buf[pq->front];
	pq->front=(pq->front+1)%MAXSIZE;
	return true;
}

void main()
{
	queue q={0};
	pqueue pq=&q;
	initqueue(pq);
	elem data;
	if(push(pq,1))
		printf("success!\n");
	if(push(pq,2))
		printf("success!\n");
	if(push(pq,3))
		printf("success!\n");
	if(push(pq,4))
		printf("success!\n");
	if(pop(pq,&data))
		printf("%d\n",data);
	if(pop(pq,&data))
		printf("%d\n",data);
	if(pop(pq,&data))
		printf("%d\n",data);
	if(pop(pq,&data))
		printf("%d\n",data);
}
