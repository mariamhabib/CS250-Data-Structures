#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

struct FoodException : public exception
{
    FoodException( const string& msg )
    {
        m_message = msg;
    }

    const char* what() const throw()
    {
        return m_message.c_str();
    }

    private:
    string m_message;
};

void Eat( string food )
{
    if ( food == "cat" )
    {
        throw FoodException( "Cannot eat " + food + "!" );
    }

    cout << "Ate " << food << endl;
}

int main()
{
    try
    {
        Eat( "pizza" );
    }
    catch( FoodException ex )
    {
        cout << "FoodException: " << ex.what() << endl;
    }

    try
    {
        Eat( "cat" );
    }
    catch( FoodException ex )
    {
        cout << "FoodException: " << ex.what() << endl;
    }

    return 0;
}
