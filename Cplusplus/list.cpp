#include "list.h"

using namespace std;

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
	if (k > 1 )
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
		mergeHead->next = MergeSortedListR(pHead1->next, pHead2);
	}
	else
	{
		mergeHead = pHead2;
		mergeHead->next = MergeSortedListR(pHead1, pHead2->next);
	}

	return mergeHead;

}

/*
�ж�һ�������������Ƿ��л�
˼·����������л������ͷ��������Զ�߲���β�ģ���˲��ÿ���ָ�룬�������
ָ����������֤���л�
���裺
1���ж�ͷָ�����һ��ָ���Ƿ�Ϊ�գ�����һ��Ϊ�ձ�ʾ��������
2��ʹ��ָ������������ָ����һ��
3���ж�����ָ���Ƿ�����
*/
bool HasCircle(ListNode *pHead)
{
	ListNode *pFast = pHead;
	ListNode *pSlow = pHead;

	while (pFast != nullptr && pFast->next != nullptr)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;

		//���������ʾ�л�
		if (pFast == pSlow)
		{
			return true;
		}

	}
	return false;
}

/*
�ж������������Ƿ��ཻ
˼·��������������ཻ��ĳһ�ڵ㣬��ô������ཻ�ڵ�֮������нڵ㶼���������������еġ�Ҳ����˵��������������ཻ����ô���һ���ڵ�϶��ǹ��е�
��ʱ������������Y��״���ȱ�����һ��������ס���һ���ڵ㣬Ȼ������ڶ������������һ���ڵ�ʱ�͵�һ����������һ���ڵ����Ƚϣ�
�����ͬ�����ཻ�������ཻ��ʱ�临�Ӷ�ΪO(len1+len2)����Ϊֻ��Ҫһ������ָ�뱣�����һ���ڵ��ַ
*/
bool IsIntersected(ListNode *pHead1, ListNode *pHead2)
{
	if (pHead1 == nullptr || pHead2 == nullptr)
		return false;

	ListNode *pTail1 = pHead1;
	while (pTail1->next != nullptr)
		pTail1 = pTail1->next;

	ListNode *pTail2 = pHead2;
	while (pTail2->next != nullptr)
		pTail2 = pTail2->next;

	return pTail1 == pTail2;
}

/*
�������������ཻ�ĵ�һ���ڵ�
˼·������һ�������ϣ�����������˽�һ����չ������
�Ե�һ��������������㳤��len1��ͬʱ�������һ���ڵ�ĵ�ַ��
�Եڶ���������������㳤��len2��ͬʱ������һ���ڵ��Ƿ�͵�һ����������һ���ڵ���ͬ��������ͬ�����ཻ��������
�����������ͷ�ڵ㿪ʼ������len1����len2����ô����һ�������ȱ���len1-len2���ڵ㣬��ʱ��������ǰ�ڵ㵽��һ���ཻ�ڵ�ľ��������ˣ�Ȼ��һ����������֪�������ڵ�ĵ�ַ��ͬ��
ʱ�临�Ӷȣ�O(len1+len2)
*/
ListNode *GetFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
	if (pHead1 == nullptr || pHead2 == nullptr)
		return nullptr;

	//�õ�pHead1��β�ڵ�
	ListNode *pTail1 = pHead1;
	int len1 = 1;
	while (pTail1->next != nullptr)
	{
		pTail1 = pTail1->next;
		++len1;
	}

	//�õ�pHead2��β�ڵ�
	ListNode *pTail2 = pHead2;
	int len2 = 1;
	while (pTail2->next != nullptr)
	{
		pTail2 = pTail2->next;
		++len2;
	}

	//�ж�����β�ڵ��Ƿ����
	if (pTail1 != pTail2)
		return nullptr;

	pTail1 = pHead1;
	pTail2 = pHead2;

	//ʱ�����Ǹ��������߳��������ǲ���
	if (len1 > len2)
	{
		int k = len1 - len2;
		while (k--)
			pTail1 = pTail1->next;
	}
	else
	{
		int k = len2 - len1;
		while (k--)
			pTail2 = pTail2->next;
	}

	//����ָ����ͬʱ�ߣ�֪������
	while (pTail1 != pTail2)
	{
		pTail1 = pTail1->next;
		pTail2 = pTail2->next;
	}

	//���������ڵ�
	return pTail1;
}

/*
��֪һ���������д��ڻ�������뻷�еĵ�һ���ڵ�
�����ж��Ƿ���ڻ����������ڽ������ڻ��е����ÿ���ָ���ҵ��������Ǹ��ڵ㴦�Ͽ�����Ȼ��������ʱ�����ƻ�ԭ������
�������γ��������ཻ�ĵ���������������������һ��������������ͷ�����Ϊ����ͷ��㣬��һ��
�����ڻ��ڶϿ��ڵ����һ���ڵ���Ϊͷ��㣬��������뻷�еĵ�һ���ڵ�Ҳ��ת������������
�������ཻ�ĵ�һ���ڵ㡣

*/
ListNode *GetFirstNodeInCircle(ListNode *pHead)
{
	if (pHead == nullptr || pHead->next == nullptr)
		return nullptr;

	//�ҵ����������Ľڵ�
	ListNode *pFast = pHead->next;
	ListNode *pSlow = pHead;

	while (pFast->next != nullptr)
	{
		//��ָ����һ��
		pSlow = pSlow->next;

		//��ָ��������
		pFast = pFast->next;
		if (pFast->next != nullptr)
			pFast = pFast->next;
	}

	if (pFast == nullptr )
		return nullptr;

	//һ�������������������ͷ�����Ϊͷ���
	ListNode *pHead1 = pHead;
	//һ���������Ի��������Ľڵ����һ���ڵ���Ϊͷ�ڵ�
	ListNode *pHead2 = pFast->next;
	//���������ڵ���Ϊβ�ڵ�
	ListNode *pTail = pFast;

	//�����һ��������ĳ���
	int len1 = 1;
	while (pHead1 != pTail)
	{
		++len1;
		pHead1 = pHead1->next;
	}

	//����ڶ���������ĳ���
	int len2 = 1;
	while (pHead2 != pTail)
	{
		++len2;
		pHead2 = pHead2->next;
	}

	pHead1 = pHead;
	pHead2 = pFast;

	//�ó����Ǹ���������|len2-len1|��
	if (len1 > len2)
	{
		int k = len1 - len2;
		while (k--)
			pHead1 = pHead1->next;
	}
	else
	{
		int k = len2 - len1;
		while (k--)
			pHead2 = pHead2->next;
	}

	//������ָ��ͬʱ�ߣ������ĵ�һ���ڵ��������ڵ�
	while (pHead1 != pHead2)
	{
		pHead1 = pHead1->next;
		pHead2 = pHead2->next;
	}

	return pHead1;
}

/*
����һ������ͷָ��pHead��һ�ڵ�ָ��pToBeDeleted��O(1)ʱ�临�Ӷ�ɾ���ڵ�pToBeDeleted
����ɾ���ڵ㣬������ͨ��˼·�����øýڵ��ǰһ���ڵ�ָ��ýڵ����һ���ڵ㣬���������Ҫ
�����ҵ��ýڵ��ǰһ���ڵ㣬ʱ�临�Ӷ�ΪO(n)���������������е�ÿ���ڵ�ṹ����һ���ģ�
�������ǿ��԰Ѹýڵ����һ���ڵ�����ݸ��Ƶ��ýڵ㣬Ȼ��ɾ����һ���ڵ㼴�ɡ�Ҫע��pToBeDeleted
ָ��������һ���ڵ����������ʱ��ֻ���ó����ķ��������������ҵ�ǰһ���ڵ㣬�������ƽ��ʱ�临�ӶȻ���O(1)��
˼·��
�������ɾ����ʱ����Ҫ�������¼��������
1��Ҫɾ������β�ڵ�
  1.1������ֻ��һ���ڵ㣬ͷָ����NULL
  1.2���������ڵ㣬�����ҵ�ǰ��һ���ڵ㣬next��NULL
2��Ҫɾ�����Ƿ�β�ڵ�
  ֻ��Ҫ��������ڵ��ֵ��������ɾ������Ľڵ�
*/
void Delete(ListNode **pHead, ListNode *pToBeDeleted)
{
	//�߽���
	if (*pHead == nullptr || pToBeDeleted == nullptr)
		return;

	//�������
	if (pToBeDeleted->next != nullptr)
	{
		ListNode *pTemp = pToBeDeleted->next;
		pToBeDeleted->key = pTemp->key;
		pToBeDeleted->next = pTemp->next;
		delete pTemp;
	}
	else
	{
		//ֻ��һ���ڵ�
		if (*pHead == pToBeDeleted)
		{
			*pHead = nullptr;
			delete pToBeDeleted;
		}
		else //����ڵ㣬����Ҫɾ��β�ڵ�
		{
			ListNode *pNode = *pHead;
			while (pNode->next != pToBeDeleted && pNode->next != nullptr)
				pNode = pNode->next;

			pNode->next = nullptr;
			delete pToBeDeleted;
		}
	}

}