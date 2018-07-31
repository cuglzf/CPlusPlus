

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