#pragma once
#include <stdbool.h>
typedef struct CircularQueue
{
	int* data;
	int head;
	int tail;
	int size;
}CircularQueue;

//创建队列，设置队列大小为k
CircularQueue* CircularQueueCreat(int k);
//检测循环队列是空还是满
bool CircularQueueIsEmpty(CircularQueue* obj);
bool CircularQueueIsFull(CircularQueue* obj);
//插入元素
bool CircularQueueEnQueue(CircularQueue* obj, int value);
//删除元素
bool CircularQueueDeQueue(CircularQueue* obj);
//获得队头元素
int CircularQueueFront(CircularQueue* obj);
//获得队尾元素
int CircularQueueRear(CircularQueue* obj);
//销毁
void CircularQueueDestroy(CircularQueue* obj);