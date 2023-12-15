#include <iostream>
#include "Array1D.cpp"

int main()
{
    printf("Projekt: SampleList\n\n");

    printf("+++ Array1D +++\n");
    // ARRAY1D
    Array1D mList;
    int pole[] = { 10, 5, 2, 4, 15, 1, 3 };
    mList.MakeList(pole, 7);
    mList.Tisk();

    // IsEmpty
    printf("Array1D je prazdne: %s\n", mList.IsEmpty() ? "Ano" : "Ne");
    //Add
    printf("--- Add ---\n");
    printf("Prev: ");
    mList.Tisk();
    mList.Add(11);
    mList.Tisk();
    //AddHead
    printf("--- AddHead ---\n");
    printf("Prev: ");
    mList.Tisk();
    mList.AddHead(111);
    mList.Tisk();
    //AddOrder
    printf("--- AddOrder ---\n");
    printf("Prev: ");
    mList.Tisk();
    mList.AddOrder(10);
    mList.Tisk();
    //AddPosition
    printf("--- AddPosition ---\n");
    printf("Prev: ");
    mList.Tisk();
    mList.AddPosition(0, 0);
    mList.Tisk();
    //Remove
    printf("--- Remove ---\n");
    printf("Prev: ");
    mList.Tisk();
    mList.Remove(0);
    mList.Tisk();
    //RemovePosition
    printf("--- RemovePosition ---\n");
    printf("Prev: ");
    mList.Tisk();
    mList.RemovePosition(1);
    mList.Tisk();
    //GetAt
    printf("Get At: %d \n", mList.GetAt(1));
    //SetAt
    printf("--- RemovePosition ---\n");
    printf("Prev: ");
    mList.Tisk();
    mList.SetAt(-1, 1);
    mList.Tisk();
    //Contains
    printf("--- Contains ---\n");
    printf("Contains: %d\n", mList.Contains(1));
    //IndexOf
    printf("--- IndexOf ---\n");
    printf("Index of %d\n", mList.IndexOf(1));
    //TiskReverse
    printf("--- TiskReverse ---\n");
    mList.TiskReverse();
    //MoveMinHead
    printf("--- MoveMinHead ---\n");
    mList.MoveMinHead();
    mList.Tisk();
    //MoveMaxTail
    printf("--- MoveMaxTail ---\n");
    mList.MoveMaxTail();
    mList.Tisk();
}