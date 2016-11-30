#ifndef _BIG_OBJECT_HPP
#define _BIG_OBJECT_HPP

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class BigObject
{
    public:
    BigObject()
    {
        m_arraySize = 10000;
        m_array = new int[m_arraySize];

        for ( int i = 0; i < m_arraySize; i++ )
        {
            m_array[i] = i;
        }
    }

    ~BigObject()
    {
        delete [] m_array;
    }

    bool operator==( int value )
    {
        for ( int i = 0; i < m_arraySize; i++ )
        {
            if ( m_array[i] == value )
            {
                return true;
            }
        }
        return false;
    }

    private:
    int* m_array;
    int m_arraySize;
};

#endif
