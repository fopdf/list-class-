//Linked list
//In understanding and working on the project helped me a lot:
//https://en.wikipedia.org/wiki/Linked_list
//



#include "list.h"
#include <iostream>
#include <string>
using namespace std;



int main()
{
    setlocale(LC_ALL, "ru");
    List<int> lst;
    lst.pushback(5);
    lst.pushback(42);
    lst.pushback(420);
    lst.pushback(15);
    lst.pushback(11);
    lst.pushfront(1);
    lst.pushfront(2);
    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
    }
    cout << "Элементов в списке " << lst.GetSize() << endl;
    cout << "Удалим начальный элемент " << endl;
    lst.popfront();
    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
    }
    cout << "Элементов в списке " << lst.GetSize() << endl;
    return 0;

}
