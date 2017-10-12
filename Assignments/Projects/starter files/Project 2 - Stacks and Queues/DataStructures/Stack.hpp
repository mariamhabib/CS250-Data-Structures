#ifndef _STACK_HPP
#define _STACK_HPP

#include "LinkedList.hpp"

//! A LIFO template data structure; inherits from LinkedList
template <typename T>
class Stack : public LinkedList<T>
{
public:
    //!
    /**
        @param <type> asdf
        @return <type>
    */
	Stack() : LinkedList<T>()
	{
	}

    //!
    /**
        @param <T> newItem
        @return <void>
    */
	void Push(T& newItem)
	{
	}

    //!
    /**
        @return <void>
    */
	void Pop()
	{
	}

    //!
    /**
        @return <T> asdf
    */
	T& Top()
	{
	}

    //!
    /**
        @return <int>
    */
	int Size()
	{
	}

private:
	int m_itemCount;
};

#endif
