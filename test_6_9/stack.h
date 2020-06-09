#pragma once

typedef char SDataType;

/*
��̬ջ
#define MAXSIZE 100
typedef struct Stack
{
SDataType array[MAXSIZE];
int top;//���ջ��
}Stack;
*/

typedef struct Stack
{
	SDataType* array;
	int capacity;
	int size;//ջ��Ԫ�صĸ��� ջ��
}Stack;

void StackInit(Stack* ps);
//��ջ��β��
void StackPush(Stack* ps, SDataType data);
//��ջ��βɾ
void StackPop(Stack* ps);
//��ȡջ��Ԫ��
SDataType StackTop(Stack* ps);
//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps);
//����Ƿ�Ϊ��
int StackEmpty(Stack* ps);
//����
void StackDestroy(Stack* ps);