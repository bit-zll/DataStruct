#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
#include <malloc.h>
#include <stdio.h>
#include <assert.h>

SListNode* BuySListNode(SLDataType data)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == newNode)
	{
		assert(0);  //���Ժ꣬����Ϊ0��ͻᴥ������0���ᴥ��
		return NULL;
	}
	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}
//β��
void SListPushBack(SListNode** head, SLDataType data)
{
	assert(head);
	//������
	SListNode* newNode = BuySListNode(data);
	if (NULL == *head)
	{
		*head = newNode;
	}
	else
	{
		//1.�ҵ������е����һ���ڵ�
		SListNode* cur = *head;
		while (cur->next)
		{
			cur = cur->next;
		}
		//2.�����½ڵ�
		cur->next = newNode;
	}
}
//βɾ
void SListPopBack(SListNode** head)
{
	assert(head);//���Ƿ����
	if (NULL == *head)
	{
		//������
		return;
	}
	else if (NULL == (*head)->next)
	{
		//������ֻ��һ���ڵ�
		free(*head);
		*head = NULL;
	}
	else
	{
		//����ǿ�---������������һ���ڵ�
		SListNode* cur = *head;
		SListNode* prev = NULL;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = NULL;
		//ɾ���ýڵ�
		free(cur);
	}
}
//ͷ��
void SListPushFront(SListNode** head, SLDataType data)
{
	assert(head);
	SListNode* newNode = BuySListNode(data);
	newNode->next = *head;
	*head = newNode;
	////1.������
	//if (NULL == *head)
	//	*head = newNode;
	//else
	//{
	//	//2.�����ж���ڵ�
	//	newNode->next = *head;
	//	*head = newNode;
	//}
}
//ͷɾ
void SListPopFront(SListNode** head)
{
	assert(head);
	SListNode* delNode = NULL;
	if (NULL == *head)
		return;
	delNode = *head;
	*head = delNode->next;
	free(delNode);
}
//����λ�ò���
void SListInsertAfter(SListNode* pos, SLDataType data)
{
	SListNode* newNode = NULL;
	if (NULL == pos)
		return;
	newNode = BuySListNode(data);
	newNode->next = pos->next;
	pos->next = newNode;
}
//����λ��ɾ��
void SListEraseAfter(SListNode* pos)
{
	SListNode* delNode = NULL;
	if (NULL == pos||NULL == pos->next)
		return;
	delNode = pos->next;
	pos->next = delNode->next;
	free(delNode);
}
//�ڵ����
int SListSize(SListNode* head)
{
	SListNode* cur = head;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
//�ж������Ƿ�Ϊ��
int SListEmpty(SListNode* head)
{
	return NULL == head;
}
//���ҽڵ�
SListNode* SListFind(SListNode* head, SLDataType data)
{
	SListNode* cur = head;
	while (cur)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
//��������
void SListDestroy(SListNode** head)
{
	assert(head);
	while (*head)
	{
		SListNode* delNode = *head;
		*head = delNode->next;
		free(delNode);
	}
}
//��ӡ����
void PrintSList(SListNode* head)
{
	SListNode* cur = head;
	while (cur)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//////////////////////////////////////////

void TestSList()
{
	SListNode* listhead = NULL;
	SListPushBack(&listhead, 1);
	SListPushBack(&listhead, 2);
	SListPushBack(&listhead, 3);
	SListPushBack(&listhead, 4);
	SListPushBack(&listhead, 5);

	SListPopBack(&listhead);

	SListPushFront(&listhead, 0);

	SListPopFront(&listhead);

	SListInsertAfter(SListFind(listhead, 3), 0);

	SListEraseAfter(SListFind(listhead, 2));

	printf("%d\n", SListSize(listhead));

	//SListDestroy(&listhead);
	PrintSList(listhead);
}