#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class SmartStaticArray
{
    public: 
    bool Set( int index, string value ) noexcept;
    string* Get( int index ) noexcept;
    
    private:
    string m_array[10];
    const int MAX_SIZE = 10;
};

bool SmartStaticArray::Set( int index, string value ) noexcept
{
    if ( index < 0 || index >= MAX_SIZE )
    {
        // Don't update the array, just return false
        return false;
    }
    else
    {
        m_array[ index ] = value;
        return true; // success
    }
}

string* SmartStaticArray::Get( int index ) noexcept
{
    if ( index < 0 || index >= MAX_SIZE )
    {
        return nullptr;
    }
    
    return &m_array[ index ];
}


int main()
{
    SmartStaticArray playerList;
    
    playerList.Set( 0, "Ana" );
    playerList.Set( 1, "Lucio" );
    playerList.Set( 2, "Orisa" );
    
    cout << "Insert an item at position 50..." << endl;
    playerList.Set( 50, "Zarya" );
    
    cout << "Getting an item at position 50..." << endl;
    string* value = playerList.Get( 50 );
    if ( value != nullptr )
    {
        cout << *value << endl;
    }
    else
    {
        cout << "Returned nullptr." << endl;
    }
    
    return 0;
}
