#define _CRT_SECURE_NO_WARNINGS 1

#include "Stackby_two_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//申请节点
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

//初始化队列
void QueueInit(Queue* q)
{
	assert(q);
	q->head = BuyNode(0);
	q->_size = 0;
	q->rear = q->head;
}

//入队列
void QueuePush(Queue* q, QDataType val)
{
	assert(q);
	QNode* newNode = BuyNode(val);
	q->rear->next = newNode;
	q->rear = newNode;
	q->_size++;
}

//检测队列是否为空
int QueueEmpty(Queue* q)
{
	assert(q);
	return 0 == q->_size;
}

//出队列
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

//队列元素的个数
int QueueSize(Queue* q)
{
	assert(q);
	return q->_size;
}

//获取头元素
QDataType QueueFront(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->head->next->val;
}

//获取队尾元素
QDataType QueueBack(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->rear->val;
}

//销毁链表：带头节点的单链表
void QueueDestory(Queue* q)
{
	//采用头删法将链表中有效节点和头结点全部删除
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
	//哪个队列有元素，将元素插入到此队列中
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
		//q1队列中有元素，将q1中n-1个元素搬移到q2中
		while (QueueSize(&obj->q1) > 1)
		{
			QueuePush(&obj->q2, QueueFront(&obj->q1));
			QueuePop(&obj->q1);
		}
		ret = QueueFront(&obj->q1);
		//最后将q1中剩余的一个元素删除掉
		QueuePop(&obj->q1);
	}
	else
	{
		//q2队列中有元素，将q2中n-1个元素搬移到q2中
		while (QueueSize(&obj->q2) > 1)
		{
			QueuePush(&obj->q1, QueueFront(&obj->q2));
			QueuePop(&obj->q2);
		}
		ret = QueueFront(&obj->q2);
		//最后将q1中剩余的一个元素删除掉
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
