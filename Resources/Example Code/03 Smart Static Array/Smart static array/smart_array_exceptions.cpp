#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class SmartStaticArray
{
    public: 
    void Set( int index, string value );
    string Get( int index );
    
    private:
    string m_array[10];
    const int MAX_SIZE = 10;
};

void SmartStaticArray::Set( int index, string value )
{
    if ( index < 0 || index >= MAX_SIZE )
    {
        throw out_of_range( "Invalid index!" );
    }
    
    m_array[ index ] = value;
}

string SmartStaticArray::Get( int index )
{
    if ( index < 0 || index >= MAX_SIZE )
    {
        throw out_of_range( "Invalid index!" );
    }
    
    return m_array[ index ];
}


int main()
{
    SmartStaticArray playerList;
    
    playerList.Set( 0, "Ana" );
    playerList.Set( 1, "Lucio" );
    playerList.Set( 2, "Orisa" );
    
    cout << "Insert item 100... (with try/catch)" << endl;
    // inserting something invalid with a try/catch:
    try
    {
        playerList.Set( 100, "Symmetra" );
    }
    catch( out_of_range& ex )
    {
        cout << "Error: " << ex.what() << endl;
    }
    
    cout << endl << "Insert item 50... (no try/catch)" << endl;
    // inserting something invalid without a try/catch:
    playerList.Set( 50, "Zarya" );
    
    cout << "This message won't be displayed" << endl;    
    
    return 0;
}
