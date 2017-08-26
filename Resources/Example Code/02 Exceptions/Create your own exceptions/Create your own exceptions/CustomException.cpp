#include <iostream>
#include <string>
#include <exception>
using namespace std;

// My custom Exception type
class SpecialException : public logic_error
{
public:
    SpecialException( const string& what_arg )
        : logic_error( what_arg )
    {
        // Do special things here
    }
};

// A function that throws the SpecialException
float RiskyFunction( int num, int denom )
{
    if ( denom == 0 )
    {
        throw SpecialException( "0 denominator not allowed" );
    }

    return float( num ) / float( denom );
}

// Use try/catch in main to detect.
int main()
{
    int num = 10;
    int denom = 0;

    try
    {
        float result = RiskyFunction( num, denom );
        cout << "Result: " << result << endl;
    }
    catch (SpecialException ex)
    {
        cout << "ERROR! " << ex.what() << endl;
    }

    denom = 1;

    try
    {
        float result = RiskyFunction( num, denom );
        cout << "Result: " << result << endl;
    }
    catch (SpecialException ex)
    {
        cout << "ERROR! " << ex.what() << endl;
    }

    return 0;
}
