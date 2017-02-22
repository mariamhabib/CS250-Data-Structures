#ifndef _SMART_ARRAY_STATIC_HPP
#define _SMART_ARRAY_STATIC_HPP

#include <string>
using namespace std;

const int MAX_SIZE = 5;

class SmartArray
{
public:
    SmartArray();

    bool Push( string item );
    string Get( int index );
    int GetSize();

private:
    string m_array[MAX_SIZE];
    int m_itemCount;
};

#endif
