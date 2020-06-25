#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"
#include <stdio.h>
void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");
}
void InsertSort(int array[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		//单个元素插入
		int key = array[i];
		int end = i - 1;
		//找待插入元素在区间中的位置
		while (key < array[end])
		{
			array[end + 1] = array[end];
			end--;
		}
		//插入元素
		array[end + 1] = key;
	}
}


//////////////////////////////////////////////
void TestSort()
{
	int array[] = { 4, 1, 7, 6, 3, 9, 5, 8, 0, 2 };
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	InsertSort(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
}