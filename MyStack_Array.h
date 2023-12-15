#pragma once
#include <exception>
using namespace std;

/// <summary>
/// Implementace zasobniku pomoci pole.
/// </summary>
/// <typeparam name="T">Typ uchovavany v zasobniku.</typeparam>
template <class T>
class MyStack_Array
{
public:

	/// <summary>
	/// Konstruktor - vytvori zasobnik o pozadovane velikosti. 
	/// </summary>
	/// <param name="max">Velikost fronty.</param>
	MyStack_Array(int max);

	/// <summary>
	/// Destruktor - provede odstraneni implementace zasobniku.
	/// </summary>
	~MyStack_Array();

	// -------------------------------------------

	/// <summary>
	/// Pocet prvku v zasobniku
	/// </summary>
	int Size();

	/// <summary>
	/// Prida hodnotu T do zasobniku.
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
	/// Test na prazdny zasobnik.
	/// </summary>
	/// <returns>true - zasobnik je prazdny(, false - zasobnik neni prazdny)</returns>
	bool Empty() const;

private:

	/// <summary>
	/// Element zasobniku. 
	/// </summary>
	struct Item {
		T* val;		
		Item() 
		{ 
			pNext = NULL; 
		}
	};

	// implementace zasobniku pomoci pole
	/// <summary>
	/// Pole 
	/// </summary>
	Item *p_1d;

	/// <summary>
	/// Pocet hodnot vlozenych do zasobniku.
	/// </summary>
	int n;

	/// <summary>
	/// Max pocet hodnot v zasobniku
	/// </summary>
	int size;		
};

template <class T>
int MyStack_Array<T>::Size() {
	return size;
}

template <class T>
MyStack_Array<T>::MyStack_Array(int max) {
	p_1d = new Item[max];
	n = 0;
	size = max;
}

template <class T>
MyStack_Array<T>::~MyStack_Array() {
	delete p_1d;
}

template <class T>
void MyStack_Array<T>::Push(/*const T& x*/T *x) {
	if(n < size) {
		p_1d[n].val = x;
		n++;
	}
}

template <class T>
T* MyStack_Array<T>::Front() const {
	return (n > 0) ? p_1d[n - 1].val : NULL;
}

template <class T>
T* MyStack_Array<T>::Pop() {
	if (n > 0) {
		n--;
		return p_1d[n].val;
	}
	return NULL;
}

template <class T>
bool MyStack_Array<T>::Empty() const {
	return (n == 0);
}