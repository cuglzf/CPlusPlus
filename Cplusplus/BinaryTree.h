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

int GetTreeNodeNumR(BinaryTreeNode *root);
int GetTreeNodeNum(BinaryTreeNode *root);

int GetTreeDepth(BinaryTreeNode *root);

void preOrderR(BinaryTreeNode *root);
void preOrder(BinaryTreeNode *root);

void inOrderR(BinaryTreeNode *root);
void inOrder(BinaryTreeNode *root);

void postOrderR(BinaryTreeNode *root);
void postOrder(BinaryTreeNode *root);

void LevelTraverse(BinaryTreeNode *root);

void Convert(BinaryTreeNode *root, BinaryTreeNode *pFirst, BinaryTreeNode *pLast);

int GetNodeNumKthLevel(BinaryTreeNode *root, int k);

int GetLeafNodeNum(BinaryTreeNode *root);