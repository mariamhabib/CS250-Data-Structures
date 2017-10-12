#ifndef _QUEUE_HPP
#define _QUEUE_HPP

#include "LinkedList.hpp"

//! A FIFO template data structure; inherits from LinkedList
template <typename T>
class Queue : public LinkedList<T>
{
public:
    //!
    /**
        @param <type> asdf
        @return <type>
    */
    Queue() : LinkedList<T>()
    {
    }

    //!
    /**
        @param <type> asdf
        @return <type>
    */
	void Push(T& newItem)
	{
	}

    //!
    /**
        @param <type> asdf
        @return <type>
    */
	void Pop()
	{
	}

    //!
    /**
        @param <type> asdf
        @return <type>
    */
	T& Front()
	{
	}

    //!
    /**
        @param <type> asdf
        @return <type>
    */
	int Size()
	{
	}

private:
	int m_itemCount;
};

#endif
