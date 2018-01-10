#include <iostream>
#include <string>
using namespace std;

// Really arbitrary error to check for, not very realistic.
int RiskyFunction( int input )
{
    if ( input < 0 )
    {
        throw "Input is negative!";
    }

    return input * 2;
}

int main()
{
    try
    {
        cout << RiskyFunction( 5 ) << endl;
    }
    catch( string& message )
    {
        cout << "Error 1: " << message << endl;
    }

    // Only this one gets thrown
    try
    {
        cout << RiskyFunction( -5 ) << endl;
    }
    catch( const char* message )
    {
        cout << "Error 2: " << message << endl;
    }

    return 0;
}
