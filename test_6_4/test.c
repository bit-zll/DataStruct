#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
//typedef struct ListNode ListNode;
////��������в�������
//struct ListNode* insertionSortList(struct ListNode* head)
//{
//	//����Ϊ�ջ���������ֻ��һ���ڵ�
//	if (NULL == head || NULL == head->next)
//		return head;
//
//	//�����������������ڵ�
//	//��ԭ�����л�ȡһ���ڵ㽫����뵽��������
//	ListNode* newHead = NULL;
//	ListNode* cur = head;
//	while (cur)
//	{
//		//cur��Ϊ��Ҫ���������в���Ľڵ�
//		head = cur->next;
//		ListNode* insertPos = newHead;
//		ListNode* insertPosPrev = NULL;
//		while (insertPos)
//		{
//			if (cur->val > insertPos->val)
//			{
//				insertPosPrev = insertPos;
//				insertPos = insertPos->next;
//			}
//			else
//			{
//				break;
//			}
//		}
//		if (NULL == insertPosPrev)
//		{
//			cur->next = newHead;
//			newHead = cur;
//		}
//		else
//		{
//			cur->next = insertPos;
//			insertPosPrev->next = cur;
//		}
//		cur = head;
//	}
//	return newHead;
//}

//����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣

typedef struct Node Node;

Node* BuyRandomListNode(int val)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (NULL == newNode)
		return NULL;
	newNode->val = val;
	newNode->next = NULL;
	newNode->random = NULL;

	return newNode;
}
struct Node* copyRandomList(struct Node* head)
{
	if (NULL == head)
		return NULL;
	//1.��ԭ������ÿ���ڵ�����ֵ��ȵ��½ڵ�
	Node* cur = head;
	Node* newNode = NULL;
	while (cur)
	{
		newNode = BuyRandomListNode(cur->val);
		if (newNode == NULL)
			return NULL;
		newNode->next = cur->next;
		cur->next = newNode;
		cur = newNode->next;
	}
	//2.���½ڵ�����ָ����ֵ
	cur = head;
	while (cur)
	{
		newNode = cur->next;
		if (cur->random)
		{
			newNode->random = cur->random->next;
		}
		cur = newNode->next;
	}
	//3.���½ڵ��ԭ�����в�����
	Node* newHead = head->next;
	cur = head;
	while (cur->next)
	{
		newNode = cur->next;
		cur->next = newNode->next;
		cur = newHead;
	}
	return newHead;
}