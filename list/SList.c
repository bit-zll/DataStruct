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
		assert(0);  //调试宏，参数为0宏就会触发，非0不会触发
		return NULL;
	}
	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}
//尾插
void SListPushBack(SListNode** head, SLDataType data)
{
	assert(head);
	//空链表
	SListNode* newNode = BuySListNode(data);
	if (NULL == *head)
	{
		*head = newNode;
	}
	else
	{
		//1.找到链表中的最后一个节点
		SListNode* cur = *head;
		while (cur->next)
		{
			cur = cur->next;
		}
		//2.插入新节点
		cur->next = newNode;
	}
}
//尾删
void SListPopBack(SListNode** head)
{
	assert(head);//检测非法情况
	if (NULL == *head)
	{
		//空链表
		return;
	}
	else if (NULL == (*head)->next)
	{
		//链表中只有一个节点
		free(*head);
		*head = NULL;
	}
	else
	{
		//链表非空---链表中至少有一个节点
		SListNode* cur = *head;
		SListNode* prev = NULL;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = NULL;
		//删除该节点
		free(cur);
	}
}
//头插
void SListPushFront(SListNode** head, SLDataType data)
{
	assert(head);
	SListNode* newNode = BuySListNode(data);
	newNode->next = *head;
	*head = newNode;
	////1.空链表
	//if (NULL == *head)
	//	*head = newNode;
	//else
	//{
	//	//2.链表有多个节点
	//	newNode->next = *head;
	//	*head = newNode;
	//}
}
//头删
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
//任意位置插入
void SListInsertAfter(SListNode* pos, SLDataType data)
{
	SListNode* newNode = NULL;
	if (NULL == pos)
		return;
	newNode = BuySListNode(data);
	newNode->next = pos->next;
	pos->next = newNode;
}
//任意位置删除
void SListEraseAfter(SListNode* pos)
{
	SListNode* delNode = NULL;
	if (NULL == pos||NULL == pos->next)
		return;
	delNode = pos->next;
	pos->next = delNode->next;
	free(delNode);
}
//节点个数
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
//判断链表是否为空
int SListEmpty(SListNode* head)
{
	return NULL == head;
}
//查找节点
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
//销毁链表
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
//打印链表
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