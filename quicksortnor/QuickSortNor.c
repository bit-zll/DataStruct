#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "Stack.h"

void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}
int GetMiddleIndex(int array[], int left, int right)
{
	int mid = left + ((right - left) >> 1);
	//三个数据：left,mid,right-1
	if (array[left]<array[right - 1])
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid]>array[right - 1])
			return right - 1;
		else
			return mid;
	}
	else
	{
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right - 1;
		else
			return mid;
	}
}
int Partion(int array[], int left, int right)
{
	int cur = left;
	int prev = cur - 1;
	int keyofindex = GetMiddleIndex(array, left, right);
	int key;
	if (keyofindex != right - 1)
		Swap(&array[keyofindex], &array[right - 1]);
	key = array[right - 1];
	while (cur<right)
	{
		if (array[cur] < key&&++prev != cur)
			Swap(&array[cur], &array[prev]);
		++cur;
	}
	if (++prev != right - 1)
		Swap(&array[right - 1], &array[prev]);
	return prev;
}
//用栈来将递归转换为循环
void QuickSortNor(int array[], int size)
{
	int left = 0;
	int right = size;
	Stack s;
	StackInit(&s);
	StackPush(&s, right);
	StackPush(&s, left);
	while (!StackEmpty(&s))
	{
		//先按照基准值来进行划分
		left = StackTop(&s);
		StackPop(&s);
		right = StackTop(&s);
		StackPop(&s);
		if (right - left > 1)
		{
			int div = Partion(array, left, right);
			//排基准值的左半侧--将右半部分的区间入栈[div+1,right)
			StackPush(&s, right);
			StackPush(&s, div + 1);
			//排基准值的右半侧--将左半部分的区间入栈[left,div)
			StackPush(&s, div);
			StackPush(&s, left);
		}
	}
	StackDestroy(&s);
}

int main()
{
	int array[] = { 4, 1, 7, 5, 6, 9, 8, 0, 3, 2 };
	int sz = sizeof(array) / sizeof(array[0]);
	QuickSortNor(array, sz);
	PrintArray(array, sz);
	return 0;
}