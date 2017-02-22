#include "SmartArray_Static.hpp"


SmartArray::SmartArray()
{
    m_itemCount = 0;
}

bool SmartArray::Push( string item )
{
    if ( m_itemCount == MAX_SIZE )
    {
        return false;
    }

    m_array[m_itemCount] = item;
    m_itemCount++;

    return true;
}

string SmartArray::Get( int index )
{
    if ( index < 0 || index >= MAX_SIZE )
    {
        return "";
    }

    return m_array[index];
}

int SmartArray::GetSize()
{
    return m_itemCount;
}
