#include <stack>
using namespace std;

struct ListNode
{
	int key;
	ListNode *next;
};

/*
ͳ�������еĽڵ�ĸ���
���裺
1���ж������Ƿ�Ϊ��
2���������������м���
3�����ؼ���
ʱ�临�Ӷ�O(n)
*/
unsigned int GetListLength(ListNode *pHead)
{
	//1���ж������Ƿ�Ϊ��
	if (pHead == nullptr)
		return 0;

	unsigned int nLength = 0;
	ListNode *pCurrent = pHead;

	//2������������+ָ�����
	while (pCurrent != nullptr)
	{
		++nLength;
		pCurrent = pCurrent->next;
	}

	//3�����ؼ���
	return nLength;
}

/*
������ת��
���裺
1���ж������Ƿ�Ϊ�ջ�ֻ��һ���ڵ�
2����ͷ��㿪ʼ������ÿɨ��һ���ڵ㣬��Ѹýڵ���뵽�������ǰ��
3������ͷ���ָ��
ʱ�临�Ӷ�O(n)
*/
ListNode * ReverseList(ListNode *pHead)
{
	//1���ж������Ƿ�Ϊ�ջ���ֻ��һ���ڵ�
	if (pHead == nullptr || pHead->next == nullptr)
		return pHead;

	//2������
	ListNode *pCurrent = pHead;
	ListNode *pReverseHead = nullptr;

	while (pCurrent != nullptr)
	{
		//ʹ����ʱ������������pCurrent��
		//������pCurrent�ڵ㵽��������ʱ������
		//pCurrent�ڵ����Ľڵ㶪ʧ
		ListNode *pTemp = pCurrent;
		pCurrent = pCurrent->next;
		//���ýڵ���뵽������ǰͷ
		pTemp->next = pReverseHead;
		pReverseHead = pTemp;
	}
	//3������ͷ���ָ��
	return pReverseHead;
}

/*
���ҵ������е�����K���ڵ㣨K>0��
˼·����������ָ�룬��Ȼ��һ��ָ���ߵ�����ĵ�K���ڵ㣬����ǰ������ָ��ľ������K-1��Ȼ��ǰ������ָ��һ���ߣ�
��ǰ��һ��ָ��ָ�����һ���ڵ�ʱ������ָ����ָ�Ľڵ���ǵ�����K���ڵ�
���裺
1���ж������Ƿ�Ϊ�ջ�k<= 0
2����ǰ���ָ�����ߵ���k���ڵ��λ����
3���ж�����Ľڵ�����Ƿ�С��K
4������ָ��һ���ߣ�ֱ��ǰ��Ľڵ�ָ�����һ���ڵ�
5�����غ����Ǹ�ָ��
*/
ListNode *RGetKthNode(ListNode *pHead, unsigned int k)
{
	//1���ж������Ƿ�Ϊ�գ���k<=0
	if (k <= 0 || pHead == nullptr)
		return nullptr;
	ListNode *pFront = pHead;
	ListNode *pBehind = pHead;

	//2������ǰ���ָ���ߵ���K���ڵ�λ����
	//��ʱ��K���ڵ�����һ���ڵ�ľ�����K-1
	//���K>1
	while (k > 1 && pFront != nullptr)
	{
		pFront = pFront->next;
		--k;
	}

	//3���ڵ����С��K������
	if (k > 1)
		return nullptr;

	//4������ָ��һ���ߣ�ֱ��ǰ���ָ��ָ�����һ���ڵ�
	while (pFront->next != nullptr)
	{
		pFront = pFront->next;
		pBehind = pBehind->next;
	}

	//5�����غ����ָ��
	return pBehind;

}

/*
���ҵ�������м�ڵ�
˼·�����ÿ���ָ�룬�ÿ�ָ��һ������������ָ��һ����һ��������ָ�뵽�����һ���ڵ��ʱ��
��ָ����ָ�Ľڵ�����м�ڵ㣬����n/2+1���ڵ�
���裺
1���ж������Ƿ�Ϊ�ջ�ֻ��һ���ڵ�
2����ָ������������ָ����һ����ֱ����ָ��ָ�����һ���ڵ�
3��������ָ��
*/
ListNode * getMidNode(ListNode *pHead)
{
	//1������Ϊ�ջ�ֻ��һ���ڵ�
	if (pHead == nullptr || pHead->next == nullptr)
		return pHead;

	ListNode *pFront = pHead;
	ListNode *pBehind = pHead;

	//2��ǰָ������������ָ����һ��
	while (pFront->next != nullptr)
	{
		pFront = pFront->next;
		pBehind = pBehind->next;

		if (pFront->next != nullptr)
			pFront = pFront->next;
	}

	//3��������ָ��
	return pBehind;
}

/*
��β��ͷ��ӡ������
˼·��
�������ֵߵ�˳������⣬����Ӧ�þͻ��뵽ջ������ȳ������ԣ���һ��Ҫô�Լ�ʹ��ջ��Ҫô��ϵͳʹ��ջ��Ҳ���ǵݹ顣ע������Ϊ�յ������ʱ�临�Ӷ�ΪO��n��
��������ַ�ʽʵ�֣�1��ʹ��ջ��ʵ�� 2��ʹ�õݹ�
*/
void RPrintListByStack(ListNode *pHead)
{
	stack<ListNode *> s;
	ListNode *pNode = pHead;

	while (pNode != nullptr)
	{
		s.push(pNode);
		pNode = pNode->next;
	}

	while (!s.empty())
	{
		//ÿ��ӡ��һ����Ҫ��ջ
		printf("%d", s.top()->key);
		s.pop();
	}

}

void RPrintListByR(ListNode *pHead)
{
	if (pHead == nullptr)
	{
		return;
	}
	else
	{
		RPrintListByR(pHead->next);
		printf("%d", pHead->key);
	}
}

/*
���������������ϲ���һ�����������
˼·��������ƹ鲢��������ע����������Ϊ�գ�������һ��Ϊ��ʱ�������ֻ��ҪO��1���Ŀռ䡣ʱ�临�Ӷ�ΪO��max(len1, len2)��
*/

ListNode * MergeSortedList(ListNode *pHead1, ListNode *pHead2)
{
	//1���ж������Ƿ�Ϊ��
	if (pHead1 == nullptr)
		return pHead2;
	if (pHead2 == nullptr)
		return pHead1;

	ListNode *pNode1 = pHead1;
	ListNode *pNode2 = pHead2;
	ListNode *mergeHead = nullptr;

	//3�����µ�����ͷָ��ָ���һ���ڵ�
	if (pNode1->key < pNode2->key)
	{
		mergeHead = pNode1;
		mergeHead->next = nullptr;
		pNode1 = pNode1->next;
	}
	else
	{
		mergeHead = pNode2;
		mergeHead->next = nullptr;
		pNode2 = pNode2->next;
	}

	//4�����µ������βָ��ָ���������β�ڵ�
	ListNode *pTemp = mergeHead;

	//5��������������
	while (pNode1 != nullptr && pNode2 != nullptr)
	{
		if (pNode1->key < pNode2->key)
		{
			pTemp->next = pNode1;
			pNode1 = pNode1->next;
			pTemp = pTemp->next;
			pTemp->next = nullptr;
		}
		else
		{
			pTemp->next = pNode2;
			pNode2 = pNode2->next;
			pTemp = pTemp->next;
			pTemp->next = nullptr;
		}
	}

	//6����ʣ������ڵ���뵽�������β��
	if (pNode1 != nullptr)
	{
		pTemp->next = pNode1;
	}
	else
	{
		pTemp->next = pNode2;
	}

	//7�������������ͷָ��
	return mergeHead;
}

//�ݹ��
ListNode *MergeSortedListR(ListNode *pHead1, ListNode *pHead2)
{
	if (pHead1 == nullptr)
		return pHead2;
	if (pHead2 == nullptr)
		return pHead1;

	ListNode *mergeHead = nullptr;
	if (pHead1->key < pHead2->key)
	{
		mergeHead = pHead1;
		mergeHead->next = MergeSortedListR(pHead1->next,pHead2);
	}
	else
	{
		mergeHead = pHead2;
		mergeHead->next = MergeSortedListR(pHead1, pHead2->next);
	}

	return mergeHead;

}