#define LIST_H

#include <stack>

struct ListNode
{
	int key;
	ListNode *next;
};

unsigned int GetListLength(ListNode *pHead);

ListNode *ReverseList(ListNode *pHead);

ListNode *RGetKthNode(ListNode *pHead, unsigned int k);

ListNode *getMidNode(ListNode *pHead);

void RPrintListByStack(ListNode *pHead);

void RPrintListByR(ListNode *pHead);

ListNode *MergeSortedList(ListNode *pHead1, ListNode *pHead2);

ListNode *MergeSortedListR(ListNode *pHead1, ListNode *pHead2);

bool HasCircle(ListNode *pHead);

bool IsIntersected(ListNode *pHead1, ListNode *pHead2);

ListNode *GetFirstCommonNode(ListNode *pHead1, ListNode *pHead2);

ListNode *GetFirstNodeInCircle(ListNode *pHead);

