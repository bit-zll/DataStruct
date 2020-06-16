#pragma once


typedef int HDataType;

int Less(HDataType left, HDataType right);
int Greater(HDataType left, HDataType right);
//Cmp的函数指针类型变量：Cmp即可以指向Less,也可以指向Greater
int (*Cmp)(HDataType left, HDataType right);

typedef int(*CMP)(HDataType, HDataType);

typedef struct Heap
{
	HDataType* array;
	int capacity;
	int size;
	CMP Cmp; //函数指针
}Heap;


void HeapInit(Heap* hp, int initCap,CMP cmp);
void HeapCreate(Heap* hp, int* array, int size,CMP cmp);
void HeapPush(Heap* hp, HDataType data);
void HeapPop(Heap* hp);
HDataType HeapTop(Heap* hp);
int HeapEmpty(Heap* hp);
int HeapSize(Heap* hp);
void HeapDestroy(Heap* hp);


////////////////////////////////////////////////////
void TestHeap();