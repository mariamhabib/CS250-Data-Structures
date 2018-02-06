/*
Linked List example, Spring 2018 CS 250
Written by Rachel Singh
*/

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

#include "Node.hpp"

template <typename T>
class LinkedList
{
    public:
    LinkedList();
    ~LinkedList();

    // Return type boolean to work with the unit tests from last time.
    void PushFront( const T& newData ) noexcept;
    void PushBack( const T& newData ) noexcept;
    void Insert( const T& newData, int atIndex );

    void PopFront() noexcept;
    void PopBack() noexcept;
    void Remove( int atIndex );

    T& GetFront();
    T& GetBack();
    T& Get( const int index );

    T& operator[]( const int index );
    void Clear();

    bool IsEmpty() noexcept;
    int Size() noexcept;

    private:
    Node<T>* GetAtIndex( int index ) noexcept;

    Node<T>* m_ptrFirst;
    Node<T>* m_ptrLast;

    int m_itemCount;
};

template <typename T>
LinkedList<T>::LinkedList()
{
    m_ptrFirst = m_ptrLast = nullptr;
    m_itemCount = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Clear();
}

template <typename T>
void LinkedList<T>::PushFront( const T& newData ) noexcept
{
    // Create a new node, set its data.
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    m_itemCount++;

    // If the list is empty, this is the first item.
    if ( m_ptrFirst == nullptr )
    {
        m_ptrFirst = newNode;
        m_ptrLast = newNode;
    }

    // Otherwise, it goes at the beginning; it is the new first item.
    else
    {
        m_ptrFirst->ptrPrev = newNode;
        newNode->ptrNext = m_ptrFirst;
        m_ptrFirst = newNode;
    }
}

template <typename T>
void LinkedList<T>::PushBack( const T& newData ) noexcept
{
    // Create a new node, set its data.
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    m_itemCount++;

    // If the list is empty, this is the first item.
    if ( m_ptrLast == nullptr )
    {
        m_ptrFirst = newNode;
        m_ptrLast = newNode;
    }

    // Otherwise, it goes at the end; it is the new last item.
    else
    {
        m_ptrLast->ptrNext = newNode;
        newNode->ptrPrev = m_ptrLast;
        m_ptrLast = newNode;
    }
}

template <typename T>
void LinkedList<T>::Insert( const T& newData, int atIndex )
{
    // Invalid scenario: Index is out of range
    if ( atIndex < 0 || atIndex > m_itemCount )
    {
        throw out_of_range( "Invalid index" );
    }

    // Otherwise, check if we're doing a PushFront
    else if ( atIndex == 0 )
    {
        PushFront( newData );
    }

    // Or if we're doing a PushBack (why reinvent the wheel?)
    else if ( atIndex == m_itemCount )
    {
        PushBack( newData );
    }

    else
    {
        // Otherwise, we need to find the node that will go before,
        // and the node that will go after.
        Node<T>* ptrPrevious    = GetAtIndex( atIndex - 1 );
        Node<T>* ptrNext        = GetAtIndex( atIndex );

        // Create our new node and set its data
        Node<T>* newNode = new Node<T>;
        newNode->data = newData;

        // Update the pointers so that newNode goes between ptrPrevious and ptrNext.
        ptrPrevious->ptrNext = newNode;
        newNode->ptrPrev = ptrPrevious;

        newNode->ptrNext = ptrNext;
        ptrNext->ptrPrev = newNode;

        // Increment the item count
        m_itemCount++;
    }
}

template <typename T>
void LinkedList<T>::PopFront() noexcept
{
    // If the list is empty, nothing happens.
    // There is a "no exception" contract for this function.
    if ( m_ptrFirst == nullptr )
    {
        // Ignore this scenario
        // If statement left to explicitly state what happens.
    }

    // If there is only one item in the list...
    else if ( m_ptrFirst == m_ptrLast )
    {
        delete m_ptrFirst;
        m_ptrFirst = m_ptrLast = nullptr;
        m_itemCount--;
    }

    // If there is more than one item in the list...
    else
    {
        // Locate the second item in the list. It will be the new first.
        Node<T>* ptrSecond = m_ptrFirst->ptrNext;
        // Clearing out the prev pointer for the new-first-item.
        ptrSecond->ptrPrev = nullptr;
        // Remove the old-first-item
        delete m_ptrFirst;
        // Point the first pointer to the new-first-item.
        m_ptrFirst = ptrSecond;
        m_itemCount--;
    }
}

template <typename T>
void LinkedList<T>::PopBack() noexcept
{
    // If the list is empty, nothing happens.
    // There is a "no exception" contract for this function.
    if ( m_ptrLast == nullptr )
    {
        // Ignore this scenario
        // If statement left to explicitly state what happens.
    }

    // If there is only one item in the list...
    else if ( m_ptrFirst == m_ptrLast )
    {
        delete m_ptrFirst;
        m_ptrFirst = m_ptrLast = nullptr;
        m_itemCount--;
    }

    // If there is more than one item in the list...
    else
    {
        // Locate the second-to-last item in the list. It will be the new last.
        Node<T>* ptrSecondToLast = m_ptrLast->ptrPrev;
        // Clearing out the next pointer for the new-last-item.
        ptrSecondToLast->ptrNext = nullptr;
        // Remove the old-last-item
        delete m_ptrLast;
        // Point the last pointer to the new-last-item.
        m_ptrLast = ptrSecondToLast;
        m_itemCount--;
    }
}

template <typename T>
void LinkedList<T>::Remove( int atIndex )
{
    // Invalid scenario: Index is out of range
    if ( atIndex < 0 || atIndex > m_itemCount )
    {
        throw out_of_range( "Invalid index" );
    }

    // Otherwise, check if we're doing a PopFront
    else if ( atIndex == 0 )
    {
        PopFront();
    }

    // Or if we're doing a PopBack
    else if ( atIndex == m_itemCount )
    {
        PopBack();
    }

    else
    {
        // Otherwise, we need to find the node that will go before,
        // and the node that will go after.
        Node<T>* ptrPrevious    = GetAtIndex( atIndex - 1 );
        Node<T>* ptrDeleteMe    = GetAtIndex( atIndex );
        Node<T>* ptrNext        = GetAtIndex( atIndex + 1 );

        // Delete the Node
        delete ptrDeleteMe;

        // Update the pointers
        ptrPrevious->ptrNext = ptrNext;
        ptrNext->ptrPrev = ptrPrevious;

        // Decrement the item count
        m_itemCount--;

    }
}

template <typename T>
T& LinkedList<T>::GetFront()
{
    // Invalid scenario: List is empty / there is no ptrFirst
    if ( m_ptrFirst == nullptr )
    {
        throw out_of_range( "Cannot GetBack() for an empty list" );
    }

    // Return the data stored in the head node
    else
    {
        return m_ptrFirst->data;
    }
}

template <typename T>
T& LinkedList<T>::GetBack()
{
    // Invalid scenario: List is empty / there is no ptrLast
    if ( m_ptrLast == nullptr )
    {
        throw out_of_range( "Cannot GetBack() for an empty list" );
    }

    // Return the data stored in the tail node
    else
    {
        return m_ptrLast->data;
    }
}

template <typename T>
Node<T>* LinkedList<T>::GetAtIndex( int index ) noexcept
{
    // Invalid scenario: List is empty
    if ( m_ptrFirst == nullptr )
    {
        return nullptr;
    }

    // Invalid scenario: Index is out of bounds
    else if ( index < 0 || index >= m_itemCount )
    {
        return nullptr;
    }

    // Locate the node at that index and return its data.
    int counter = 0;
    Node<T>* ptrWalker = m_ptrFirst;

    while ( ptrWalker != nullptr && counter < index )
    {
        ptrWalker = ptrWalker->ptrNext;
        counter++;
    }

    return ptrWalker;
}

template <typename T>
T& LinkedList<T>::Get( const int index )
{
    Node<T>* nodeAtIndex = GetAtIndex( index );

    // Invalid scenario: The GetAtIndex function returned a nullptr.
    if ( nodeAtIndex == nullptr )
    {
        throw out_of_range( "Invalid index passed in" );
    }

    // Otherwise return the data in this node
    else
    {
        return nodeAtIndex->data;
    }
}

template <typename T>
T& LinkedList<T>::operator[]( const int index )
{
    return Get( index );
}

template <typename T>
void LinkedList<T>::Clear()
{
    // Pop all items until the list is empty.
    while ( m_ptrFirst != nullptr )
    {
        PopFront();
    }
}

template <typename T>

bool LinkedList<T>::IsEmpty() noexcept
{
    return ( m_itemCount == 0 );
}

template <typename T>
int LinkedList<T>::Size() noexcept
{
    return m_itemCount;
}

#endif
