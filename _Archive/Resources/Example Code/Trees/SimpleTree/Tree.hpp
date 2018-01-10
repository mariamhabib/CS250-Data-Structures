#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
using namespace std;

template <typename KT, typename VT>
struct Node
{
	Node()
	{
		ptrLeft = nullptr;
		ptrRight = nullptr;
	}

	Node<KT, VT>* ptrLeft;
	Node<KT, VT>* ptrRight;

	KT key;
	VT value;
};

template <typename KT, typename VT>
class Tree
{
public:
	Tree()
	{
		ptrRoot = nullptr;
		m_nodeCount = 0;
	}

	~Tree()
	{
    // Implement this or else
	}

	void Add(KT key, VT value)
	{
		Node<KT, VT>* newNode = new Node<KT, VT>;
		newNode->key = key;
		newNode->value = value;

		if (ptrRoot == nullptr)
		{
			cout << "New root: " << newNode->key << endl;
			ptrRoot = newNode;
		}
		else
		{
			TraverseAndAdd(newNode, ptrRoot);
		}
		m_nodeCount++;
		cout << endl;
	}

	void TraverseAndAdd(Node<KT, VT>* newNode, Node<KT, VT>* ptrCurrent)
	{
		if (ptrCurrent->key < newNode->key)
		{
			// Greater - right
			if (ptrCurrent->ptrRight == nullptr)
			{
				cout << "Add Right " << newNode->key << endl;
				ptrCurrent->ptrRight = newNode;
			}
			else
			{
				cout << "R ";
				TraverseAndAdd(newNode, ptrCurrent->ptrRight);
			}
		}
		else if (ptrCurrent->key > newNode->key)
		{
			// Less - left
			if (ptrCurrent->ptrLeft == nullptr)
			{
				cout << "Add Left " << newNode->key;
				ptrCurrent->ptrLeft = newNode;
			}
			else
			{
				cout << "L ";
				TraverseAndAdd(newNode, ptrCurrent->ptrLeft);
			}
		}
	}

private:
	Node<KT, VT>* ptrRoot;
	int m_nodeCount;
};

#endif
