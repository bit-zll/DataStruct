#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//ɾ�������е��ڸ���ֵ val �����нڵ㡣
//����: 1->2->6->3->4->5->6, val = 6
//���: 1->2->3->4->5
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* cur = head;
//	struct ListNode* prev = NULL;
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			//�ýڵ�Ҫ��ɾ����
//			if (cur == head)
//			{
//				//curΪ��һ���ڵ㣬����ͷɾ�ķ�ʽ
//				head = cur->next;
//				free(cur);
//				cur = head;
//			}
//			else
//			{
//				//cur���ǵ�һ���ڵ�
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

//����һ������ͷ��� head �ķǿյ���������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣
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

//��תһ��������
//����: 1->2->3->4->5->NULL
//���: 5->4->3->2->1->NULL
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

//����һ����������������е�����k����㡣
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

//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
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