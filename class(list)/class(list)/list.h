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
    void pushfront(T data);
    void popback();
    void insert(T value, int index);
    void remove(int index);
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
inline void List<T>::pushfront(T data)
{
    head = new Node<T>(data, head);
    Size++;
}

template<typename T>
inline void List<T>::popback()
{
    remove(Size-1);
}

template<typename T>
inline void List<T>::insert(T value, int index)
{
    if (index == 0)
    {
        pushfront(value);
    }
    
    else {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        
        Node<T>* newNode = new Node<T>(value, previous->pNext);
        previous->pNext = newNode;

        Size++;
    }
}

template<typename T>
inline void List<T>::remove(int index)
{
    if (index == 0)
    {
        popfront();
    }
    else
    {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        Node<T>* toDelete = previous->pNext;

        previous->pNext = toDelete->pNext;

        delete toDelete;
        Size--;
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
