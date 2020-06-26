#define _CRT_SECURE_NO_WARNINGS 1

#include "CircularQueue.h"
#include <stdio.h>
#include <malloc.h>


//�������У����ö��д�СΪk
CircularQueue* CircularQueueCreat(int k)
{
	CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
	queue->data = (int*)malloc(sizeof(int)*(k + 1));
	queue->head = 0;
	queue->tail = 0;
	queue->size = k + 1;
	return queue;
}
//���ѭ�������ǿջ�����
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
//����Ԫ��
bool CircularQueueEnQueue(CircularQueue* obj, int value)
{
	if (CircularQueueIsFull(obj))
		return false;
	obj->data[obj->tail] = value;
	obj->tail = (obj->tail + 1) % obj->size;
	return true;
}
//ɾ��Ԫ��
bool CircularQueueDeQueue(CircularQueue* obj)
{
	if (CircularQueueIsEmpty(obj))
		return false;
	obj->head = (obj->head + 1) % obj->size;
	return true;
}
//��ö�ͷԪ��
int CircularQueueFront(CircularQueue* obj)
{
	if (CircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->data[obj->head];
}
//��ö�βԪ��
int CircularQueueRear(CircularQueue* obj)
{
	if (CircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->data[(obj->tail - 1 + obj->size) % obj->size];
}
//����
void CircularQueueDestroy(CircularQueue* obj)
{
	free(obj->data);
	free(obj);
}