#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void ShellSort(int array[], int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < size; ++i)
		{
			int key = array[i];
			int end = i - gap;
			while (end >= 0 && key < array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}
}
void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}
int main()
{
	int array[] = { 4, 1, 7, 6, 3, 9, 5, 8, 0, 2 };
	ShellSort(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	return 0;
}