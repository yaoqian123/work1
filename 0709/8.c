#include<stdio.h>
#include<stdlib.h>

#define STACK_SIZE 64    //栈大小
#define TOP_OF_STACK -1  //栈顶位置
typedef int ElementType   //栈元素类型

#define TRUE 0
#define FALSE -1

//定义栈结构
typedef struct StackInfo
{
	int topOfStack[STACK_SIZE];   //记录栈顶位置
	ElemenntType stack[STACK_SIZE];  //栈数组,也可以使用动态数组实现
}StackInfo_st;

bool stack full(StackInfo_st *s,ElementType value);





//创建栈
StackInfo_st stack;
stack.topOfStack = TOP_OF_STACK;
