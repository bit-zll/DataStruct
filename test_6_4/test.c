#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
//typedef struct ListNode ListNode;
////对链表进行插入排序。
//struct ListNode* insertionSortList(struct ListNode* head)
//{
//	//链表为空或者链表中只有一个节点
//	if (NULL == head || NULL == head->next)
//		return head;
//
//	//链表中至少有两个节点
//	//从原链表中获取一个节点将其插入到新链表中
//	ListNode* newHead = NULL;
//	ListNode* cur = head;
//	while (cur)
//	{
//		//cur即为需要向新链表中插入的节点
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

//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

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
	//1.在原链表中每个节点后插入值相等的新节点
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
	//2.给新节点的随机指针域赋值
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
	//3.将新节点从原链表中拆下来
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