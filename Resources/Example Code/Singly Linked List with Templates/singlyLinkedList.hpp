#ifndef _LINKED_LIST
#define _LINKED_LIST

#include <iostream>
using namespace std;

template <typename T>
class Node
{
    public:
    Node()
    {
        next = NULL;
    }

    T data;
    Node<T>* next;
};

template <typename T>
class SinglyLinkedList
{
    public:
    SinglyLinkedList()
    {
        m_size = 0;
        head = NULL;
        tail = NULL;
    }

    ~SinglyLinkedList()
    {
        Node<T>* current = head;
        Node<T>* next;
        while ( m_size > 0 )
        {
            Pop();
        }
    }

    Node<T>* Begin()
    {
        return head;
    }

    Node<T>* End()
    {
        return tail;
    }

    int Size()
    {
        return m_size;
    }

    void Push( T data )
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;

        if ( head == NULL )
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        m_size++;
    }

    void Pop()
    {
        // find next-to-last node
        Node<T>* current = head;
        if ( head == tail )
        {
            delete head;
            head = NULL;
            tail = NULL;
            m_size--;
            return;
        }

        while ( current->next != tail )
        {
            current = current->next;
        }

        delete tail;
        tail = current;
        m_size--;
    }

    void Print()
    {
        Node<T>* current = head;

        int ct = 0;
        while ( current != NULL )
        {
            ct++;
            cout << ct << ": " << current->data;

            if ( current == head )
            {
                cout << "\t HEAD";
            }
            if ( current == tail )
            {
                cout << "\t TAIL";
            }
            cout << endl;

            current = current->next;
        }
        cout << endl;
    }

    private:
    Node<T>* head;
    Node<T>* tail;
    int m_size;
};

#endif
