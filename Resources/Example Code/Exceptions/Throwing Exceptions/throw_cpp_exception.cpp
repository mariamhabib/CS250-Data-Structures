#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

string veryBadGlobalArray[10];

void RiskyInsert( int index, string value )
{
    if ( index < 0 || index >= 10 )
    {
        throw out_of_range( "index out of range" );
    }

    veryBadGlobalArray[index] = value;
}

int main()
{
    try
    {
        RiskyInsert( 0, "Hi" );
    }
    catch( out_of_range& ex )
    {
        cout << "out_of_range: " << ex.what() << endl;
    }

    try
    {
        RiskyInsert( 20, "Bye" );
    }
    catch( out_of_range& ex )
    {
        cout << "out_of_range: " << ex.what() << endl;
    }

    return 0;
}
