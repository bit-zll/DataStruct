#define _CRT_SECURE_NO_WARNINGS 1

#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include <math.h>
//��ֵ������
//���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ������


struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool _isUnivalTree(struct TreeNode* root, int value)
{
	if (NULL == root)
		return true;
	if (root->val != value)
		return false;
	return _isUnivalTree(root->left, value) && _isUnivalTree(root->right, value);
}
bool isUnivalTree(struct TreeNode* root)
{
	if (NULL == root)
		return true;
	int value = root->val;
	return _isUnivalTree(root, value);
}

//��������������
int maxDepth(struct TreeNode* root)
{
	if (NULL == root)
		return 0;
	int leftHeight = maxDepth(root->left);
	int rightHeight = maxDepth(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

//��ת������
struct TreeNode* invertTree(struct TreeNode* root)
{
	if (root)
	{
		struct TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;

		invertTree(root->left);
		invertTree(root->right);
	}
	return root;
}

//����������Ƿ���ͬ
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (NULL == p&&NULL == q)
		return true;
	if (NULL == p || NULL == q)
		return false;
	return p->val == q->val&&
		isSameTree(p->left, q->left) &&
		isSameTree(p->right, q->right);
}

//�Գƶ�����
bool _isSymmetric(struct TreeNode* p, struct TreeNode* q)
{
	if (NULL == p&&NULL == q)
		return true;
	if (NULL == p || NULL == q)
		return false;
	return p->val == q->val&&
		_isSymmetric(p->left, q->right) &&
		_isSymmetric(p->right, q->left);
}
bool isSymmetric(struct TreeNode* root)
{
	if (NULL == root)
		return true;
	return _isSymmetric(root->left, root->right);
}

//ǰ�����

//��ȡ�������нڵ����
int GetSize(struct TreeNode* root)
{
	if (NULL == root)
		return 0;
	return GetSize(root->left) + GetSize(root->right) + 1;
}
void _preorderTraversal(struct TreeNode* root, int* array, int* index)
{
	if (root == NULL)
		return;
	array[(*index)++] = root->val;
	_preorderTraversal(root->left, array, index);
	_preorderTraversal(root->right, array, index);
}
//returnSize:����Ͳ���---����������һ�ַ��صķ�ʽ---��ͨ������������ֵ����ȥ
//����ֵ;1.���ؿռ���׵�ַ2.�ռ�Ԫ�ظ�����ͨ��returnSize��������ȥ
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	*returnSize = GetSize(root);
	int* ret = (int*)malloc((*returnSize)*sizeof(int));
	if (NULL == ret)
		return NULL;
	int index = 0;
	_preorderTraversal(root, ret, &index);
	return ret;
}

//ƽ�������
int Height(struct TreeNode* root)
{
	if (NULL == root)
		return 0;
	int leftHeight = maxDepth(root->left);
	int rightHeight = maxDepth(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}
bool isBalanced(struct TreeNode* root)
{
	if (NULL == root)
		return true;
	//�����ڵ��Ƿ�����ƽ����
	int leftHeight = Height(root->left);
	int rightHeight = Height(root->right);
	if (abs(rightHeight - leftHeight) > 1)
		return false;
	//�ݹ�����ڵ�����������Ƿ�����ƽ����������
	return isBalanced(root->left) && isBalanced(root->right);
}