#ifndef __QUEUE__
#define __QUEUE__
#include<stdbool.h>
#include "threadpool.h"
extern bool isFull(CThread_worker*);
extern bool isEmpty(CThread_worker*);
extern bool push(CNode_task,CThread_worker*);
extern bool pop(CNode_task*,CThread_worker*);
extern void initQueue(CThread_worker*);
extern void clearQueue(CThread_worker*);
#endif
