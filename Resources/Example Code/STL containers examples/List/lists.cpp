#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    list<string> states;
    
    states.push_back( "Maine" );
    states.push_back( "Hawaii" );
    states.push_back( "Kansas" );
    states.push_back( "Missouri" );
    states.push_back( "Washington" );
    states.push_back( "Alaska" );
    
    states.sort();
    
    for ( list<string>::iterator it = states.begin(); it != states.end(); it++ )
    {
        cout << *it << endl;
    }
    
    return 0;
}

