#pragma once
#include <stdbool.h>
typedef struct CircularQueue
{
	int* data;
	int head;
	int tail;
	int size;
}CircularQueue;

//�������У����ö��д�СΪk
CircularQueue* CircularQueueCreat(int k);
//���ѭ�������ǿջ�����
bool CircularQueueIsEmpty(CircularQueue* obj);
bool CircularQueueIsFull(CircularQueue* obj);
//����Ԫ��
bool CircularQueueEnQueue(CircularQueue* obj, int value);
//ɾ��Ԫ��
bool CircularQueueDeQueue(CircularQueue* obj);
//��ö�ͷԪ��
int CircularQueueFront(CircularQueue* obj);
//��ö�βԪ��
int CircularQueueRear(CircularQueue* obj);
//����
void CircularQueueDestroy(CircularQueue* obj);