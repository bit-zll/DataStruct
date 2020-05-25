#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
//void right_move(int* str, int k,int sz)
//{
//	assert(str);
//	for (int i = 0; i < k; i++)
//	{
//		int tmp = *(str + sz - 1);
//		for (int j = sz - 1; j > 0; j--)
//		{
//			*(str + j) = *(str + j - 1);
//		}
//		*str = tmp;
//	}
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6 };
//	int k = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	scanf("%d", &k);
//	right_move(arr, k, sz);
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

int* addToArrayForm(int* A, int ASize, int K)
{
	int sz = ASize > 5 ? ASize + 1 : 6;
	int retSz = sz;
	int* ret = (int*)malloc(sz*sizeof(int));
	int total = ASize;
	while (ASize > 0)
	{
		K += A[ASize - 1];
		ret[sz - 1] = K % 10;
		K /= 10;
		sz--;
		ASize--;
	}
	while (K > 0)
	{
		ret[sz - 1] = K % 10;
		K /= 10;
		sz--;
		total++;
	}
	
	if (total < retSz)
	{
		memmove(ret, ret + (retSz - total), total*sizeof(int));
	}
	return ret;
}
int main()
{
	int A[] = { 1, 2, 5 };
	int K = 30;
	int* ret = addToArrayForm(A, 3, K);
	for (int i = 0; i < 3; i++)
	{
		printf("%d ",*(ret + i));
	}
	return 0;
}