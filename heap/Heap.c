#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

int Less(HDataType left, HDataType right)
{
	return left < right;
}
int Greater(HDataType left, HDataType right)
{
	return left > right;
}
//��ʼ��һ���ն�
void HeapInit(Heap* hp, int initCap,CMP cmp)
{
	assert(hp);
	initCap = initCap < 10 ? 10 : initCap;
	hp->array = (HDataType*)malloc(sizeof(HDataType)* initCap);
	if (NULL == hp->array)
	{
		assert(0);
		return;
	}
	hp->capacity = initCap;
	hp->size = 0;
	//���ձȽϵķ�ʽ
	hp->Cmp = cmp;
}
//������������
void Swap(HDataType* left, HDataType* right)
{
	HDataType temp = *left;
	*left = *right;
	*right = temp;
}
//���µ���
void AdjustDown(Heap* hp, int parent)
{
	//��child���parent�Ľ�С�ĺ���--Ĭ���ȱ��parent������
	int size = hp->size;
	int *array = hp->array;
	int child = parent * 2 + 1;
	while (child < size)
	{
		//�ҵ�parent���������н�С�ĺ���
		if (child + 1 < size&&hp->Cmp(array[child+1],array[child]))
			child += 1;
		//���parent�Ƿ�����ѵ�����
		if (hp->Cmp(array[child],array[parent]))
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}
//�������е�Ԫ�ش�����
void HeapCreate(Heap* hp, int* array, int size, CMP cmp)
{
	//1.�Ƚ������е�Ԫ�ط��ڶѽṹ��
	HeapInit(hp, size,cmp);
	memcpy(hp->array, array, sizeof(HDataType)*size);
	hp->size = size;
	//2.���е���
	for (int root = (size - 2) / 2; root >= 0; root--)
		AdjustDown(hp, root);
}

void AdjustUP(Heap* hp, int child)
{
	HDataType* array = hp->array;
	int size = hp->size;
	int parent = ((child - 1) >> 1);
	while (child)
	{
		if (hp->Cmp(array[child] , array[parent]))
		{
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = ((child - 1) >> 1);
		}
		else
		{
			return;
		}
	}
}
void CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		//1.�����¿ռ�
		int newCapacity = hp->capacity * 2;
		HDataType* temp = (HDataType*)malloc(sizeof(HDataType)*newCapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		//����Ԫ��
		for (int i = 0; i < hp->size; ++i)
			temp[i] = hp->array[i];
		//3.�ͷžɿռ�
		free(hp->array);
		//4.ʹ���¿ռ�
		hp->array = temp;
		hp->capacity = newCapacity;
	}
}
void HeapPush(Heap* hp, HDataType data)
{
	assert(hp);
	//0.����Ƿ���Ҫ����
	CheckCapacity(hp);
	//1.����Ԫ�ز��뵽�����ĩβ
	hp->array[hp->size++] = data;
	//2.��Ԫ�ز���󣬿��ܻ��ƻ��ѵ�����
	AdjustUP(hp, hp->size - 1);
}
//ɾ���Ѷ�Ԫ��
void HeapPop(Heap* hp)
{
	if (HeapEmpty(hp))
		return;
	Swap(&hp->array[0], &hp->array[hp->size - 1]);
	hp->size--;
	AdjustDown(hp, 0);
}
//��ȡ�Ѷ�Ԫ��
HDataType HeapTop(Heap* hp)
{
	assert(!HeapEmpty(hp));
	return hp->array[0];
}
//��Ϊ�շ��ط���ֵ
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->size;
}
//����Ԫ�ظ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}
void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->capacity = 0;
	hp->size = 0;
}

////////////////////////////////////////////////////////

void TestHeap()
{
	int array[] = { 3, 6, 9, 1, 5, 2, 0, 7, 8, 4 };
	Heap hp;
	HeapCreate(&hp, array, sizeof(array) / sizeof(array[0]),Greater);
	printf("heap size = %d\n", HeapSize(&hp));
	printf("heap top = %d\n", HeapTop(&hp));

	HeapPop(&hp);
	printf("heap size = %d\n", HeapSize(&hp));
	printf("heap top = %d\n", HeapTop(&hp));

	HeapPush(&hp, 0);
	printf("heap size = %d\n", HeapSize(&hp));
	printf("heap top = %d\n", HeapTop(&hp));
    HeapDestroy(&hp);
}