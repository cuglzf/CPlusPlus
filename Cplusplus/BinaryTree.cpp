#include "BinaryTree.h"
#include <stdexcept>

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