#ifndef SINGLELINKEDLIST_HPP
#define SINGLELINKEDLIST_HPP

#include <iostream>
using namespace std;

template <typename T>
class Node
{
    public:
    Node() { ptrNext = nullptr; }

    Node<T>* ptrNext;
    T data;
};

template <typename T>
class SingleLinkedList
{
    public:
    SingleLinkedList()
    {
        m_count = 0;
    }

    ~SingleLinkedList()
    {
        ClearList();
    }

    void ClearList()
    {
    }

    void AddItem( T data )
    {
    }

    void RemoveItem( T data )
    {
    }

    int Size()
    {
        return m_count;
    }

    void Print()
    {
        Node<T>* ptrCurrent = m_ptrFirst;

        while ( ptrCurrent != nullptr )
        {
            cout << ptrCurrent->data << endl;
            ptrCurrent = ptrCurrent->ptrNext;
        }
    }

    private:
    Node<T>* m_ptrFirst;
    Node<T>* m_ptrLast;
    int m_count;
};

#endif
