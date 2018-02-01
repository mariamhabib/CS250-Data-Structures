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
        return false; // placeholder
    }

    bool ShiftLeft( int atIndex )
    {
        return false; // placeholder
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
        return false; // placeholders
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
