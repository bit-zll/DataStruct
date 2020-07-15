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
void CountSort(int array[], int size)
{
	//找数据范围
	int minValue = array[0];
	int maxValue = array[0];
	for (int i = 1; i < size; ++i)
	{
		if (array[i]>maxValue)
			maxValue = array[i];
		if (array[i] < minValue)
			minValue = array[i];
	}
	//计算用来计数的空间个数：maxValue-minValue+1,申请用来保存计数的空间
	int range = maxValue - minValue + 1;
	int* temp = (int*)malloc(range*sizeof(int));
	memset(temp, 0, sizeof(int)*range);
	//统计区间中每个元素出现的个数
	for (int i = 0; i < size; ++i)
		temp[array[i] - minValue]++;
	//回收
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (temp[i]--)
		{
			array[index++] = i + minValue;
		}
	}
	free(temp);
}
int main()
{
	int array[] = { 4, 1, 7, 6, 3, 9, 5, 8, 0, 2 };
	int sz = sizeof(array) / sizeof(array[0]);
	CountSort(array, sz);
	PrintArray(array, sz);
	return 0;
}