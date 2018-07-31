

struct ListNode
{
	int key;
	ListNode *next;
};

/*
统计链表中的节点的个数
步骤：
1、判断链表是否为空
2、遍历链表，并进行计数
3、返回计数
时间复杂度O(n)
*/
unsigned int GetListLength(ListNode *pHead)
{
	//1、判断链表是否为空
	if (pHead == nullptr)
		return 0;

	unsigned int nLength = 0;
	ListNode *pCurrent = pHead;

	//2、遍历：计数+指针后移
	while (pCurrent != nullptr)
	{
		++nLength;
		pCurrent = pCurrent->next;
	}

	//3、返回计数
	return nLength;
}

/*
将链表反转：
步骤：
1、判断链表是否为空或只有一个节点
2、从头结点开始遍历，每扫描一个节点，则把该节点插入到链表的最前面
3、返回头结点指针
时间复杂度O(n)
*/

ListNode * ReverseList(ListNode *pHead)
{
	//1、判断链表是否为空或者只有一个节点
	if (pHead == nullptr || pHead->next == nullptr)
		return pHead;

	//2、遍历
	ListNode *pCurrent = pHead;
	ListNode *pReverseHead = nullptr;

	while (pCurrent != nullptr)
	{
		//使用临时变量用来代替pCurrent，
		//当插入pCurrent节点到新链表中时不至于
		//pCurrent节点后面的节点丢失
		ListNode *pTemp = pCurrent;
		pCurrent = pCurrent->next;
		//将该节点插入到链表最前头
		pTemp->next = pReverseHead;
		pReverseHead = pTemp;
	}
	//3、返回头结点指针
	return pReverseHead;
}