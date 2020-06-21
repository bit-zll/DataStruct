#pragma once

typedef int QDataType;
typedef struct QNode
{
	struct QNode* _pNext;
	QDataType _data;
}QNode;

typedef struct Queue
{
	QNode* _front;//ָ���ͷԪ��
	QNode* _back;//ָ���βԪ��
	int Q_size;
}Queue;

//���г�ʼ��
void QueueInit(Queue* q);
//�����
void QueuePush(Queue* q,QDataType data);
//������
void QueuePop(Queue* q);
//���ض�ͷԪ��
QDataType QueueFront(Queue* q);
//���ض�βԪ��
QDataType QueueBack(Queue* q);
//���ض�����ЧԪ�ظ���
int QueueSize(Queue* q);
//�ж϶����Ƿ�Ϊ��
int QueueEmpty(Queue* q);
//���ٶ���
void QueueDestroy(Queue* q);

/////////////////////////////////////////
void QueueTest();