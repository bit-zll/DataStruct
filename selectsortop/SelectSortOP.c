#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

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
void SelectSortOP(int array[], int size)
{
	int begin = 0, end = size - 1;
	while (begin < end)
	{
		//在[begin,end]区间中找最大和最小的元素
		int maxPos = begin, minPos = begin;
		int j = begin + 1;
		while (j <= end)
		{
			if (array[j]>array[maxPos])
				maxPos = j;
			if (array[j] < array[minPos])
				minPos = j;
			++j;
		}
		//最大元素放最后
		if (maxPos != end)
			Swap(&array[maxPos], &array[end]);
		//如果end位置存储的刚好是最小元素，上面的交换就将最小元素位置更改了
		//最小元素位置发生了改变，则必须更新minPos
		if (minPos == end)
			minPos = maxPos;
		//最小元素放最前
		if (minPos != begin)
			Swap(&array[minPos], &array[begin]);
		++begin;
		--end;
	}
}

int main()
{
	int array[] = { 4, 1, 7, 6, 3, 9, 5, 8, 0, 2 };
	SelectSortOP(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	return 0;
}