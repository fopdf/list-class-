//Linked list
//In understanding and working on the project helped me a lot:
//https://en.wikipedia.org/wiki/Linked_list
//




#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List
{
public:
    List();
    ~List();
    void popfront();
    void pushback(T data);
    void clearr();
    int GetSize() { return Size; }
    T& operator[](const int index);

private:


    template<typename T>
    class Node
    {
    public:

        Node* pNext;                                      //pointer Next
        T data;

        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T>* head;
};

template<typename T>
List<T>::List()                                            //create node
{
    Size = 0;
    head = nullptr;
}



template<typename T>
List<T>::~List()
{
    clearr();
}

template<typename T>                    //delete first element
void List<T>::popfront()
{
    Node<T>* temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}


template<typename T>
void List<T>::pushback(T data)                            //add element
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;

        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);

    }

    Size++;
}

template<typename T>
void List<T>::clearr()
{
    while (Size)
    {
        popfront();
    }
}


template<typename T>
T& List<T>:: operator[](const int index)              //search node by index
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}




int main()
{
    setlocale(LC_ALL, "ru");
    List<int> lst;
    lst.pushback(5);
    lst.pushback(42);
    lst.pushback(420);
    lst.pushback(15);
    lst.pushback(11);
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
