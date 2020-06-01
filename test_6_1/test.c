#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
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
//		//��curβ�嵽lessHead����greatHead
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

//����һ�����������һ��ʱ�临�Ӷ�ΪO(n),����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ�� 
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��

//bool chkPalindrome(ListNode* A)
//{
//	if (NULL == A)
//		return true;
//
//	int array[900] = { 0 };
//	int size = 0;
//	//�������еĽڵ���õ�array��������
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

//��дһ�������ҵ������������ཻ����ʼ�ڵ㡣
//typedef struct ListNode ListNode;
//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
//{
//	if (NULL == headA || NULL == headB)
//		return NULL;
//
//	//����������Ϊ��
//	//1.���������Ƿ��ཻ���ҵ�������������һ���ڵ㣬���ýڵ�ĵ�ַ�Ƿ���ͬ
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
//	//�󽻵�
//	//�ó����������ʼλ����������gap��
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
//	//���ϼ��curA��curB�Ƿ��ַ��ͬ
//	while (curA != curB)
//	{
//		curA = curA->next;
//		curB = curB->next;
//	}
//	return curA;
//}

//����һ�������ж��������Ƿ��л���
//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� - 1�����ڸ�������û�л���
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

//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
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