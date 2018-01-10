#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP


#include <stdexcept>
using namespace std;

template <typename T>
class DoublyLinkedNode
{
    public:
    DoublyLinkedNode()
    {
        ptrNext = nullptr;
        ptrPrev = nullptr;
    }

    T data;

    DoublyLinkedNode<T>* ptrNext;
    DoublyLinkedNode<T>* ptrPrev;
};

template <typename T>
class DoublyLinkedList
{
    public:
    DoublyLinkedList()
    {
        m_ptrFirst = nullptr;
        m_ptrLast = nullptr;
        m_itemCount = 0;
    }

    ~DoublyLinkedList()
    {
        while ( m_ptrFirst != nullptr )
        {
            PopBack();
        }
    }

    void PushFront( T data )
    {
        DoublyLinkedNode<T>* newNode = new DoublyLinkedNode<T>();
        newNode->data = data;

        if ( m_ptrFirst = nullptr )
        {
            // Empty list
            m_ptrFirst = newNode;
            m_ptrLast = newNode;
        }
        else
        {
            // Not empty, new node is the new first
            newNode->ptrNext = m_ptrFirst;
            m_ptrFirst->ptrPrev = newNode;

            // Update pointer
            m_ptrFirst = newNode;
        }

        m_itemCount++;
    }

    void PushBack( T data )
    {
        DoublyLinkedNode<T>* newNode = new DoublyLinkedNode<T>();
        newNode->data = data;

        if ( m_ptrFirst == nullptr )
        {
            // Empty list
            m_ptrFirst = newNode;
            m_ptrLast = newNode;
        }
        else
        {
            // Not empty, new node is the new last
            m_ptrLast->ptrNext = newNode;
            newNode->ptrPrev = m_ptrLast;

            // Update pointer
            m_ptrLast = newNode;
        }

        m_itemCount++;
    }

    void Insert( T data, int index )
    {
        if ( index > m_itemCount || index < 0 )
        {
            throw out_of_range( "Invalid index!" );
        }

        DoublyLinkedNode<T>* newNode = new DoublyLinkedNode<T>();
        newNode->data = data;

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
            DoublyLinkedNode<T>* ptrCurrent = m_ptrFirst;

            while ( counter != index )
            {
                counter++;
            }

            // Add item in list
            newNode->ptrPrev = ptrCurrent->ptrPrev;
            newNode->ptrNext = ptrCurrent;

            ptrCurrent->ptrPrev->ptrNext = newNode;
            ptrCurrent->ptrPrev = newNode;
        }

        m_itemCount++;
    }


    void PopFront()
    {
        if ( m_ptrFirst == nullptr )
        {
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
        DoublyLinkedNode<T>* ptrSecond = m_ptrFirst->ptrNext;

        // Update the 2nd element's prev pointer
        ptrSecond->ptrPrev = nullptr;

        // Clear out the data at m_ptrFirst
        delete m_ptrFirst;

        // Update first pointer
        m_ptrFirst = ptrSecond;

        m_itemCount--;
    }

    void PopBack()
    {
        if ( m_ptrLast == nullptr )
        {
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
        DoublyLinkedNode<T>* ptrPenultimate = m_ptrLast->ptrPrev;

        // Update 2nd-to-last item's next ptr
        ptrPenultimate->ptrNext = nullptr;

        // Clear out data at last element
        delete m_ptrLast;

        // Update last pointer
        m_ptrLast = ptrPenultimate;

        m_itemCount--;
    }

    void Remove( int index )
    {
        if ( index > m_itemCount || index < 0 )
        {
            throw out_of_range( "Invalid index!" );
        }

        // Locate item
        DoublyLinkedNode<T>* ptrCurrent = m_ptrFirst;

        int counter = 0;
        while ( counter != index )
        {
            counter++;
        }

        DoublyLinkedNode<T>* ptrPrev = ptrCurrent->ptrPrev;
        DoublyLinkedNode<T>* ptrNext = ptrCurrent->ptrNext;

        // Update previous item's pointer
        ptrPrev->ptrNext = ptrNext;

        // Update next item's pointer
        ptrNext->ptrPrev = ptrPrev;

        // Free this item
        delete ptrCurrent;

        m_itemCount--;
    }

    T& GetFront()
    {
        if ( m_ptrFirst == nullptr )
        {
            throw out_of_range( "First pointer is nullptr" );
        }

        return m_ptrFirst->data;
    }

    T& GetBack()
    {
        if ( m_ptrLast == nullptr )
        {
            throw out_of_range( "Last pointer is nullptr" );
        }

        return m_ptrLast->data;
    }

    bool IsInList( T data )
    {
        DoublyLinkedNode<T>* ptrCurrent = m_ptrFirst;

        while ( ptrCurrent != nullptr )
        {
            if ( ptrCurrent->data == data )
            {
                return true;
            }
            ptrCurrent = ptrCurrent->ptrNext;
        }

        return false;
    }

    T& Get( int index )
    {
        if ( index > m_itemCount || index < 0 )
        {
            throw out_of_range( "Invalid index!" );
        }

        DoublyLinkedNode<T>* ptrCurrent;
        int counter;

        // Faster to go from start to end, or end to start?
        if ( (m_itemCount - 1) - index < index )
        {
            ptrCurrent = m_ptrLast;
            counter = m_itemCount - 1;

            while ( counter != index )
            {
                ptrCurrent = ptrCurrent->ptrPrev;
                counter--;
            }
        }
        else
        {
            ptrCurrent = m_ptrFirst;
            counter = 0;

            while ( counter != index )
            {
                ptrCurrent = ptrCurrent->ptrNext;
                counter++;
            }
        }

        return ptrCurrent->data;
    }

    void Display()
    {
        DoublyLinkedNode<T>* ptrCurrent = m_ptrFirst;
        while ( ptrCurrent != nullptr )
        {
            cout << ptrCurrent->data;

            if ( ptrCurrent == m_ptrFirst )
            {
                cout << "\t FIRST";
            }
            if ( ptrCurrent == m_ptrLast )
            {
                cout << "\t LAST";
            }

            cout << endl;

            ptrCurrent = ptrCurrent->ptrNext;
        }
    }

    int GetSize()
    {
        return m_itemCount;
    }

    private:
    int m_itemCount;
    DoublyLinkedNode<T>* m_ptrFirst;
    DoublyLinkedNode<T>* m_ptrLast;
};

#endif
