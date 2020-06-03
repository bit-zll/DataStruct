#define _CRT_SECURE_NO_WARNINGS 1

#include "DHCList.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>

DHCLNode* BuyDHCListNode(DLDataType data)
{
	DHCLNode* newNode = (DHCLNode*)malloc(sizeof(DHCLNode));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
//ֻ�轫ͷ��������
DHCLNode* DHCListInit()
{
	DHCLNode* head = BuyDHCListNode(0);
	head->next = head;
	head->prev = head;
	return head;
}
void DHCListPushBack(DHCLNode* pHead, DLDataType data)
{
	assert(pHead);
	DHCListInsert(pHead, data);
}
void DHCListPopBack(DHCLNode* pHead)
{
	if (DHCListEmpty(pHead))
		return;
	DHCListErase(pHead->prev);
}
void DHCListPushFront(DHCLNode* pHead, DLDataType data)
{
	assert(pHead);
	DHCListInsert(pHead->next, data);
}
void DHCListPopFront(DHCLNode*pHead)
{
	if (DHCListEmpty(pHead))
		return;
	DHCListErase(pHead->next);
}
void DHCListInsert(DHCLNode* pos, DLDataType data)
{
	DHCLNode* newNode;
	if (NULL == pos)
		return;
	//�����½ڵ�
    
	newNode = BuyDHCListNode(data);
	//�Ƚ��½ڵ����ӵ�ԭ������
	newNode->next = pos;
	newNode->prev = pos->prev;
	//�Ͽ�����
	pos->prev = newNode;
	newNode->prev->next = newNode;
}
void DHCListErase(DHCLNode* pos)
{
	if (NULL == pos)
		return;
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}
DHCLNode* DHCListFind(DHCLNode* pHead, DLDataType data)
{
	assert(pHead);
	DHCLNode* cur = pHead->next;
	while (cur!=pHead)
	{
		if (data == cur->data)
			return cur; 
		cur = cur->next;
	}
	return NULL;
}
int DHCListSize(DHCLNode* pHead)
{
	assert(pHead);
	DHCLNode* cur = pHead->next;
	int count = 0;
	while (cur != pHead)
	{
		++count;
		cur = cur->next;
	}
	return count;
}
int DHCListEmpty(DHCLNode* pHead)
{
	assert(pHead);
	return pHead->next == pHead;
}
//ֻ�ǽ������е���Ч�ڵ�ɾ������ɾͷ�ڵ�
void DHCListClear(DHCLNode* pHead)
{
	assert(pHead);
	DHCLNode* cur = pHead->next;
	while (cur != pHead)
	{
		pHead->next = cur->next;
		free(cur);
		cur = pHead->next;
	}
	//�����Ѿ�Ϊ��
	pHead->next = pHead;
	pHead->prev = pHead;
}
//��Ҫ��ͷ��������ͷ���ȫ��ɾ��
void DHCListDestroy(DHCLNode** pHead)
{
	assert(pHead);
	DHCListClear(*pHead);
	free(*pHead);
	*pHead = NULL;
}
////////////////////////////////////////////

void PrintDHCList(DHCLNode* head)
{
	DHCLNode* cur = head->next;
	while (cur != head)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void TestDHCList()
{
	DHCLNode* head = DHCListInit();
	DHCListPushBack(head, 1);
	DHCListPushBack(head, 2);
	DHCListPushBack(head, 3);
	DHCListPushBack(head, 4);
	DHCListPushBack(head, 5);
	PrintDHCList(head);

	DHCListPopBack(head);
	PrintDHCList(head);

	DHCListPushFront(head, 0);
	PrintDHCList(head);

	DHCListPopFront(head);
	PrintDHCList(head);

	DHCListInsert(DHCListFind(head, 3), 100);
	PrintDHCList(head);

	printf("%d\n", DHCListSize(head));

	DHCListDestroy(&head);
	PrintDHCList(head);
}