#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (SDataType*)malloc(sizeof(SDataType)* 10);
	if (NULL == ps->array)
	{
		assert(0);
		return;
	}
	ps->capacity = 10;
	ps->size = 0;
}
void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		//1.�����¿ռ�
		SDataType* temp = (SDataType*)malloc(sizeof(SDataType)*ps->size * 2);
		if (temp == NULL)
		{
			assert(0);
			return;
		}
		//2.����Ԫ��
		memcpy(temp, ps->array, sizeof(SDataType)*ps->size);
		//3.�ͷžɿռ�
		free(ps->array);
		ps->array = temp;
		ps->capacity *= 2;
	}
}
//��ջ��β��
void StackPush(Stack* ps, SDataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->array[ps->size++] = data;
}
//��ջ��βɾ
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
		return;
	ps->size--;
}
//��ȡջ��Ԫ��
SDataType StackTop(Stack* ps)
{
	assert(!StackEmpty(ps));
	return ps->array[ps->size - 1];
}
//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}
//����Ƿ�Ϊ��
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->size == 0;
}
//����
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->array);
	ps->array = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��

//��Ч�ַ��������㣺
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�

bool isValid(char* s)
{
	Stack st;
	StackInit(&st);
	bool ret = true;
	int len = strlen(s);
	for (int i = 0; i < len; ++i)
	{
		//��������ջ
		if ('(' == s[i] || '[' == s[i] || '{' == s[i])
			StackPush(&st, s[i]);
		else
		{
			//��ǰ����Ϊ�����ţ�����ջ�ǿյ�
			if (StackEmpty(&st))
			{
				ret = false;
				break;
			}
			//��ǰ������������
			char ch = StackTop(&st);
			
			//�õ�ǰ�����ż���Ƿ���ջ����������ƥ��
			if ((ch == '('&&')' == s[i]) || (ch == '['&&']' == s[i]) || (ch == '{'&&'}' == s[i]))
			{
				StackPop(&st);
				continue;
			}
			else
			{
				ret = false;
				break;
			}
		}
	}
	//�����ű������Ŷ�
	if (!StackEmpty(&st))
		ret = false;
	StackDestroy(&st);
	return ret;
}

int main()
{
	char* s = "([{}])";
	bool n = isValid(s);
	printf("%d\n", n);
	return 0;
}