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
		//��[begin,end]��������������С��Ԫ��
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
		//���Ԫ�ط����
		if (maxPos != end)
			Swap(&array[maxPos], &array[end]);
		//���endλ�ô洢�ĸպ�����СԪ�أ�����Ľ����ͽ���СԪ��λ�ø�����
		//��СԪ��λ�÷����˸ı䣬��������minPos
		if (minPos == end)
			minPos = maxPos;
		//��СԪ�ط���ǰ
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