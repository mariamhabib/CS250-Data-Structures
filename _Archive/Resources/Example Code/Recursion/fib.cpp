#include <iostream>
using namespace std;

int Fib( int n )
{
    if ( n == 0 )
    {
        return 0;
    }

    if ( n == 1 )
    {
        return 1;
    }

    return Fib( n-1 ) + Fib( n-2 );
}

int main()
{
    while ( true )
    {
        cout << "n = ";
        int n;
        cin >> n;

        cout << "Recursive: " << Fib( n ) << endl;

        cout << endl << endl;
    }
    
    return 0;
}
