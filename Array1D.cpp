#include "Array1D.h"
#include <cstddef>
#include <iostream>
using namespace std;

Array1D::Array1D()
{
	this->size = 10;
	p_data = new int[10];
	n = 0;
}

Array1D::Array1D(int size)
{
	this->size = size;
	p_data = new int[size];
	n = 0; // seznam hodnot je po vytvoreni prazdny
}

Array1D::~Array1D()
{
	delete[] p_data;
	p_data = NULL;
}

bool Array1D::IsEmpty() const
{
	return (n == 0);
}

int Array1D::Pocet_Prvku()
{
	return n;
}

void Array1D::MakeList(int* p, int cnt)
{
	delete[] p_data;
	p_data = new int[cnt];
	// init
	for (int i = 0; i < cnt; i++)
		p_data[i] = *(p + i) /* p[i] */;
	n = cnt;
}

void Array1D::Add(int value)
{
	if (n < size)
	{
		p_data[n++] = value;
	}
}


void Array1D::AddHead(int value)
{
	AddPosition(value, 0);
}

void Array1D::AddOrder(int value)
{
	int j = 0;
	while (j < n && p_data[j] > value)
		j++;
	for (int i = n; i > j; i--)
		p_data[i] = p_data[i - 1];
	p_data[j] = value;
	n++;
}

void Array1D::AddPosition(int value, int pos)
{
	if (n < size - 1)
	{
		for (int i = n; i > pos; i--)
			p_data[i] = p_data[i - 1];
		p_data[pos] = value;
		n++;
	}
}

bool Array1D::Remove(int value)
{
	int id = IndexOf(value);
	if (id != -1) {
		RemovePosition(0);
		return true;
	}
	else
		return false;
}

int Array1D::RemovePosition(int pos)
{
	if (!(pos >= 0 && pos < n))
		return -1;

	int value = p_data[pos];
	for (int i = pos; i < n - 1; i++)
		p_data[i] = p_data[i + 1];
	n--;
	return value;
}

int Array1D::GetAt(int pos)
{
	return (pos >= 0 && pos < n) ? p_data[pos] : -1;
}

void Array1D::SetAt(int value, int pos)
{
	if (pos >= 0 && pos < n)
		p_data[pos] = value;
}

bool Array1D::Contains(int value)
{
	return IndexOf(value) != -1;
}

int Array1D::IndexOf(int value)
{
	int id = 0;
	while (id < n && p_data[id] != value)
		id++;
	return id < n ? id : -1; 
}

void Array1D::Tisk() const
{	
	int* pTmp = p_data;
	while (pTmp != (p_data + n))
	{
		cout << *pTmp << ';';
		pTmp++;
	}
	cout << "\n";
}

void Array1D::TiskReverse()
{
	for (int i = n - 1; i >= 0; i--)
		cout << p_data[i] << ';';
	cout << "\n";
}

void Array1D::MoveMinHead() {
	int min = p_data[0];
	int MIN_INDEX = 0;

	for(int i = 0; i < this->size; i++) {
		if(p_data[i] < min) {
			min = p_data[i];
			MIN_INDEX = i;
		}
	}

	for (int i = MIN_INDEX; i > 0; i--) {
        p_data[i] = p_data[i - 1];
    }

    p_data[0] = min;
}

void Array1D::MoveMaxTail() {
	if (n > 0) {
		int max = p_data[0];
		int MAX_INDEX = 0;

		for (int i = 1; i < n; i++) {
			if (p_data[i] > max) {
				max = p_data[i];
				MAX_INDEX = i;
			}
		}

		for (int i = MAX_INDEX; i < n - 1; i++) {
			p_data[i] = p_data[i + 1];
		}

		p_data[n - 1] = max;
    }
}