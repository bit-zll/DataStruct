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
	//�����ݷ�Χ
	int minValue = array[0];
	int maxValue = array[0];
	for (int i = 1; i < size; ++i)
	{
		if (array[i]>maxValue)
			maxValue = array[i];
		if (array[i] < minValue)
			minValue = array[i];
	}
	//�������������Ŀռ������maxValue-minValue+1,����������������Ŀռ�
	int range = maxValue - minValue + 1;
	int* temp = (int*)malloc(range*sizeof(int));
	memset(temp, 0, sizeof(int)*range);
	//ͳ��������ÿ��Ԫ�س��ֵĸ���
	for (int i = 0; i < size; ++i)
		temp[array[i] - minValue]++;
	//����
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