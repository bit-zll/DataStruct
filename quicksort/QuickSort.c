#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void PirntArray(int array[], int size)
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
//三数取中法：三个数据最中间的数据作为基准值
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
//hore法
//int Partion1(int array[], int left, int right)
//{
//	int begin = left;
//	int end = right - 1;
//	int keyofindex = GetMiddleIndex(array, left, right);
//	int key;
//	if (keyofindex != right - 1)
//		Swap(&array[keyofindex], &array[right - 1]);
//	key = array[right - 1];
//	while (begin<end)
//	{
//		//让begin从前往后找，找比基准值大的元素，找到了就停下来
//		while (begin<end&&array[begin] <= key)
//			begin++;
//		//让end从后往前找，找比基准值小的元素，找到了就停下来
//		while (begin<end&&array[end] >= key)
//			end--;
//		if (begin<end)
//			Swap(&array[begin], &array[end]);
//	}
//	if (begin!=right-1)
//		Swap(&array[begin], &array[right - 1]);
//	return begin;
//}
//挖坑法
//int Partion2(int array[], int left, int right)
//{
//	int begin = left;
//	int end = right - 1;
//	int keyofindex = GetMiddleIndex(array, left, right);
//	int key;
//	if (keyofindex != right - 1)
//		Swap(&array[keyofindex], &array[right - 1]);
//	key = array[right - 1];
//	while (begin<end)
//	{
//		//让begin从前往后找，找比基准值大的元素，找到了就停下来
//		while (begin<end&&array[begin] <= key)
//			begin++;
//		//让begin位置大的元素填end位置的坑
//		if (begin < end)
//		{
//			array[end] = array[begin];
//			end--;
//		}
//		//begin位置形成了一个新坑
//		//让end从后往前找比基准值小的元素，填begin位置的坑
//		//让end从后往前找，找比基准值小的元素，找到了就停下来
//		while (begin<end&&array[end] >= key)
//			end--;
//		if (begin < end)
//		{
//			array[begin] = array[end];
//			begin++;
//		}
//	}
//	//用基准值填最后一个坑
//	array[begin] = key;
//	return begin;
//}
//前后指针法
int Partion3(int array[], int left, int right)
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
//[left,right)表示待排序元素的区间
void QuickSort(int array[], int left, int right)
{
	if (right - left>1)
	{
		//Partion按照基准值对区间进行划分成两部分
		//左部分元素比基准值小，右侧部分比基准值大
		int div = Partion3(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}

int main()
{
	int array[] = { 4, 1, 7, 2, 6, 5, 9, 8, 0, 3 };
	int sz = sizeof(array) / sizeof(array[0]);
	QuickSort(array, 0, sz);
	PirntArray(array, sz);
	return 0;
}