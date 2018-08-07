#define BINARYTREE_H

struct BinaryTreeNode
{
	int key;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	BinaryTreeNode *parent; //ָ�򸸽ڵ�
};

BinaryTreeNode *ContractCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder);
BinaryTreeNode *Contract(int *preorder, int *inorder, int length);