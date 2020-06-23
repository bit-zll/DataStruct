#define _CRT_SECURE_NO_WARNINGS 1

#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include <math.h>
//单值二叉树
//如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树


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

//二叉树的最大深度
int maxDepth(struct TreeNode* root)
{
	if (NULL == root)
		return 0;
	int leftHeight = maxDepth(root->left);
	int rightHeight = maxDepth(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

//翻转二叉树
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

//检查两棵树是否相同
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

//对称二叉树
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

//前序遍历

//获取二叉树中节点个数
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
//returnSize:输出型参数---类似于另外一种返回的方式---即通过参数将返回值带出去
//返回值;1.返回空间的首地址2.空间元素个数：通过returnSize参数带出去
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

//平衡二叉树
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
	//检测根节点是否满足平衡性
	int leftHeight = Height(root->left);
	int rightHeight = Height(root->right);
	if (abs(rightHeight - leftHeight) > 1)
		return false;
	//递归检测根节点的左右子树是否满足平衡树的性质
	return isBalanced(root->left) && isBalanced(root->right);
}