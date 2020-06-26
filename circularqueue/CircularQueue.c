#define _CRT_SECURE_NO_WARNINGS 1

#include "CircularQueue.h"
#include <stdio.h>
#include <malloc.h>


//创建队列，设置队列大小为k
CircularQueue* CircularQueueCreat(int k)
{
	CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
	queue->data = (int*)malloc(sizeof(int)*(k + 1));
	queue->head = 0;
	queue->tail = 0;
	queue->size = k + 1;
	return queue;
}
//检测循环队列是空还是满
bool CircularQueueIsEmpty(CircularQueue* obj)
{
	if (obj->head == obj->tail)
	{
		return true;
	}
	return false;
}
bool CircularQueueIsFull(CircularQueue* obj)
{
	if (obj->head == ((obj->tail + 1) % obj->size))
	{
		return true;
	}
	return false;
}
//插入元素
bool CircularQueueEnQueue(CircularQueue* obj, int value)
{
	if (CircularQueueIsFull(obj))
		return false;
	obj->data[obj->tail] = value;
	obj->tail = (obj->tail + 1) % obj->size;
	return true;
}
//删除元素
bool CircularQueueDeQueue(CircularQueue* obj)
{
	if (CircularQueueIsEmpty(obj))
		return false;
	obj->head = (obj->head + 1) % obj->size;
	return true;
}
//获得队头元素
int CircularQueueFront(CircularQueue* obj)
{
	if (CircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->data[obj->head];
}
//获得队尾元素
int CircularQueueRear(CircularQueue* obj)
{
	if (CircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->data[(obj->tail - 1 + obj->size) % obj->size];
}
//销毁
void CircularQueueDestroy(CircularQueue* obj)
{
	free(obj->data);
	free(obj);
}