#pragma once

typedef char SDataType;

/*
静态栈
#define MAXSIZE 100
typedef struct Stack
{
SDataType array[MAXSIZE];
int top;//标记栈顶
}Stack;
*/

typedef struct Stack
{
	SDataType* array;
	int capacity;
	int size;//栈中元素的个数 栈顶
}Stack;

void StackInit(Stack* ps);
//入栈：尾插
void StackPush(Stack* ps, SDataType data);
//出栈：尾删
void StackPop(Stack* ps);
//获取栈顶元素
SDataType StackTop(Stack* ps);
//获取栈中有效元素个数
int StackSize(Stack* ps);
//检测是否为空
int StackEmpty(Stack* ps);
//销毁
void StackDestroy(Stack* ps);