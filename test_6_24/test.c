#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
//二叉树遍历
typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	char ch;
}TreeNode;

TreeNode* BuyTreeNode(char ch)
{
	TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
	if (NULL == newnode)
	{
		return NULL;
	}
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->ch = ch;
	return newnode;
}

void InOrder(TreeNode* root)
{
	if (root)
	{
		InOrder(root->left);
		printf("%c ", root->ch);
		InOrder(root->right);
	}
}

TreeNode* CreatBinTree(char szTree[], int size, int* index, char invalid)
{
	TreeNode* root = NULL;
	if (*index < size&&szTree[*index] != invalid)
	{
		//创建根节点
		root = BuyTreeNode(szTree[*index]);
		//创建根节点的左子树
		++(*index);
		root->left = CreatBinTree(szTree, size, index, invalid);
		//创建根节点的右子树
		++(*index);
		root->right = CreatBinTree(szTree, size, index, invalid);
	}
	return root;
}
int main()
{
	char szTree[100] = { 0 };
	int size = strlen(szTree);
	int index = 0;
	while (EOF != scanf("%s", szTree))
	{
		TreeNode* root = CreatBinTree(szTree, size, &index, "#");
		InOrder(root);
		printf("\n");
	}
	return 0;
}

//另一个树的子树

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


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
bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
	if (NULL == s)
		return false;
	//s树存在 t树不存在
	if (NULL == t)
		return true;
	//s和t都不为空
	//根节点一样
	if (s->val == t->val&&isSameTree(s, t))
		return true;

	return isSubtree(s->left, t) || isSubtree(s->right, t);
}