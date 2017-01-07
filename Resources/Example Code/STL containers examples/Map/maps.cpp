#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<int, string> employees;
    
    employees[ 123 ] = "asdf";
    employees[ 1024 ] = "bob";
    employees[ 155 ] = "harry";
    employees[ 1321 ] = "ron";
    employees[ 1982 ] = "hermione";
    
    /*
    for ( map<int, string>::iterator it = employees.begin(); it != employees.end(); it++ )
    {
        cout << it->first << " = " << it->second << endl;
    }
    * */
    
    int index;
    cout << "Enter an index: ";
    cin >> index;
    
    cout << employees[ index ] << endl;
    
    return 0;
}

