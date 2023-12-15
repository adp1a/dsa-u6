#include "LinkedList.h"
#include <cstddef>
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
	pHead = NULL;
}

LinkedList::~LinkedList() {
	ListNode* pTmp;
	while (pHead != NULL) {
		pTmp = pHead;
		pHead = pHead->pNext;
		delete pTmp; pTmp = NULL;
	}
}

bool LinkedList::IsEmpty() const
{
	return (pHead == NULL);
}

int LinkedList::Pocet_Prvku()
{
	int n = 0;
	ListNode* pTmp = pHead;
	while (pTmp != NULL) {
		n++;
		pTmp = pTmp->pNext;
	}
	return n;
}

void LinkedList::MakeList(int* p, int cnt)
{
	ListNode *pTmp, *pLast = NULL;

	for (int i = 0; i < cnt; i++)
	{
		pTmp = new ListNode(*(p + i));
		if (pHead == NULL)
			pHead = pLast = pTmp;
		else
		{
			pLast->pNext = pTmp;
			pLast = pTmp;
		}
	}
}

void LinkedList::Add(int value)
{
	ListNode* pLast, *pItem = new ListNode(value);

	if (pHead == NULL)
		pHead = pItem;
	else
	{
		pLast = pHead;
		while (pLast->pNext != NULL)
			pLast = pLast->pNext;
		pLast->pNext = pItem;
	}
}

void LinkedList::AddHead(int value)
{  
	ListNode* pItem = new ListNode(value);
	pItem->pNext = pHead;
	pHead = pItem;
}

void LinkedList::AddOrder(int value)
{
	ListNode* pTmp = pHead, * pPrev = NULL;
	ListNode* pItem = new ListNode(value);

	while (pTmp != NULL && pTmp->value > value) {
		pPrev = pTmp;
		pTmp = pTmp->pNext;
	}

	pItem->pNext = pTmp;
	if (pPrev == NULL)
		pHead = pItem;
	else
		pPrev->pNext = pItem;
}

void LinkedList::AddPosition(int value, int pos)
{
	int n = 0;
	ListNode *pTmp = pHead, *pPrev = NULL;
	ListNode* pItem;

	while (pTmp != NULL && n < pos)
	{
		pPrev = pTmp;
		pTmp = pTmp->pNext;
		n++;
	}

	if (pTmp != NULL)
	{
		pItem = new ListNode(value);
		pItem->pNext = pTmp;
		if (pTmp == pHead) {
			pHead = pItem;
		}
		else {
			pPrev->pNext = pItem;
		}
	}
}

bool LinkedList::Remove(int value)
{
	ListNode* pPrev = NULL;
	ListNode* pItem = pHead;

	// hledej prvek
	while (pItem != NULL && pItem->value != value)
	{
		pPrev = pItem;
		pItem = pItem->pNext;
	}

	if (pItem != NULL)
	{
		// Pokud jsi nasel, proved odstraneni.
		if (pHead == pItem)
		{
			// odstranuje se prvni prvek seznamu
			pHead = pItem->pNext;
		}
		else
		{
			// odstranuje se prvek seznamu, ktery neni prvni
			pPrev->pNext = pItem->pNext;
		}
		delete pItem;
		return true;
	}
	else
		return false;
}

int LinkedList::RemovePosition(int pos)
{
	int n = 0;
	ListNode* pTmp = pHead, * pPrev = NULL;
	int value;

	while (pTmp != NULL && n < pos)
	{
		pPrev = pTmp;
		pTmp = pTmp->pNext;
		n++;
	}

	if (pTmp == NULL)
		return -1;
	else
	{
		pPrev->pNext = pTmp->pNext;
		value = pTmp->value;
		delete pTmp;
		return value;
	}
}

// -----

int LinkedList::GetAt(int pos)
{
	int n = 0;
	ListNode* pTmp = pHead;

	while (pTmp != NULL && n < pos)
	{
		pTmp = pTmp->pNext;
		n++;
	}

	return pTmp == NULL ? -1 : pTmp->value;
}

void LinkedList::SetAt(int value, int pos)
{
	int n = 0;
	ListNode* pTmp = pHead;

	while (pTmp != NULL && n < pos)
	{
		pTmp = pTmp->pNext;
		n++;
	}

	if (pTmp != NULL)
		pTmp->value = value;
}

bool LinkedList::Contains(int value)
{   
	ListNode* pItem = pHead;

	// hledej prvek
	while (pItem != NULL && pItem->value != value)
		pItem = pItem->pNext;

	return pItem != NULL;
}

int LinkedList::IndexOf(int value)
{
	int n = 0;
	ListNode* pTmp = pHead;

	while (pTmp != NULL && pTmp->value != value)
		n++;

	return pTmp == NULL ? -1 : n;
}

// -----

void LinkedList::Tisk() const
{
	ListNode* pTmp = pHead;
	while (pTmp != NULL)
	{
		cout << pTmp->value << ';';
		pTmp = pTmp->pNext;
	}
}

void LinkedList::TiskReverse(ListNode* pItem)
{
	if (pItem == NULL)
		return;
	TiskReverse(pItem->pNext);
	cout << pItem->value << ';';
}

void LinkedList::TiskReverse()
{
	TiskReverse(pHead);
}

void LinkedList::MoveMinHead() {
	if (pHead == NULL) {
        return;
    }

    ListNode* pMinPrev = NULL;
    ListNode* pMinNode = pHead;
    ListNode* pTmp = pHead->pNext;

    while (pTmp != NULL) {
        if (pTmp->value < pMinNode->value) {
            pMinPrev = pMinNode;
            pMinNode = pTmp;
        }
        pTmp = pTmp->pNext;
    }

    if (pMinPrev != NULL) {
        pMinPrev->pNext = pMinNode->pNext;
        pMinNode->pNext = pHead;
        pHead = pMinNode;
    }
}

void LinkedList::MoveMaxTail() {
	if (pHead == NULL) {
    	return;
    }

    ListNode* pMaxPrev = NULL;
    ListNode* pMaxNode = pHead;
    ListNode* pTmp = pHead->pNext;

    while (pTmp != NULL) {
        if (pTmp->value > pMaxNode->value) {
            pMaxPrev = pMaxNode;
            pMaxNode = pTmp;
        }
        pTmp = pTmp->pNext;
    }

    if (pMaxPrev != NULL) {
        pMaxPrev->pNext = pMaxNode->pNext;
        pTmp = pHead;
        while (pTmp->pNext != NULL) {
            pTmp = pTmp->pNext;
        }
        pTmp->pNext = pMaxNode;
        pMaxNode->pNext = NULL;
    }
}