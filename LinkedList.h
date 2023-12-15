#pragma once
#include "ListNode.h"

class LinkedList
{
private:
	/// <summary>
	/// Ukazatel na zacatek seznamu (na prvni prvek seznamu). 
	/// </summary>
	ListNode* pHead;

private:
	void TiskReverse(ListNode* pHead);

public:
	LinkedList();

	~LinkedList();

	// -----

	// otestuje, jestli je seznam prazdny
	bool IsEmpty() const;

	// vrati hodnotu poctu prvku seznamu
	int Pocet_Prvku();

	// vytvori seznam z hodnot ulozenych v poli p
	void MakeList(int* p, int cnt);

	// -----

	// prida prvek s hodnou value na konec seznamu
	void Add(int value);

	// prida prvek s hodnotou value na zacatek seznamu
	void AddHead(int value);

	// zaradi prvek s hodnotou do seznamu tak, aby byly prvky seznamu usporadany podle hodnoty
	void AddOrder(int value);

	// zaradi prvek s hodnotou do seznamu na zadanou pouzici
	void AddPosition(int value, int pos);

	// odstrani prvek seznamu s hodnotou value
	bool Remove(int value);

	// odstrani prvek s hodnotou ze seznamu na zadane pozici
	int RemovePosition(int pos);

	// -----

	// vrati hodnotu prvku na pozadovane pozici
	int GetAt(int pos);

	// zapise (prepise) hodnotu pvku na pozadovane pozici, pokud takova existuje
	void SetAt(int value, int pos);

	// otestuje, jestli existuje prvek s hodnotou value
	bool Contains(int value);

	// vrati pozici prvniho vyskytu hodnoty, jinak vrati hodnotu -1 
	int IndexOf(int value);

	// -----

	// vytiskne seznam na standardni vystup
	void Tisk() const;

	// vytiskne prvky v obracenem poradi
	void TiskReverse();

	// presune prvek s minimalni hodnotou na zacatek seznamu
	void MoveMinHead();

	// presune prvek s maximalni hodnotou na konec seznamu
	void MoveMaxTail();
};