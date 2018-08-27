#include "BinaryTree.h"
#include <stdexcept>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

#define MAX(a,b) (a) > (b) ? (a) : (b)

/*
��ָoffer������7
��Ŀ������ĳ��������ǰ����������������
˼·��
ǰ���еĵ�һ��Ԫ�ؾ��Ǹ��ڵ㣬�ٵ������������ҵ���Ԫ��
Ȼ������һ��Ϊ2�����������������ٷֱ�ݹ鹹��
��Ҫע��һ����ǣ���ȷ����Ԫ��������Ѧ���е�λ�ã���֪����������
�ĳ��ȣ�ʹ��ǰ����ڵ�+���ȣ����ǰ������Ҳͬ�����Է�Ϊ������������
*/
BinaryTreeNode *Contract(int *preorder, int *inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;
	return ContractCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode *ContractCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder)
{
	//ǰ������ĵ�һ���ڵ���Ǹ��ڵ�
	int rootValue = startPreorder[0];
	BinaryTreeNode *root = new BinaryTreeNode();
	root->key = rootValue;
	root->left = nullptr;
	root->right = nullptr;

	//�����ڵ�������������׼������
	if (startPreorder == endPreorder)
	{
		//������������Ƿ�Ϸ�
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			throw std::exception("invalid input");
	}

	//�����ڵ�����������������Ҫ�ҵ��������������ҵ�������ڵ�
	int *rootInorder = startInorder;
	while (rootInorder != endInorder && *rootInorder != rootValue)
		++rootInorder;

	//�ж��Ƿ��ҵ���
	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("invalid input");

	//�����е�������
	int leftLength = rootInorder - startInorder;
	//ǰ���е�������
	int *leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		//����������
		root->left = ContractCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		//����������
		root->right = ContractCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}

	return root;
}

/*
��ָoffer������8
����һ��������������һ���ڵ㣬����ҳ������������һ���ڵ�
�ö������еĽڵ������ָ����������������ָ���⻹��һ��ָ�򸸽ڵ��ָ��
˼·��
�����⣬��һ�Ŷ���������������һ���ڵ㣬����ǰ�����򡢺������һ���ڵ㣬
�ؼ���Ҫ�����е��������ȫ,�Լ���һ����������Ȼ�����е��������������
���������Ϊ���¼��֣�
1������ýڵ�������������ô�����������һ���ڵ���������������е�����ڵ�
2������ýڵ�û����������������Է�Ϊ
   2.1������ýڵ����丸�ڵ�����ӣ���ô�����������һ���ڵ�����丸�ڵ�
   2.2������ýڵ����丸�ڵ���Һ��ӣ���ô�����������һ���ڵ��Ҫ��������
        ���ڵ������ң�һֱ�ҵ�һ�������丸�ڵ�����ӵĽڵ㣬����ڵ����
		�����������һ���ڵ㣬���߱��������ڵ�Ҳû���ҵ������ؿա�
*/
BinaryTreeNode *GetNext(BinaryTreeNode *pNode)
{
	if (pNode == nullptr)
		return nullptr;

	//���ڷ����ҵ��Ľڵ�
	BinaryTreeNode *pNext = nullptr;

	//1������ýڵ���������
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

		//2.1 ����ýڵ����丸�ڵ������
		if (pNode == pParent->left)
			pNext = pParent;
		//2.2 ����ýڵ����丸�ڵ���Һ���
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
��������еĽڵ����
˼·��
1�����������Ϊ�գ��ڵ����Ϊ0
2�������������Ϊ�գ��������ڵ����=�������ڵ����+�������ڵ����+1
*/

int GetTreeNodeNumR(BinaryTreeNode *root)
{
	if (root == nullptr)
		return 0;
	return GetTreeNodeNumR(root->left) + GetTreeNodeNumR(root->right) + 1;
}

//�ǵݹ飬���ö��У���ȱ���������
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
������������
˼·��
1�����������Ϊ�գ�����0
2�������������Ϊ�գ������������=max����������ȣ���������ȣ�+1
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
�������ı�����ǰ������ͺ���
*/
//ǰ��
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

//����
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

		//���������������ô����Ҫ��������
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

		//�ж�������Ϊ��Ϊ��
		if (current->right != nullptr)
		{
			nodeS.push(current->right);
		}
	}
}

//����
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
�ǵݹ�ĺ��������Ƚ�ǰ���������˵����Ҫʹ��һ������������ǰһ�����ʵĽڵ�
ͨ���жϸýڵ��Ƿ���ջ���ڵ���ӽڵ㣬�Ӷ��ﵽ���������Һ����Ժ�Ž��и��ڵ�
�ķ��ʣ����������ջ��˳���ǣ���->�Һ���->���ӡ�
*/
void postOrder(BinaryTreeNode *root)
{
	if (root == nullptr)
		return;

	stack<BinaryTreeNode *> nodeS;
	BinaryTreeNode * current = nullptr; //��ǰ�ڵ�
	BinaryTreeNode *preNode = nullptr; //��һ�����ʵĽڵ�
	nodeS.push(root);

	while (!nodeS.empty())
	{
		current = nodeS.top();

		//ֻ����������ſ���ȥ���ʲ���ջ
		//1���ڵ�ʱҶ�ӽ�㣬�������Һ���
		//2���Ѿ����ʹ��ýڵ�ĺ��ӣ����ӻ����Һ��ӣ�
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

/*
�ֲ����������������˳���մ������£��������ҵ�˳��
*/
void LevelTraverse(BinaryTreeNode *root)
{
	if (root == nullptr)
		return;
	queue<BinaryTreeNode *> nodeQ;
	BinaryTreeNode * current = nullptr;
	nodeQ.push(root);

	while (!nodeQ.empty())
	{
		current = nodeQ.front();
		nodeQ.pop();

		cout << current->key << " ";

		if (current->left != nullptr)
			nodeQ.push(current->left);

		if (current->right != nullptr)
			nodeQ.push(current->right);
	}
}

/*
����������������˫������
root:�������ĸ��ڵ�ָ��
pFirst��˫�������һ���ڵ�ָ��
pLast��˫����������һ���ڵ�ָ��
˼·��
1�����������Ϊ�գ�ֱ�ӷ���
2�������������Ϊ�գ�
   2.1�����������Ϊ�գ����ڵ���˫�������ͷ��㣬����������������˫�����������ڵ�
		����������˫���������ӣ��ŵ������ͷ����
   2.2�������������Ϊ�գ�������������˫��������ʱ�����������������ͷָ���������
		�����ͷָ�룬Ȼ�󽫸��ڵ����ӵ�����β����
   2.3�����������Ϊ�գ����ڵ���˫�������β��㡣
   2.4�������������Ϊ�գ�������������˫���������ڵ�������������ͷ������ӣ�������
		��β�ڵ������������β�ڵ㡣
*/
void Convert(BinaryTreeNode *root, BinaryTreeNode *pFirst, BinaryTreeNode *pLast)
{
	pFirst = nullptr;
	pLast = nullptr;
	if (root == nullptr)
		return;
	
	//��������ͷָ���βָ��
	BinaryTreeNode *pFirstLeft = nullptr;
	BinaryTreeNode *pLastLeft = nullptr;
	//��������ͷָ���βָ��
	BinaryTreeNode *pFirstRight = nullptr;
	BinaryTreeNode *pLastRight = nullptr;

	//1���ȹ�����������˫������Ȼ�󽫸��ڵ�ŵ������������β��
	if (root->left != nullptr)
	{
		//��������������˫������
		Convert(root->left, pFirstLeft, pLastLeft);
		//��������ͷ���������������ͷ���
		pFirst = pFirstLeft;
		//�����ڵ���������������β��
		root->left = pLastLeft;
		pLastLeft->right = root;
	}
	else
	{
		//���������Ϊ�գ����ڵ���������ͷ���
		pFirst = root;
	}

	//2���ٹ�����������˫������Ȼ����������˫����������ڵ�����
	if (root->right != nullptr)
	{
		Convert(root->right, pFirstRight, pLastRight);
		//��������β�ڵ������������β�ڵ�
		pLast = pLastRight;
		//�����ڵ���������ͷ�������
		root->left = pFirstRight;
		pFirstRight->left = root;
	}
	else
	{
		//���ڵ�������������β�ڵ�
		pLast = root;
	}
}

/*
���������k��Ľڵ����
˼·��
1�����������Ϊ�ջ���k<1��ֱ�ӷ���0
2�������������Ϊ����k == 1��ֱ�ӷ���1
3�������������Ϊ����k>1��������������k-1��ڵ�+��������k-1��ڵ�

�����㷨ʹ�õ��ǵݹ��㷨����������õݹ��㷨�����ʵ���أ�
˼·�����Բ�������������ʵ��queue1��queue2�����Ƚ����ڵ����queue1����k--
��k>0ʱ����ѭ��������ȥ��queue1�нڵ㲢�����ӽڵ����queue2ֱ��queue1��
Ԫ��Ϊ�գ�Ȼ��queue2��Ԫ���ٵ��뵽queue1����˷�������󷵻�queue1��
��Ԫ�ظ������Ƕ�������k��Ľڵ������
*/
int GetNodeNumKthLevel(BinaryTreeNode *root, int k)
{
	if (root == nullptr || k < 1)
		return 0;

	if (k == 1)
		return 1;

	int numLeft = GetNodeNumKthLevel(root->left, k - 1);
	int numRight = GetNodeNumKthLevel(root->right, k - 1);

	return (numLeft + numRight);
}

/*
���������Ҷ�ӽڵ�ĸ���
˼·������k��ڵ��������
1�����������Ϊ�գ�����0
2�������������Ϊ������������Ϊ�գ�����1
3�������������Ϊ��������������ͬʱΪ�գ�����
��������Ҷ�ӽڵ����+��������Ҷ�ӽڵ����
*/
int GetLeafNodeNum(BinaryTreeNode *root)
{
	if (root == nullptr)
		return 0;
	
	if (root->left == nullptr && root->right == nullptr)
		return 1;

	int numLeft = GetLeafNodeNum(root->left);
	int numRight = GetLeafNodeNum(root->right);

	return (numLeft + numRight);
}
