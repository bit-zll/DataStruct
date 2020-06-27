#define _CRT_SECURE_NO_WARNINGS 1

#include "Stackby_two_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//����ڵ�
QNode* BuyNode(int val)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}

	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

//��ʼ������
void QueueInit(Queue* q)
{
	assert(q);
	q->head = BuyNode(0);
	q->_size = 0;
	q->rear = q->head;
}

//�����
void QueuePush(Queue* q, QDataType val)
{
	assert(q);
	QNode* newNode = BuyNode(val);
	q->rear->next = newNode;
	q->rear = newNode;
	q->_size++;
}

//�������Ƿ�Ϊ��
int QueueEmpty(Queue* q)
{
	assert(q);
	return 0 == q->_size;
}

//������
void QueuePop(Queue* q)
{
	QNode* pDelNode = NULL;
	if (QueueEmpty(q))
		return;

	pDelNode = q->head->next;
	q->head->next = pDelNode->next;
	if (q->head->next == NULL)
		q->rear = q->head;

	free(pDelNode);
	q->_size--;
}

//����Ԫ�صĸ���
int QueueSize(Queue* q)
{
	assert(q);
	return q->_size;
}

//��ȡͷԪ��
QDataType QueueFront(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->head->next->val;
}

//��ȡ��βԪ��
QDataType QueueBack(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->rear->val;
}

//����������ͷ�ڵ�ĵ�����
void QueueDestory(Queue* q)
{
	//����ͷɾ������������Ч�ڵ��ͷ���ȫ��ɾ��
	QNode* cur = NULL;
	while (cur)
	{
		q->head = cur->next;
		free(cur);
		cur = q->head;
	}

	q->head = NULL;
	q->rear = NULL;
	q->_size = 0;
}

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* ms = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&ms->q1);
	QueueInit(&ms->q2);
	return ms;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	//�ĸ�������Ԫ�أ���Ԫ�ز��뵽�˶�����
	if (!QueueEmpty(&obj->q1))
		QueuePush(&obj->q1, x);
	else
		QueuePush(&obj->q2, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	int ret = 0;
	if (!QueueEmpty(&obj->q1))
	{
		//q1��������Ԫ�أ���q1��n-1��Ԫ�ذ��Ƶ�q2��
		while (QueueSize(&obj->q1) > 1)
		{
			QueuePush(&obj->q2, QueueFront(&obj->q1));
			QueuePop(&obj->q1);
		}
		ret = QueueFront(&obj->q1);
		//���q1��ʣ���һ��Ԫ��ɾ����
		QueuePop(&obj->q1);
	}
	else
	{
		//q2��������Ԫ�أ���q2��n-1��Ԫ�ذ��Ƶ�q2��
		while (QueueSize(&obj->q2) > 1)
		{
			QueuePush(&obj->q1, QueueFront(&obj->q2));
			QueuePop(&obj->q2);
		}
		ret = QueueFront(&obj->q2);
		//���q1��ʣ���һ��Ԫ��ɾ����
		QueuePop(&obj->q2);
	}
	return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
		return QueueBack(&obj->q1);
	else
		return QueueBack(&obj->q2);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj)  {
	QueueDestory(&obj->q1);
	QueueDestory(&obj->q2);
	free(obj);
}
