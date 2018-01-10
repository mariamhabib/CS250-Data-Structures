#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

void SomeFunction( int error )
{
    if ( error == 1 )
    {
        throw overflow_error( "Overflow" );
    }
    else if ( error == 2 )
    {
        throw invalid_argument( "Invalid argument" );
    }
    else if ( error == 3 )
    {
        throw out_of_range( "Out of range" );
    }
}

int main()
{
    int num;
    cout << "Enter an int: ";
    cin >> num;

    try
    {
        SomeFunction( num );
    }
    catch( logic_error& e )
    {
        cout << "LOGIC ERROR" << endl
            << e.what() << endl;
    }
    catch( runtime_error& e )
    {
        cout << "RUNTIME ERROR" << endl
            << e.what() << endl;
    }
    catch( exception& e )
    {
        cout << e.what() << endl;
    }
    
    return 0;
}
