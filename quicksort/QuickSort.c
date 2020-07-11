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
//����ȡ�з��������������м��������Ϊ��׼ֵ
int GetMiddleIndex(int array[], int left, int right)
{
	int mid = left + ((right - left) >> 1);
	//�������ݣ�left,mid,right-1
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
//hore��
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
//		//��begin��ǰ�����ң��ұȻ�׼ֵ���Ԫ�أ��ҵ��˾�ͣ����
//		while (begin<end&&array[begin] <= key)
//			begin++;
//		//��end�Ӻ���ǰ�ң��ұȻ�׼ֵС��Ԫ�أ��ҵ��˾�ͣ����
//		while (begin<end&&array[end] >= key)
//			end--;
//		if (begin<end)
//			Swap(&array[begin], &array[end]);
//	}
//	if (begin!=right-1)
//		Swap(&array[begin], &array[right - 1]);
//	return begin;
//}
//�ڿӷ�
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
//		//��begin��ǰ�����ң��ұȻ�׼ֵ���Ԫ�أ��ҵ��˾�ͣ����
//		while (begin<end&&array[begin] <= key)
//			begin++;
//		//��beginλ�ô��Ԫ����endλ�õĿ�
//		if (begin < end)
//		{
//			array[end] = array[begin];
//			end--;
//		}
//		//beginλ���γ���һ���¿�
//		//��end�Ӻ���ǰ�ұȻ�׼ֵС��Ԫ�أ���beginλ�õĿ�
//		//��end�Ӻ���ǰ�ң��ұȻ�׼ֵС��Ԫ�أ��ҵ��˾�ͣ����
//		while (begin<end&&array[end] >= key)
//			end--;
//		if (begin < end)
//		{
//			array[begin] = array[end];
//			begin++;
//		}
//	}
//	//�û�׼ֵ�����һ����
//	array[begin] = key;
//	return begin;
//}
//ǰ��ָ�뷨
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
//[left,right)��ʾ������Ԫ�ص�����
void QuickSort(int array[], int left, int right)
{
	if (right - left>1)
	{
		//Partion���ջ�׼ֵ��������л��ֳ�������
		//�󲿷�Ԫ�رȻ�׼ֵС���Ҳಿ�ֱȻ�׼ֵ��
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