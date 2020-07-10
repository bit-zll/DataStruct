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
void BubbleSort(int array[], int size)
{
	int flag = 0;
	for (int i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (array[j]>array[j + 1])
			{
				Swap(&array[j], &array[j + 1]);
				flag = 1;
			}
		}
		if (!flag)
			return;
	}
}
int main()
{
	int array[] = { 4, 1, 7, 3, 6, 5, 8, 9, 2, 0 };
	int sz = sizeof(array) / sizeof(array[0]);
	BubbleSort(array, sz);
	PrintArray(array, sz);
	return 0;
}