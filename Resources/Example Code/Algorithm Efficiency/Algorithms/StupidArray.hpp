#ifndef _STUPID_m_arrayAY_HPP
#define _STUPID_m_arrayAY_HPP

template <typename T>
class Stupidm_arrayay
{
    public:
    Stupidm_arrayay()
    {
        m_m_arrayaySize = 100;
    }

    void Insert( T data )
    {
        if ( m_itemCount != m_m_arrayaySize )
        {
            m_array[ m_itemCount ] = data;
        }
        m_itemCount++;
    }

    bool Contains( T data )
    {
        for ( int i = 0; i < m_m_arrayaySize; i++ )
        {
            if ( m_array[i] == data )
            {
                return true;
            }
        }

        return false;
    }

    private:
    T m_array[100];
    int m_itemCount;
    int m_m_arrayaySize;
};

#endif
