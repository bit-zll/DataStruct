#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
//ListNode* partition(ListNode* pHead, int x)
//{
//	if (NULL == pHead)
//		return NULL;
//	ListNode lessHead(0);
//	ListNode greatHead(0);
//	ListNode* lessTail = &lessHead;
//	ListNode* greatTail = &greatHead;
//	ListNode* cur = pHead;
//
//	while (cur)
//	{
//		pHead = cur->next;
//		//将cur尾插到lessHead或者greatHead
//		if (cur->val < x)
//		{
//			lessTail->next = cur;
//			lessTail = cur;
//		}
//		else
//		{
//			greatTail->next = cur;
//			greatTail = cur;
//		}
//		cur = pHead;
//	}
//	greatTail->next = NULL;
//	lessTail->next = greatHead.next;
//	return lessHead.next;
//}

//对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。 
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。

//bool chkPalindrome(ListNode* A)
//{
//	if (NULL == A)
//		return true;
//
//	int array[900] = { 0 };
//	int size = 0;
//	//将链表中的节点放置到array的数组中
//	ListNode* cur = A;
//	while (cur)
//	{
//		array[size++] = cur->val;
//		cur = cur->next;
//	}
//	int left = 0, right = size - 1;
//	while (left < right)
//	{
//		if (array[left] != array[right])
//			return false;
//		left++;
//		right--;
//	}
//	return true;
//}

//编写一个程序，找到两个单链表相交的起始节点。
//typedef struct ListNode ListNode;
//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
//{
//	if (NULL == headA || NULL == headB)
//		return NULL;
//
//	//两个链表都不为空
//	//1.两个链表是否相交：找到两个链表的最后一个节点，检测该节点的地址是否相同
//	ListNode* curA = headA;
//	int countA = 1;
//	while (curA->next)
//	{
//		countA++;
//		curA = curA->next;
//	}
//	ListNode* curB = headB;
//	int countB = 1;
//	while (curB->next)
//	{
//		countB++;
//		curB = curB->next;
//	}
//	if (curA != curB)
//		return NULL;
//	//求交点
//	//让长的链表从起始位置先往后走gap步
//	curA = headA;
//	curB = headB;
//	int gap = countA - countB;
//	if (gap > 0)
//	{
//		while (gap--)
//			curA = curA->next;
//	}
//	else
//	{
//		while (gap++)
//			curB = curB->next;
//	}
//	//不断检测curA和curB是否地址相同
//	while (curA != curB)
//	{
//		curA = curA->next;
//		curB = curB->next;
//	}
//	return curA;
//}

//给定一个链表，判断链表中是否有环。
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 - 1，则在该链表中没有环。
//bool hasCycle(struct ListNode *head)
//{
//	struct ListNode* fast = head;
//	struct ListNode* slow = head;
//	while (fast&&fast->next)
//	{
//		fast = fast->next->next;
//		slow = slow->next;
//		if (fast == slow)
//			return true;
//	}
//	return false;
//}

//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
ListNode* hasCycle(ListNode* head)
{
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return fast;
	}
	return NULL;
}
struct ListNode *detectCycle(struct ListNode *head)
{
	ListNode* pM = hasCycle(head);
	if (NULL=pM)
		return NULL;
	ListNode* pH = head;
	while (pH != pM)
	{
		pH = pH->next;
		pM = pM->next;
	}
	return pM;
}