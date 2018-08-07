#include "BinaryTree.h"
#include <stdexcept>

/*
剑指offer面试题7
题目：输入某二叉树的前序和中序，求后序序列
思路：
前序中的第一个元素就是根节点，再到中序序列中找到该元素
然后将中序一分为2，左子树和右子树再分别递归构建
需要注意一点的是，当确定了元素在中序薛烈中的位置，就知道左右子树
的长度，使用前序根节点+长度，则把前序序列也同样可以分为左右两个子树
*/
BinaryTreeNode *Contract(int *preorder, int *inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;
	return ContractCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode *ContractCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder)
{
	//前序遍历的第一个节点就是根节点
	int rootValue = startPreorder[0];
	BinaryTreeNode *root = new BinaryTreeNode();
	root->key = rootValue;
	root->left = nullptr;
	root->right = nullptr;

	//当根节点无左右子树后，准备返回
	if (startPreorder == endPreorder)
	{
		//检查两个数组是否合法
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			throw std::exception("invalid input");
	}

	//当根节点有左右子树，则需要找到在中序序列中找到这个根节点
	int *rootInorder = startInorder;
	while (rootInorder != endInorder && *rootInorder != rootValue)
		++rootInorder;

	//判断是否找到了
	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("invalid input");

	//中序中的左子树
	int leftLength = rootInorder - startInorder;
	//前序中的左子树
	int *leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		//构建左子树
		root->left = ContractCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		//构建右子树
		root->right = ContractCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}

	return root;
}

/*
剑指offer面试题8
给定一个二叉树和其中一个节点，如何找出中序遍历的下一个节点
该二叉树中的节点除了有指向左右子树的两个指针外还有一个指向父节点的指针
思路：
这种题，给一颗二叉树，给定其中一个节点，找其前序、中序、后序的下一个节点，
关键是要将所有的情况考虑全,自己画一个二叉树，然后将所有的情况分析出来。
这里情况分为以下几种：
1、如果该节点有右子树，那么中序遍历的下一个节点就是它的右子树中的最左节点
2、如果该节点没有右子树，这里可以分为
   2.1、如果该节点是其父节点的左孩子，那么中序遍历的下一个节点就是其父节点
   2.2、如果该节点是其父节点的右孩子，那么中序遍历的下一个节点就要沿着它的
        父节点往上找，一直找到一个其是其父节点的左孩子的节点，这个节点就是
		中序遍历的下一个节点，或者遍历到根节点也没有找到，返回空。
*/
BinaryTreeNode *GetNext(BinaryTreeNode *pNode)
{
	if (pNode == nullptr)
		return nullptr;

	//用于返回找到的节点
	BinaryTreeNode *pNext = nullptr;

	//1、如果该节点有右子树
	if (pNode->right != nullptr)
	{
		BinaryTreeNode *leftNode = pNode->right;
		while (leftNode->left != nullptr)
		{
			leftNode = leftNode->left;
		}
		pNext = leftNode;
	}
	
	else if (pNode->parent != nullptr)
	{
		BinaryTreeNode *pParent = pNode->parent;

		//2.1 如果该节点是其父节点的左孩子
		if (pNode == pParent->left)
			pNext = pParent;
		//2.2 如果该节点是其父节点的右孩子
		else
		{
			while (pParent->parent != nullptr)
			{
				if (pParent == pParent->parent->left)
				{
					pNext = pParent->parent;
					break;
				}
				pParent = pParent->parent;
			}
		}
	}

	return pNext;
}