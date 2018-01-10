#include <iostream>
using namespace std;

int CalculateFactorial( int n )
{
    if ( n == 1 )
    {
        // Terminating case
        return 1;
    }

    return n * CalculateFactorial( n-1 );
}

int CalculateFactorial_Loop( int value )
{
    int result = value;
    for ( int i = value-1; i > 0; i-- )
    {
        result *= i;
    }
    return result;
}

int main()
{
    while ( true )
    {
        cout << "n = ";
        int n;
        cin >> n;

        cout << "Recursive: " << CalculateFactorial( n ) << endl;
        cout << "Loop:      " << CalculateFactorial_Loop( n ) << endl;

        cout << endl << endl;
    }
    
    return 0;
}
