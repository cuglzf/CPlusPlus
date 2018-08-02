#include "list.h"

using namespace std;
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

/*
查找单链表中倒数第K个节点（K>0）
思路：利用两个指针，显然第一个指针走到正向的第K个节点，这样前后两个指针的距离差是K-1，然后前后两个指针一起走，
当前面一个指针指向最后一个节点时，后面指针所指的节点就是倒数第K个节点
步骤：
1、判断链表是否为空或k<= 0
2、让前面的指针先走到第k个节点的位置上
3、判断链表的节点个数是否小于K
4、两个指针一起走，直到前面的节点指向最后一个节点
5、返回后面那个指针
*/
ListNode *RGetKthNode(ListNode *pHead, unsigned int k)
{
	//1、判断链表是否为空，或k<=0
	if (k <= 0 || pHead == nullptr)
		return nullptr;
	ListNode *pFront = pHead;
	ListNode *pBehind = pHead;

	//2、先让前面的指针走到第K个节点位置上
	//此时第K个节点距离第一个节点的距离是K-1
	//因此K>1
	while (k > 1 && pFront != nullptr)
	{
		pFront = pFront->next;
		--k;
	}

	//3、节点个数小于K，返回
	if (k > 1)
		return nullptr;

	//4、两个指针一起走，直到前面的指针指向最后一个节点
	while (pFront->next != nullptr)
	{
		pFront = pFront->next;
		pBehind = pBehind->next;
	}

	//5、返回后面的指针
	return pBehind;

}

/*
查找单链表的中间节点
思路：利用快慢指针，让块指针一次走两步，慢指针一次走一步，当块指针到达最后一个节点的时候
满指针所指的节点就是中间节点，即（n/2+1）节点
步骤：
1、判断链表是否为空或只有一个节点
2、快指针走两步，慢指针走一步，直到快指针指向最后一个节点
3、返回慢指针
*/
ListNode * getMidNode(ListNode *pHead)
{
	//1、链表为空或只有一个节点
	if (pHead == nullptr || pHead->next == nullptr)
		return pHead;

	ListNode *pFront = pHead;
	ListNode *pBehind = pHead;

	//2、前指针走两步，后指针走一步
	while (pFront->next != nullptr)
	{
		pFront = pFront->next;
		pBehind = pBehind->next;

		if (pFront->next != nullptr)
			pFront = pFront->next;
	}

	//3、返回慢指针
	return pBehind;
}

/*
从尾到头打印单链表
思路：
对于这种颠倒顺序的问题，我们应该就会想到栈，后进先出。所以，这一题要么自己使用栈，要么让系统使用栈，也就是递归。注意链表为空的情况。时间复杂度为O（n）
因此有两种方式实现：1、使用栈来实现 2、使用递归
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
		//每打印完一个就要出栈
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
将两个有序的链表合并成一个有序的链表
思路：这个类似归并排序。尤其注意两个链表都为空，和其中一个为空时的情况。只需要O（1）的空间。时间复杂度为O（max(len1, len2)）
*/

ListNode * MergeSortedList(ListNode *pHead1, ListNode *pHead2)
{
	//1、判断链表是否为空
	if (pHead1 == nullptr)
		return pHead2;
	if (pHead2 == nullptr)
		return pHead1;

	ListNode *pNode1 = pHead1;
	ListNode *pNode2 = pHead2;
	ListNode *mergeHead = nullptr;

	//3、将新的链表头指针指向第一个节点
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

	//4、将新的链表的尾指针指向新链表的尾节点
	ListNode *pTemp = mergeHead;

	//5、遍历两个链表
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

	//6、将剩余链表节点接入到新链表的尾部
	if (pNode1 != nullptr)
	{
		pTemp->next = pNode1;
	}
	else
	{
		pTemp->next = pNode2;
	}

	//7、返回新链表的头指针
	return mergeHead;
}

//递归版
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
判断一个单链表链表是否有环
思路：如果链表有环，则从头遍历是永远走不到尾的，因此采用快慢指针，如果两个
指针相遇，则证明有环
步骤：
1、判断头指针和下一个指针是否为空，任意一个为空表示链表有限
2、使快指针走两步，慢指针走一步
3、判断两个指针是否相遇
*/
bool HasCircle(ListNode *pHead)
{
	ListNode *pFast = pHead;
	ListNode *pSlow = pHead;

	while (pFast != nullptr && pFast->next != nullptr)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;

		//若相遇则表示有环
		if (pFast == pSlow)
		{
			return true;
		}

	}
	return false;
}

/*
判断两个单链表是否相交
思路：如果两个链表相交于某一节点，那么在这个相交节点之后的所有节点都是两个链表所共有的。也就是说，如果两个链表相交，那么最后一个节点肯定是共有的
此时两个链表构成了Y形状，先遍历第一个链表，记住最后一个节点，然后遍历第二个链表，到最后一个节点时和第一个链表的最后一个节点做比较，
如果相同，则相交，否则不相交。时间复杂度为O(len1+len2)，因为只需要一个额外指针保存最后一个节点地址
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
求两个单链表相交的第一个节点
思路：在上一个问题上，这个问题做了进一步扩展，首先
对第一个链表遍历，计算长度len1，同时保存最后一个节点的地址。
对第二个链表遍历，计算长度len2，同时检查最后一个节点是否和第一个链表的最后一个节点相同，若不相同，不相交，结束。
两个链表均从头节点开始，假设len1大于len2，那么将第一个链表先遍历len1-len2个节点，此时两个链表当前节点到第一个相交节点的距离就相等了，然后一起向后遍历，知道两个节点的地址相同。
时间复杂度，O(len1+len2)
*/
ListNode *GetFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
	if (pHead1 == nullptr || pHead2 == nullptr)
		return nullptr;

	//得到pHead1的尾节点
	ListNode *pTail1 = pHead1;
	int len1 = 1;
	while (pTail1->next != nullptr)
	{
		pTail1 = pTail1->next;
		++len1;
	}

	//得到pHead2的尾节点
	ListNode *pTail2 = pHead2;
	int len2 = 1;
	while (pTail2->next != nullptr)
	{
		pTail2 = pTail2->next;
		++len2;
	}

	//判断两个尾节点是否相等
	if (pTail1 != pTail2)
		return nullptr;

	pTail1 = pHead1;
	pTail2 = pHead2;

	//时长的那个链表先走长出来的那部分
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

	//两个指针再同时走，知道相遇
	while (pTail1 != pTail2)
	{
		pTail1 = pTail1->next;
		pTail2 = pTail2->next;
	}

	//返回相遇节点
	return pTail1;
}