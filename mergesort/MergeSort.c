#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <malloc.h>
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
void _MergeSort(int array[], int left, int right, int temp[])
{
	if (right - left>1)
	{
		int mid = left + ((right - left) >> 1);
		//[left,mid)
		_MergeSort(array, left, mid, temp);
		//[mid,right)
		_MergeSort(array, mid, right, temp);
		//��[left,mid)��[mid,right)����������й鲢
		MergeData(array, left, mid, right, temp);
		//�鲢��֮��ת�Ƶ�array��
		memcpy(array + left, temp + left, (right - left)*sizeof(array[left]));
	}
}
void MergeSort(int array[], int size)
{
	int* temp = (int*)malloc(size*sizeof(array[0]));
	if (NULL == temp)
		return;
	_MergeSort(array, 0, size, temp);
	free(temp);
}

int main()
{
	int array[] = { 4, 1, 7, 6, 3, 9, 5, 8, 0, 2 };
	int sz = sizeof(array) / sizeof(array[0]);
	MergeSort(array, sz);
	PrintArray(array, sz);
	return 0;
}