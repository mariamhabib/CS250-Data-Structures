#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
	Node()
	{
		ptrNext = nullptr;
	}

	T data;
	Node<T>* ptrNext;
};


template <typename T>
class SinglyLinkedList
{
public:
	SinglyLinkedList()
	{
		m_size = 0;
		m_ptrHead = m_ptrTail = nullptr;
	}

	~SinglyLinkedList()
	{
		while (m_size > 0)
		{
			Pop();
		}
	}

	int Size()
	{
		return m_size;
	}

	void Push(T data)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = data;

		if (m_size == 0)
		{
			m_ptrHead = newNode;
			m_ptrTail = newNode;
		}
		else
		{
			m_ptrTail->ptrNext = newNode;
			m_ptrTail = newNode;
		}

		m_size++;
	}

	T Top()
	{
		if (m_ptrTail != nullptr)
		{
			return m_ptrTail->data;
		}
		return nullptr;
	}

	void Pop()
	{
		if (m_ptrHead == m_ptrTail)
		{
			delete m_ptrHead;
			m_ptrHead = nullptr;
			m_ptrTail = nullptr;
			m_size--;
			return;
		}

		else if (m_size == 0)
		{
			return;
		}

		Node<T>* current = m_ptrHead;
		while (current->ptrNext != m_ptrTail)
		{
			current = current->ptrNext;
		}
		delete m_ptrTail;
		m_ptrTail = current;
		m_ptrTail->ptrNext = nullptr;
		m_size--;
	}

	void Print()
	{
		Node<T>* current = m_ptrHead;
		while (current != nullptr)
		{
			cout << current->data << endl;
			current = current->ptrNext;
		}
	}

private:
	Node<T>* m_ptrHead;
	Node<T>* m_ptrTail;
	int m_size;
};



#endif
