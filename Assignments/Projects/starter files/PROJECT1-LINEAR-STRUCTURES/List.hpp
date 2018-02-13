#ifndef _LIST_HPP
#define _LIST_HPP

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
    }

public:
    List()
    {
    }

    ~List()
    {
    }

    // Core functionality
    int     Size() const
    {
    }

    bool    IsEmpty() const
    {
    }

    bool    IsFull() const
    {
    }

    bool    PushFront( const T& newItem )
    {
    }

    bool    PushBack( const T& newItem )
    {
    }

    bool    Insert( int atIndex, const T& item )
    {
    }

    bool    PopFront()
    {
    }

    bool    PopBack()
    {
    }

    bool    Remove( const T& item )
    {
    }

    bool    Remove( int atIndex )
    {
    }

    void    Clear()
    {
    }

    // Accessors
    T*      Get( int atIndex )
    {
    }

    T*      GetFront()
    {
    }

    T*      GetBack()
    {
    }

    // Additional functionality
    int     GetCountOf( const T& item ) const
    {
    }

    bool    Contains( const T& item ) const
    {
    }

    friend class Tester;
};


#endif
