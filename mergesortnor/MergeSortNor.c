#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <string.h>
void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}
void MergeData(int array[], int left, int mid, int right, int temp[])
{
	int index1 = left, index2 = mid, index = left;
	while (index1 < mid&&index2 < right)
	{
		if (array[index1] <= array[index2])
			temp[index++] = array[index1++];
		else
			temp[index++] = array[index2++];
	}
	//[left,mid)�����е����ݻ�û�а�����
	while (index1 < mid)
	{
		temp[index++] = array[index1++];
	}
	//[mid,right)�����е����ݻ�û�а�����
	while (index2 < right)
	{
		temp[index++] = array[index2++];
	}
}
void MergeSortNor(int array[],int size)
{
	int gap = 1;
	int* temp = (int*)malloc(size*array[0]);
	if (NULL == temp)
		return;
	while (gap<size)
	{
		for (int i = 0; i < size;i+=2*gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;
			if (mid>size)
			{
				mid = size;
			}
			if (right>size)
			{
				right = size;
			}
			//[left,mid)��[mid,right)ÿ����������gap������
			MergeData(array, left, mid, right, temp);
		}
		memcpy(array, temp, size*sizeof(array[0]));
		gap *= 2;
	}
	free(temp);
}
int main()
{
	int array[] = { 4, 1, 7, 6, 3, 9, 5, 8, 0, 2 };
	int sz = sizeof(array) / sizeof(array[0]);
	MergeSortNor(array, sz);
	PrintArray(array, sz);
	return 0;
}