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
        m_ptrFirst = nullptr;
        m_ptrLast = nullptr;
    }

    ~SingleLinkedList()
    {
        ClearList();
    }

    void ClearList()
    {
        Node<T>* ptrCurrent = m_ptrFirst;
        Node<T>* deleteMe;
        while ( ptrCurrent != nullptr )
        {
            deleteMe = ptrCurrent;
            ptrCurrent = ptrCurrent->ptrNext;
            FreeNode( deleteMe );
        }
    }

    void AddItem( T data )
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;

        if ( m_count == 0 )
        {
            // This is the only node so point both
            // the beginning and ending at the new node.
            m_ptrFirst = m_ptrLast = newNode;
        }
        else
        {
            m_ptrLast->ptrNext = newNode;
            m_ptrLast = newNode;
        }

        m_count++;
    }

    void RemoveItem( const T& data )
    {
        // Find the item in question
        Node<T>* dataNode = nullptr;
        Node<T>* prevNode = nullptr;

        // Successfully found item
        if ( FindItem( data, dataNode, prevNode ) )
        {
            // Is this the first item?
            if ( dataNode == m_ptrFirst )
            {
                // Update the new first pointer.
                m_ptrFirst = dataNode->ptrNext;
            }
            // Is this the last item?
            else if ( dataNode == m_ptrLast )
            {
                // Update the last pointer to the second to last item.
                m_ptrLast = prevNode;
                m_ptrLast->ptrNext = nullptr;
            }
            // Otherwise...
            else
            {
                // Have the previous node skip over the node to remove.
                prevNode->ptrNext = dataNode->ptrNext;
            }

            // Free the node
            FreeNode( dataNode );
        }
    }

    void FreeNode( Node<T>*& node )
    {
        if ( node != nullptr )
        {
            delete node;
            node = nullptr;
            m_count--;
        }
    }

    int Size()
    {
        return m_count;
    }

    bool FindItem( const T& data, Node<T>*& dataNode, Node<T>*& prevNode )
    {
        dataNode = m_ptrFirst;
        prevNode = nullptr;
        int counter = 0;

        while ( dataNode != nullptr )
        {
            if ( dataNode->data == data )
            {
                break;
            }

            prevNode = dataNode;
            dataNode = dataNode->ptrNext;
            counter++;
        }

        if ( dataNode == nullptr )
        {
            // Didn't find item in list
            return false;
        }
        else
        {
            // Successfully found item,
            // dataNode and prevNode should be
            // pointing at the correct nodes.
            return true;
        }
    }

    void Print()
    {
		cout << "List Size: " << m_count << endl;
        Node<T>* ptrCurrent = m_ptrFirst;

        int counter = 0;
        while ( ptrCurrent != nullptr )
        {
            cout << "Item #" << counter << " is \"" << ptrCurrent->data << "\", Address is " << ptrCurrent << endl;
            ptrCurrent = ptrCurrent->ptrNext;
            counter++;
        }
    }

    private:
    Node<T>* m_ptrFirst;
    Node<T>* m_ptrLast;
    int m_count;
};

#endif
