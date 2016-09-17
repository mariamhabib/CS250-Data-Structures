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
        cout << "\t(Constructor)" << endl;
        m_count = 0;
        m_ptrFirst = nullptr;
        m_ptrLast = nullptr;
    }

    ~SingleLinkedList()
    {
        cout << "\t(Destructor)" << endl;
        ClearList();
    }

    void ClearList()
    {
        while ( m_ptrFirst != nullptr )
        {
            cout << "\t(ClearList) List size: " << m_count << endl;
            FreeNode( m_ptrFirst );
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
            m_ptrFirst->ptrNext = m_ptrLast;
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
                cout << "\t(RemoveItem) It's the first item" << endl;

                // Update the new first pointer.
                m_ptrFirst = dataNode->ptrNext;
            }
            // Is this the last item?
            else if ( dataNode == m_ptrLast )
            {
                cout << "\t(RemoveItem) It's the last item" << endl;

                // Update the last pointer to the second to last item.
                m_ptrLast = prevNode;
            }
            // Otherwise...
            else
            {
                cout << "\t(RemoveItem) Center item" << endl;

                // Have the previous node skip over the node to remove.
                prevNode->ptrNext = dataNode->ptrNext;
            }

            cout << "\t(RemoveItem) Before Free: " << endl;
            Print();

            // Free the node
            cout << "\t(RemoveItem) Free node " << dataNode << endl;
            delete dataNode;
            dataNode = nullptr;
            m_count--;

            cout << "\t(RemoveItem) After Free: " << endl;
            Print();
        }
    }

    void FreeNode( Node<T>*& node )
    {
        cout << "\t(FreeNode) Free node: " << node << " = " << node->data << endl;
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
        cout << "\t(FindItem) Find item \"" << data << "\"" << endl;

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
            cout << "\t(FindItem) Didn't find item" << endl;
            // Didn't find item in list
            return false;
        }
        else
        {
            cout << "\t(FindItem) Found at position " << counter << endl;
            cout << "\t(FindItem) Data node: " << dataNode << " (" << dataNode->data << ")" << endl;
            if ( dataNode != m_ptrFirst )
            {
                cout << "\t(FindItem) Prev node: " << prevNode << " (" << prevNode->data << ")" << endl;
            }

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
            cout << counter << " = " << ptrCurrent->data << " (" << ptrCurrent << ")" << endl;
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
