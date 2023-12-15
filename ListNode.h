#pragma once

class ListNode
{
private:
	int value;
	ListNode* pNext;
public:
	ListNode(int value);

	friend class LinkedList;
};