//创建一个数组栈
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Size 20

typedef char ElementType;
typedef struct
{
	ElementType data[Size];
	int top;
}Stack;
int StackEmpty(Stack *s)   //判断栈是否为空
int StackFull(Stack *s)   //判断栈是否为满
{
	return(s->top == Size-1);
}

void PushStack(Stack *s,char *buf)    //入栈
{
	if(NULL == s || NULL == buf )
		return;
	while( *buf != '\0' && *buf != '^' && !StackFull(s))
	{
		if(*buf != NULL)
			s->data[++s->top]=*buf;
		++buf;
	}
}

void TopStack(Stack *s)    //获得栈顶元素
void PopStack(Stack *s)    //出栈
{
	if(NULL == s)
		return;
	while(s->top != -1)
		putchar(s->data[s->top--]);
}

int main()
{

	printf("请选择对栈的操作:");
	printf("1.向栈里面放入元素!");
	printf("2.取出栈顶元素!");
	printf("3.清空栈!");
	printf("4.查看栈中所有元素!");
	int opr;
	scanf("%d",&opr);
	switch(opr)
	case 1:
	{}break;
	case 2:
	{}break;
	case 3:
	{}break;
	default:
	break
}
