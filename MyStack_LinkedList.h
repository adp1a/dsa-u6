#pragma once
#include <exception>
using namespace std;

/// <summary>
/// Implementace zasobniku pomoci spojovaneho seznamu.
/// </summary>
/// <typeparam name="T">Typ uchovavany v zasobniku.</typeparam>
template <class T>
class MyStack_LinkedList
{
public:

	/// <summary>
	/// Konstruktor - vytvori zasobnik o pozadovane velikosti. 
	/// </summary>
	/// <param name="max">Velikost fronty.</param>
	MyStack_LinkedList();

	/// <summary>
	/// Destruktor - provede odstraneni implementace zasobniku.
	/// </summary>
	~MyStack_LinkedList();

	// -------------------------------------------

	/// <summary>
	/// Zasadi hodnotu T do zasobniku.
	/// </summary>
	/// <param name="">Pointer na hodnotu zasazovanou do zasobniku.</param>
	void Push(/*const T&*/ T*);

	/// <summary>
	/// Vrati hodnotu na vrcholu zasobniku. 
	/// </summary>
	/// <returns>Ukazatel na hodnotu na vrcholu zasobniku.</returns>
	T* Front() const;

	/// <summary>
	/// Vyjme prvek z vrcholu zasobniku.
	/// </summary>
	/// <returns>Ukazatel na hodnotu prvku vyjmuteho z fronty.</returns>
	T* Pop();

	/// <summary>
	/// Test na prazdneho zasobniku.
	/// </summary>
	/// <returns>true - zasobnik je prazdny(, false - zasobnik neni prazdny)</returns>
	bool Empty() const;

private:

	/// <summary>
	/// Element zasobniku, prvek spojovaneho seznamu. 
	/// </summary>
	struct Item {
		T* val;
		Item *pNext;
		Item() { pNext = NULL; }
	};

	/// <summary>
	/// Spojovany seznam. 
	/// </summary>
	Item *pHead;
};

template <class T>
MyStack_LinkedList<T>::MyStack_LinkedList() {
	pHead = NULL;
}

template <class T>
MyStack_LinkedList<T>::~MyStack_LinkedList() {
	while (!Empty()) {
		Pop();
	}
}

template <class T>
void MyStack_LinkedList<T>::Push(/*const T& x*/T *x) {
	Item* pItem = new Item;
	pItem->val = x;
	pItem->pNext = pHead;
	pHead = pItem;
}

template <class T>
T* MyStack_LinkedList<T>::Front() const {
	if (!Empty()) {
		return pHead->val;
	}
	else {
		return NULL;
	}
}

template <class T>
T* MyStack_LinkedList<T>::Pop() {
	if (!Empty()) {
		Item* pItem = pHead;
		T* value = pItem->val;
		pHead = pHead->pNext;
		delete pItem;
		return value;
	}
	else {
		return NULL;
	}
}

template <class T>
bool MyStack_LinkedList<T>::Empty() const {
	return pHead == NULL;
}