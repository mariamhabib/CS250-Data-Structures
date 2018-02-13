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
    T m_arr[ARRAY_SIZE];

    // functions for interal-workings
    bool ShiftRight( int atIndex )
    {
    }

    bool ShiftLeft( int atIndex )
    {
        if ( atIndex < 0 || atIndex > m_itemCount )
        {
            return false;
        }

        for ( int i = atIndex + 1; i < m_itemCount; i++ )
        {
            m_arr[i-1] = m_arr[i];
        }

        return true;
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
        return -1; // placeholder
    }

    bool    IsEmpty() const
    {
        return false; // placeholder
    }

    bool    IsFull() const
    {
        return false; // placeholder
    }

    bool    PushFront( const T& newItem )
    {
        return false; // placeholder
    }

    bool    PushBack( const T& newItem )
    {
        if ( IsFull() { return false; }

        m_arr[m_itemCount] = item;
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
        if ( IsEmpty() ) { return false; }

        // lazy deletion
        m_itemCount--;
        return true;
    }

    bool    RemoveItem( const T& item )
    {
        if ( IsEmpty() )
        {
            return false;
        }

        // One way you can do this
        int removeAtIndex[ARRAY_SIZE];
        int j = 0;

        // Keep track of indices to remove
        for ( int i = 0; i < Size(); i++ )
        {
            if ( m_arr[i] == item )
            {
                removeAtIndex[j] = i;
                j++;
            }
        }

        // Remove all indices we recorded
        for ( int i = 0; i < j; i++ )
        {
            RemoveIndex( removeAtIndex[i] );
        }
    }

    bool    RemoveIndex( int atIndex )
    {
        return false; // placeholder
    }

    void    Clear()
    {
        // lazy deletion
        m_itemCount = 0;
    }

    // Accessors
    T*      Get( int atIndex )
    {
        if ( atIndex < 0 || atIndex >= m_itemCount )
        {
            return nullptr;
        }

        return &m_arr[ atIndex ];
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
        return 0; // placeholder
    }

    bool    Contains( const T& item ) const
    {
        return ( GetCountOf(item) > 0 );
    }

    // Helper function
    void Display()
    {
        cout << "\t List size: " << Size() << endl;
        for ( int i = 0; i < Size(); i++ )
        {
            T* item = Get(i);

            cout << "\t " << i << " = ";

            if ( item == nullptr )
            {
                cout << "nullptr" << endl;
            }
            else
            {
                cout << *item << endl;
            }
        }
    }

    friend class Tester;
};


#endif
