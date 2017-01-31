#include "SmartArray_Static.hpp"

SmartArray::SmartArray()
{
    m_itemCount = 0;
}

bool SmartArray::Push( const string& value )
{
    if ( m_itemCount == MAX_SIZE )
    {
        // Array is full
        return false;
    }

    m_list[m_itemCount] = value;
    m_itemCount++;

    return true;
}

string SmartArray::Get( int index )
{
    if ( index < 0 || index >= m_itemCount )
    {
        return "";
    }
    return m_list[index];
}

int SmartArray::GetSize()
{
    return m_itemCount;
}
