#ifndef _LIST_HPP
#define _LIST_HPP

#include <iostream>
using namespace std;

const int ARRAY_SIZE = 100;

template <typename T>
class List
{
private:
    // private member variables
    int m_itemCount;
    T m_arr[ARRAY_SIZE];            // Add this!

    // functions for interal-workings
    bool ShiftRight( int atIndex )
    {
        return false; // placeholder
    }

    bool ShiftLeft( int atIndex )
    {
        return false; // placeholder
    }

public:
    List()
    {
        m_itemCount = 0;
    }

    ~List()
    {
    }

    // Core functionality
    int     Size() const
    {
        return m_itemCount;
    }

    bool    IsEmpty() const
    {
        return ( m_itemCount == 0 );
    }

    bool    IsFull() const
    {
        return ( m_itemCount == ARRAY_SIZE );
    }

    bool    PushFront( const T& newItem )
    {
        return false; // placeholder
    }

    bool    PushBack( const T& newItem )
    {
//        int m_itemCount;
//        T m_arr[ARRAY_SIZE];

        if ( IsFull() )
        {
            return false;   // Insert failed
        }

        m_arr[ m_itemCount ] = newItem;
        m_itemCount++;
        return true;
    }

    bool    Insert( int atIndex, const T& item )
    {
        return false; // placeholder
    }

    bool    PopFront()
    {
        return false; // placeholder
    }

    bool    PopBack()
    {
        return false; // placeholder
    }

    bool    Remove( const T& item )
    {
        return false; // placeholder
    }

    bool    Remove( int atIndex )
    {
        return false; // placeholder
    }

    void    Clear()
    {
    }

    // Accessors
    T*      Get( int atIndex )
    {
        return nullptr; // placeholder
    }

    T*      GetFront()
    {
        return nullptr; // placeholder
    }

    T*      GetBack()
    {
        return nullptr; // placeholder
    }

    // Additional functionality
    int     GetCountOf( const T& item ) const
    {
        return -1; // placeholder
    }

    bool    Contains( const T& item ) const
    {
        return false; // placeholder
    }

    friend class Tester;
};


#endif
