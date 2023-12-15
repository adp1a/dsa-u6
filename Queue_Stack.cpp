#include <iostream>
#include "MyStack_LinkedList.h"
using namespace std;

int main()
{
    // Vytvoření zásobníku pro celá čísla
    MyStack_LinkedList<int> intStack;

    // Přidání prvků na zásobník
    int hodnota1 = 10;
    int hodnota2 = 20;
    int hodnota3 = 30;

    intStack.Push(&hodnota1);
    intStack.Push(&hodnota2);
    intStack.Push(&hodnota3);

    // Výpis hodnoty na vrcholu zásobníku
    std::cout << "Hodnota na vrcholu: " << *intStack.Front() << std::endl;

    // Odebrání prvků ze zásobníku
    std::cout << "Odebráno: " << intStack.Pop() << std::endl;
    std::cout << "Odebráno: " << *intStack.Pop() << std::endl;
    std::cout << "Odebráno: " << *intStack.Pop() << std::endl;

    // Kontrola, zda je zásobník prázdný
    std::cout << "Je zásobník prázdný? " << (intStack.Empty() ? "Ano" : "Ne") << std::endl;

    return 0;
}