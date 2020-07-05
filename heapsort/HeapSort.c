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
//向下调整
void HeapAdjust(int array[], int size, int parent)
{
	//用child标记parent较大的孩子，默认先标记parent的左孩子
	int child = parent * 2 + 1;
	while (child < size)
	{
		//找parent中较大的孩子：用parent左右孩子比较
		//必须先保证parent的右孩子存在
		if (child + 1 < size&&array[child + 1] > array[child])
			child += 1;
		//检测parent是否满足堆的性质
		if (array[child]>array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}
void HeapSort(int array[], int size)
{
	int end = size - 1;
	//1.建堆
	//从倒数第一个非叶子节点的位置开始堆调整，一直调整到根节点的位置
	for (int root = (size - 2) / 2; root >= 0; root--)
		HeapAdjust(array, size, root);//向下调整
	//2.排序--利用堆删除的思想进行排序
	while (end)
	{
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}

int main()
{
	int array[] = { 4, 1, 7, 6, 3, 9, 5, 8, 0, 2 };
	HeapSort(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	return 0;
}