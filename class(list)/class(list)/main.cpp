//Linked list


#include "list.h"
#include <iostream>
#include <string>
using namespace std;



//int main()
//{
//    setlocale(LC_ALL, "ru");
//   List<int> lst;
//    lst.pushback(5);
//    lst.pushback(42);
//    lst.pushback(420);
//    lst.pushback(15);
//    lst.pushback(11);
//    lst.pushfront(1);
//    lst.pushfront(2);
//    for (int i = 0; i < lst.GetSize(); i++)
//    {
//        cout << lst[i] << endl;
//    }
//    cout << "Элементов в списке " << lst.GetSize() << endl;
//    cout << "Вставка элемента " << endl;
//    lst.insert(99, 1);
//    for (int i = 0; i < lst.GetSize(); i++)
//    {
//        cout << lst[i] << endl;
//    }
//    cout << "Элементов в списке " << lst.GetSize() << endl;
//    cout << "Удаление элемента " << endl;
//    lst.remove(1);
//    for (int i = 0; i < lst.GetSize(); i++)
//    {
//        cout << lst[i] << endl;
//    }
//    cout << "Элементов в списке " << lst.GetSize() << endl;
//    return 0;
    //}
int main()
{
    Container* c = new List;

    for (int i = 0; i < 10; i++)
        c->insert(i * i);

    cout << "Container after creation:" << endl;
    c->print();

    if (c->exists(25))
        cout << "Search for value 25: found" << endl;

    if (!c->exists(111))
        cout << "Search for value 111: not found" << endl;

    c->remove(25);
    cout << "Container after deletion of the element:" << endl;
    c->print();

    delete c;
    return 0;
}