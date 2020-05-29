#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//删除链表中等于给定值 val 的所有节点。
//输入: 1->2->6->3->4->5->6, val = 6
//输出: 1->2->3->4->5
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* cur = head;
//	struct ListNode* prev = NULL;
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			//该节点要被删除掉
//			if (cur == head)
//			{
//				//cur为第一个节点，采用头删的方式
//				head = cur->next;
//				free(cur);
//				cur = head;
//			}
//			else
//			{
//				//cur不是第一个节点
//				prev->next = cur->next;
//				free(cur);
//				cur = prev->next;
//			}
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//}

//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。
//struct ListNode* middleNode(struct ListNode* head)
//{
//	struct ListNode* fast = head;
//	struct ListNode* slow = head;
//	while (fast&&fast->next)
//	{
//		fast = fast->next->next;
//		slow = slow->next;
//	}
//	return slow;
//}

//反转一个单链表
//输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL
//struct ListNode* reverseList(struct ListNode* head)
//{
//	struct ListNode* prev = NULL;
//	struct ListNode* cur = head;
//	struct ListNode* next = NULL;
//	while (cur)
//	{
//		next = cur->next;
//		cur->next = prev;
//		prev = cur;
//		cur = next;
//	}
//	return prev;
//}

//输入一个链表，输出该链表中倒数第k个结点。
//ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
//{
//	if (NULL == pListHead || k == 0)
//		return NULL;
//	ListNode* fast = pListHead;
//	ListNode* slow = pListHead;
//
//	while (k)
//	{
//		if (NULL == fast)
//			return NULL;
//		fast = fast->next;
//		k--;
//	}
//	while (fast)
//	{
//		fast = fast->next;
//		slow = slow->next;
//	}
//	return slow;
//}

//将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//typedef struct ListNode ListNode;
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
//{
//	if (NULL == l1)
//		return l2;
//	if (NULL == l2)
//		return l1;
//	ListNode* newhead = NULL;
//	ListNode* tailNode = NULL;
//	ListNode* cur1 = l1;
//	ListNode* cur2 = l2;
//	if (cur1->val <= cur2->val)
//	{
//		newhead = cur1;
//		tailNode = cur1;
//		cur1 = cur1->next;
//	}
//	else
//	{
//		newhead = cur2;
//		tailNode = cur2;
//		cur2 = cur2->next;
//	}
//	while (cur1&&cur2)
//	{
//		if (cur1->val <= cur2->val)
//		{
//			tailNode->next = cur1;
//			cur1 = cur1->next;
//		}
//		else
//		{
//			tailNode->next = cur2;
//			cur2 = cur2->next;
//		}
//		tailNode = tailNode->next;
//	}
//	if (cur1)
//		tailNode->next = cur1;
//	else
//		tailNode->next = cur2;
//
//	return newhead;
//}