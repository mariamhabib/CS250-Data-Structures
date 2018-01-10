#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "DoublyLinkedList.hpp"

// Add exception handling...

template <typename T>
class Queue
{
    public:
    void Enqueue( T data )
    {
        m_list.PushBack( data );
    }

    void Dequeue()
    {
        m_list.PopFront();
    }

    T& Front()
    {
        return m_list.GetFront();
    }

    int GetSize()
    {
        return m_list.GetSize();
    }

    void Display()
    {
        m_list.Display();
    }

    private:
    DoublyLinkedList<T> m_list;
};

#endif
