#pragma once

typedef int SLDataType;

typedef struct SListNode
{
	struct SListNode* next;//指向下一个节点的地址
	SLDataType data;//存储该节点的数据
}SListNode;

//如果想要在函数中改变头指针的指向，形参必须为二级指针
void SListPushBack(SListNode** head, SLDataType data);
void SListPopBack(SListNode** head);
void SListPushFront(SListNode** head, SLDataType data);
void SListPopFront(SListNode** head);

void SListInsertAfter(SListNode* pos, SLDataType data);
void SListEraseAfter(SListNode* pos);

int SListSize(SListNode* head);
int SListEmpty(SListNode* head);

SListNode* SListFind(SListNode* head, SLDataType data);

void SListDestroy(SListNode** head);

///////////////////////////////////////////////////////////

void TestSList();