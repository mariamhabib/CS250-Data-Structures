#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
using namespace std;

template <typename T>
class SinglyLinkedNode
{
public:
	SinglyLinkedNode()
	{
		ptrNext = nullptr;
	}

	T data;
	SinglyLinkedNode<T>* ptrNext;
};


template <typename T>
class SinglyLinkedList
{
public:
	SinglyLinkedList()
	{
		m_itemCount = 0;
		m_ptrFirst = m_ptrLast = nullptr;
	}

	~SinglyLinkedList()
	{
		while (m_itemCount > 0)
		{
			Pop();
		}
	}

	int Size()
	{
		return m_itemCount;
	}

	void Push(T data)
	{
		SinglyLinkedNode<T>* newNode = new SinglyLinkedNode<T>;
		newNode->data = data;

		if (m_itemCount == 0)
		{
			m_ptrFirst = newNode;
			m_ptrLast = newNode;
		}
		else
		{
			m_ptrLast->ptrNext = newNode;
			m_ptrLast = newNode;
		}

		m_itemCount++;
	}

	T Top()
	{
		if (m_ptrLast != nullptr)
		{
			return m_ptrLast->data;
		}
		return nullptr;
	}

	void Pop()
	{
		if (m_ptrFirst == m_ptrLast)
		{
			delete m_ptrFirst;
			m_ptrFirst = nullptr;
			m_ptrLast = nullptr;
			m_itemCount--;
			return;
		}

		else if (m_itemCount == 0)
		{
			return;
		}

		SinglyLinkedNode<T>* current = m_ptrFirst;
		while (current->ptrNext != m_ptrLast)
		{
			current = current->ptrNext;
		}
		delete m_ptrLast;
		m_ptrLast = current;
		m_ptrLast->ptrNext = nullptr;
		m_itemCount--;
	}

    bool IsInList( T data )
    {
        SinglyLinkedNode<T>* ptrCurrent = m_ptrFirst;

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

        // Locate item
        SinglyLinkedNode<T>* ptrCurrent = m_ptrFirst;

        int counter = 0;
        while ( counter != index )
        {
            ptrCurrent = ptrCurrent->ptrNext;
            counter++;
        }

        return ptrCurrent->data;
    }

	void Display()
	{
		SinglyLinkedNode<T>* current = m_ptrFirst;
		while (current != nullptr)
		{
			cout << current->data << endl;
			current = current->ptrNext;
		}
	}

private:
	SinglyLinkedNode<T>* m_ptrFirst;
	SinglyLinkedNode<T>* m_ptrLast;
	int m_itemCount;
};



#endif
