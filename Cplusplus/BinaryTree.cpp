#include "BinaryTree.h"
#include <stdexcept>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

#define MAX(a,b) (a) > (b) ? (a) : (b)

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

/*
求二叉树中的节点个数
思路：
1、如果二叉树为空，节点个数为0
2、如果二叉树不为空，二叉树节点个数=左子树节点个数+右子树节点个数+1
*/

int GetTreeNodeNumR(BinaryTreeNode *root)
{
	if (root == nullptr)
		return 0;
	return GetTreeNodeNumR(root->left) + GetTreeNodeNumR(root->right) + 1;
}

//非递归，利用队列，广度遍历二叉树
int GetTreeNodeNum(BinaryTreeNode *root)
{
	if (root == nullptr)
		return 0;
	int nodeNum = 0;
	queue<BinaryTreeNode *> nodeQ;
	nodeQ.push(root);
	while (!nodeQ.empty())
	{
		BinaryTreeNode * current = nodeQ.front();
		if (current->left != nullptr)
		{
			nodeQ.push(root->left);
		}
		if (current->right != nullptr)
		{
			nodeQ.push(root->right);
		}
		nodeNum++;
	}

	return nodeNum;
}

/*
求二叉树的深度
思路：
1、如果二叉树为空，返回0
2、如果二叉树不为空，二叉树的深度=max（左子树深度，右子树深度）+1
*/
int GetTreeDepth(BinaryTreeNode *root)
{
	if (root == nullptr)
		return 0;

	int leftDepth = GetTreeDepth(root->left);
	int rightDepth = GetTreeDepth(root->right);

	return MAX(leftDepth, rightDepth) + 1;
}

/*
二叉树的遍历：前序、中序和后序
*/
//前序
void preOrderR(BinaryTreeNode *root)
{
	if (root != nullptr)
	{
		cout << root->key << " ";
		preOrderR(root->left);
		preOrderR(root->right);
	}
}

void preOrder(BinaryTreeNode *root)
{
	if (root == nullptr)
	{
		return;
	}

	stack<BinaryTreeNode *> nodeS;
	BinaryTreeNode *node = nullptr;
	nodeS.push(root);
	while (!nodeS.empty())
	{
		node = nodeS.top();
		nodeS.pop();

		cout << node->key << " ";

		if (node->right != nullptr)
			nodeS.push(node->right);

		if (node->left != nullptr)
			nodeS.push(node->left);

	}
	
}

//中序
void inOrderR(BinaryTreeNode *root)
{
	if (root != nullptr)
	{
		inOrderR(root->left);
		cout << root->key << " ";
		inOrderR(root->right);
	}
}

void inOrder(BinaryTreeNode *root)
{
	if (root == nullptr)
		return;

	stack<BinaryTreeNode *> nodeS;
	BinaryTreeNode *current = nullptr;
	nodeS.push(root);

	while (!nodeS.empty())
	{
		current = nodeS.top();

		//如果有左子树，那么还需要继续往下
		if (current->left != nullptr)
		{
			nodeS.push(current->left);
			continue;
		}
		else
		{
			cout << current->key << " ";
			nodeS.pop();
		}

		//判断右子树为不为空
		if (current->right != nullptr)
		{
			nodeS.push(current->right);
		}
	}
}

//后序
void postOrderR(BinaryTreeNode *root)
{
	if (root != nullptr)
	{
		postOrderR(root->left);
		postOrderR(root->right);
		cout << root->key << " ";
	}
}

/*
非递归的后序遍历相比较前序和中序来说，需要使用一个变量来保存前一个访问的节点
通过判断该节点是否是栈顶节点的子节点，从而达到访问完左右孩子以后才进行根节点
的访问，后序遍历入栈的顺序是：根->右孩子->左孩子。
*/
void postOrder(BinaryTreeNode *root)
{
	if (root == nullptr)
		return;

	stack<BinaryTreeNode *> nodeS;
	BinaryTreeNode * current = nullptr; //当前节点
	BinaryTreeNode *preNode = nullptr; //上一个访问的节点
	nodeS.push(root);

	while (!nodeS.empty())
	{
		current = nodeS.top();

		//只有两种情况才可能去访问并出栈
		//1、节点时叶子结点，即无左右孩子
		//2、已经访问过该节点的孩子（左孩子或者右孩子）
		if ((current->left == nullptr && current->right == nullptr) 
			|| (preNode != nullptr && (preNode == current->left || preNode == current->right)))
		{
			cout << current->key << " ";
			nodeS.pop();
			preNode = current;
		}
		else
		{
			if (current->right != nullptr)
				nodeS.push(current->right);

			if (current->left != nullptr)
				nodeS.push(current->left);
		}

	}
	
}