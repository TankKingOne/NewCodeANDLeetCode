#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

BTNode* BinaryTreeBuy(BTDataType x)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	newNode->_data = x;
	newNode->_left = NULL;
	newNode->_right = NULL;
	return newNode;
}

BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = BinaryTreeBuy(a[*pi]);
		(*pi)++;
		root->_left = BinaryTreeCreate(a, n, pi);
		(*pi)++;
		root->_right = BinaryTreeCreate(a, n, pi);
		return root;
	}
	else
		return NULL;
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
	root = NULL;
}

int main()
{
	char arr[100];
	scanf("%s", arr);
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	BTNode* root = BinaryTreeCreate(arr, sz, &i);
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreeDestory(root);

	return 0;
}