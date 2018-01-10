#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

void PizzaTopping( string topping )
{
    if ( topping == "anchovies" )
    {
        throw invalid_argument( "Invalid pizza topping: " + topping );
    }
}

int main()
{
    while ( true )
    {
        cout << "Enter a pizza topping: ";
        string topping;
        cin >> topping;

        try
        {
            PizzaTopping( topping );
        }
        catch( logic_error& e )
        {
            cout << "Logic error: " << e.what() << endl << endl;
        }
    }
    
    return 0;
}
