#include <iostream>
#include <string>
using namespace std;

class Container
{
public:
    // Виртуальные методы, должны быть реализованы вашим контейнером
    virtual void insert(int data) = 0;
    virtual bool exists(int data) = 0;
    virtual void remove(int data) = 0;
    virtual void deletee(int data) = 0;
    // И этот тоже, хотя к нему потом ещё вернёмся
    virtual void print() = 0;

    // Виртуальный деструктор (пока просто поверьте, что он нужен)
    virtual ~Container() { };
};


class Node
{
public:

    Node* pNext;                                      //pointer Next
    int data;

    Node(int data, Node* pNext = nullptr)
    {
        this->data = data;
        this->pNext = pNext;
    }
};

class List :public Container

{
public:
    List();
    ~List();
    void popfront();
    void pushback(int data);
    void clearr();
    void pushfront(int data);
    void popback();
    void insert(int value);
    void remove(int index);
    int GetSize() { return Size; }
    bool exists(int data);
    void print();
    void deletee(int data);
private:
    int Size;
    Node* head;
};

List::List()                                            //create node
{
    Size = 0;
    head = nullptr;
}



List::~List()
{
    clearr();
}

void List::print()
{
    Node* Current = this->head;
    cout << "----Current List----Lenght = " << GetSize() << "\n";
    while (Current->pNext != NULL)
    {
        cout << Current->data << "\n";
        Current = Current->pNext;
    }
    cout << Current->data << "\n";
}

//delete first element
void List::popfront()
{
    Node* temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}


void List::pushback(int data)                            //add element
{
    if (head == nullptr)
    {
        head = new Node(data);
    }
    else
    {
        Node* current = this->head;

        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node(data);

    }

    Size++;
}


void List::clearr()
{
    while (Size)
    {
        popfront();
    }
}


inline void List::pushfront(int data)
{
    head = new Node(data, head);
    Size++;
}


inline void List::popback()
{
    remove(Size - 1);
}


void List::insert(int value)
{
    pushfront(value);
}


inline void List::remove(int index)
{
    if (index == 0)
    {
        popfront();
    }
    else
    {
        Node* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
            if (previous == nullptr)
            {
                break;
            }
        }
        if (previous == nullptr)
        {

        }
        else {
            Node* toDelete = previous->pNext;

            previous->pNext = toDelete->pNext;

            delete toDelete;
            Size--;
        }
    }
}


bool List::exists(int data)
{
    Node* Current = this->head;
    while (true)
    {
        if (Current->data == data)
            return true;

        if (Current->pNext == NULL)
            break;
        Current = Current->pNext;
    }
    return false;
}

void List::deletee(int data)
{
    Node* Current = head;
    Node* temp;
    int i = 0;
    int j = 0;
    while (true)
    {
        temp = Current->pNext;
        if (Current->data == data)
        {
            this->remove(i - j);
            j++;
        }
        i++;
        if (temp != NULL)
            Current = temp;
        else
            break;
    }
}
