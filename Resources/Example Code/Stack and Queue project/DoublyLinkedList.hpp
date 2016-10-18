#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include "Utilities/Logger.hpp"
#include "Utilities/Strings.hpp"

#include <stdexcept>
using namespace std;

template <typename T>
class Node
{
    public:
    Node()
    {
        m_ptrNext = nullptr;
        m_ptrPrev = nullptr;
    }

    T m_data;

    Node<T>* m_ptrNext;
    Node<T>* m_ptrPrev;
};

template <typename T>
class DoublyLinkedList
{
    public:
    DoublyLinkedList()
    {
        dal::Logger::Out( "Function Begin", "DoublyLinkedList::DoublyLinkedList" );

        m_ptrFirst = nullptr;
        m_ptrLast = nullptr;
        m_itemCount = 0;

        dal::Logger::Out( "Function End", "DoublyLinkedList::DoublyLinkedList" );
    }

    ~DoublyLinkedList()
    {
        dal::Logger::Out( "Function Begin", "DoublyLinkedList::~DoublyLinkedList" );

        while ( m_ptrFirst != nullptr )
        {
            PopBack();
        }

        dal::Logger::Out( "Function End", "DoublyLinkedList::~DoublyLinkedList" );
    }

    void PushFront( T data )
    {
        dal::Logger::Out( "Function Begin", "DoublyLinkedList::PushFront" );

        Node<T>* newNode = new Node<T>();
        newNode->m_data = data;

        if ( m_ptrFirst = nullptr )
        {
            // Empty list
            m_ptrFirst = newNode;
            m_ptrLast = newNode;
        }
        else
        {
            // Not empty, new node is the new first
            newNode->m_ptrNext = m_ptrFirst;
            m_ptrFirst->m_ptrPrev = newNode;

            // Update pointer
            m_ptrFirst = newNode;
        }

        m_itemCount++;

        dal::Logger::Out( "Function End", "DoublyLinkedList::PushFront" );
    }

    void PushBack( T data )
    {
        dal::Logger::Out( "Function Begin", "DoublyLinkedList::PushBack" );

        Node<T>* newNode = new Node<T>();
        newNode->m_data = data;

        if ( m_ptrFirst == nullptr )
        {
            // Empty list
            m_ptrFirst = newNode;
            m_ptrLast = newNode;
        }
        else
        {
            // Not empty, new node is the new last
            m_ptrLast->m_ptrNext = newNode;
            newNode->m_ptrPrev = m_ptrLast;

            // Update pointer
            m_ptrLast = newNode;
        }

        m_itemCount++;

        dal::Logger::Out( "Function End", "DoublyLinkedList::PushBack" );
    }

    void Insert( T data, int index )
    {
        dal::Logger::Out( "Function Begin", "DoublyLinkedList::Insert" );

        if ( index > m_itemCount || index < 0 )
        {
            throw out_of_range( "Invalid index!" );
        }

        Node<T>* newNode = new Node<T>();
        newNode->m_data = data;

        if ( m_ptrFirst = nullptr )
        {
            // Empty list
            m_ptrFirst = newNode;
            m_ptrLast = newNode;
        }
        else
        {
            // Traverse list to find position
            int counter = 0;
            Node<T>* ptrCurrent = m_ptrFirst;

            while ( counter != index )
            {
                counter++;
            }

            // Add item in list
            newNode->m_ptrPrev = ptrCurrent->m_ptrPrev;
            newNode->m_ptrNext = ptrCurrent;

            ptrCurrent->m_ptrPrev->m_ptrNext = newNode;
            ptrCurrent->m_ptrPrev = newNode;
        }

        m_itemCount++;

        dal::Logger::Out( "Function End", "DoublyLinkedList::Insert" );
    }


    void PopFront()
    {
        dal::Logger::Out( "Function Begin", "DoublyLinkedList::PopFront" );
        dal::Logger::Out( "List size: " + dal::Strings::ToString( m_itemCount ), "DoublyLinkedList::PopFront" );

        if ( m_ptrFirst == nullptr )
        {
            dal::Logger::Out( "m_ptrFirst is a nullptr", "DoublyLinkedList::PopFront" );
            return;
        }

        if ( m_ptrFirst == m_ptrLast )
        {
            delete m_ptrLast;
            m_ptrFirst = nullptr;
            m_ptrLast = nullptr;
            m_itemCount--;
            return;
        }

        // Keep track of 2nd item
        Node<T>* ptrSecond = m_ptrFirst->m_ptrNext;

        // Update the 2nd element's prev pointer
        ptrSecond->m_ptrPrev = nullptr;

        // Clear out the data at m_ptrFirst
        delete m_ptrFirst;

        // Update first pointer
        m_ptrFirst = ptrSecond;

        m_itemCount--;

        dal::Logger::Out( "Function End", "DoublyLinkedList::PopFront" );
    }

    void PopBack()
    {
        dal::Logger::Out( "Function Begin", "DoublyLinkedList::PopBack" );
        dal::Logger::Out( "List size: " + dal::Strings::ToString( m_itemCount ), "DoublyLinkedList::PopBack" );

        if ( m_ptrLast == nullptr )
        {
            dal::Logger::Out( "m_ptrLast is a nullptr", "DoublyLinkedList::PopBack" );
            return;
        }

        if ( m_ptrFirst == m_ptrLast )
        {
            delete m_ptrLast;
            m_ptrFirst = nullptr;
            m_ptrLast = nullptr;
            m_itemCount--;
            return;
        }

        // Keep track of 2nd-to-last item
        Node<T>* ptrPenultimate = m_ptrLast->m_ptrPrev;

        // Update 2nd-to-last item's next ptr
        ptrPenultimate->m_ptrNext = nullptr;

        // Clear out data at last element
        delete m_ptrLast;

        // Update last pointer
        m_ptrLast = ptrPenultimate;

        m_itemCount--;

        dal::Logger::Out( "Function End", "DoublyLinkedList::PopBack" );
    }

    void Remove( int index )
    {
        dal::Logger::Out( "Function Begin", "DoublyLinkedList::Remove" );
        dal::Logger::Out( "List size: " + dal::Strings::ToString( m_itemCount ), "DoublyLinkedList::Remove" );

        if ( index > m_itemCount || index < 0 )
        {
            throw out_of_range( "Invalid index!" );
        }

        // Locate item
        Node<T>* ptrCurrent = m_ptrFirst;

        int counter = 0;
        while ( counter != index )
        {
            counter++;
        }

        Node<T>* ptrPrev = ptrCurrent->m_ptrPrev;
        Node<T>* ptrNext = ptrCurrent->m_ptrNext;

        // Update previous item's pointer
        ptrPrev->m_ptrNext = ptrNext;

        // Update next item's pointer
        ptrNext->m_ptrPrev = ptrPrev;

        // Free this item
        delete ptrCurrent;

        m_itemCount--;

        dal::Logger::Out( "Function End", "DoublyLinkedList::Remove" );
    }

    T& GetFront()
    {
        dal::Logger::Out( "Function Begin", "DoublyLinkedList::GetFront" );

        if ( m_ptrFirst == nullptr )
        {
            throw out_of_range( "First pointer is nullptr" );
        }

        return m_ptrFirst->m_data;

        dal::Logger::Out( "Function End", "DoublyLinkedList::GetFront" );
    }

    T& GetBack()
    {
        dal::Logger::Out( "Function Begin", "DoublyLinkedList::GetBack" );

        if ( m_ptrLast == nullptr )
        {
            throw out_of_range( "Last pointer is nullptr" );
        }

        return m_ptrLast->m_data;

        dal::Logger::Out( "Function End", "DoublyLinkedList::GetBack" );
    }

    T& Get( int index )
    {
        dal::Logger::Out( "Function Begin", "DoublyLinkedList::Get" );

        if ( index > m_itemCount || index < 0 )
        {
            throw out_of_range( "Invalid index!" );
        }

        // Locate item
        Node<T>* ptrCurrent = m_ptrFirst;

        int counter = 0;
        while ( counter != index )
        {
            counter++;
        }

        return ptrCurrent->m_data;

        dal::Logger::Out( "Function End", "DoublyLinkedList::Get" );
    }

    void Display()
    {
        dal::Logger::Out( "Function Begin", "DoublyLinkedList::Display" );

        Node<T>* ptrCurrent = m_ptrFirst;
        while ( ptrCurrent != nullptr )
        {
            cout << ptrCurrent->m_data;

            if ( ptrCurrent == m_ptrFirst )
            {
                cout << "\t FIRST";
            }
            if ( ptrCurrent == m_ptrLast )
            {
                cout << "\t LAST";
            }

            cout << endl;

            ptrCurrent = ptrCurrent->m_ptrNext;
        }

        dal::Logger::Out( "Function End", "DoublyLinkedList::Display" );
    }

    int GetSize()
    {
        return m_itemCount;
    }

    private:
    int m_itemCount;
    Node<T>* m_ptrFirst;
    Node<T>* m_ptrLast;
};

#endif
