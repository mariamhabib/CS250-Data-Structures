#ifndef _SMART_ARRAY_STATIC_HPP
#define _SMART_ARRAY_STATIC_HPP

#include <string>
using namespace std;

const int MAX_SIZE = 5;

class SmartArray
{
public:
    SmartArray();

    bool Push( const string& value );
    string Get( int index );

    int GetSize();

private:
    int m_itemCount;
    string m_list[MAX_SIZE];
};

#endif
