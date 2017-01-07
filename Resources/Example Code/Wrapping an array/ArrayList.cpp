#include "ArrayList.hpp"

#include <iostream>
using namespace std;

ArrayList::ArrayList()
{
    itemCount = 0;
}

void ArrayList::Insert( string newData )
{
    if ( itemCount == 100 )
    {
        cout << "Not enough space!" << endl;
        return;
    }
    
    dataList[ itemCount ] = newData;
    itemCount++;
}

int ArrayList::GetItemCount()
{
    return itemCount;
}
