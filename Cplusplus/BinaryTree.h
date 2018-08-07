#define BINARYTREE_H

struct BinaryTreeNode
{
	int key;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	BinaryTreeNode *parent; //指向父节点
};

BinaryTreeNode *ContractCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder);
BinaryTreeNode *Contract(int *preorder, int *inorder, int length);