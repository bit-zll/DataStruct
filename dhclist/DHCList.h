#pragma once

typedef int DLDataType;
typedef struct DHCListNode
{
	DLDataType data;
	struct DHCListNode* next;//ָ��ǰ�ڵ����һ���ڵ�
	struct DHCListNode* prev;//ָ��ǰ�ڵ��ǰһ���ڵ�
}DHCLNode;

DHCLNode* DHCListInit();
void DHCListPushBack(DHCLNode* pHead,DLDataType data);
void DHCListPopBack(DHCLNode* pHead);
void DHCListPushFront(DHCLNode* pHead,DLDataType data);
void DHCListPopFront(DHCLNode*pHead);
void DHCListInsert(DHCLNode* pos,DLDataType data);
void DHCListErase(DHCLNode* pos);
DHCLNode* DHCListFind(DHCLNode* pHead,DLDataType data);
int DHCListSize(DHCLNode* pHead);
int DHCListEmpty(DHCLNode* pHead);
void DHCListClear(DHCLNode* pHead);
void DHCListDestroy(DHCLNode** pHead);
void TestDHCList();