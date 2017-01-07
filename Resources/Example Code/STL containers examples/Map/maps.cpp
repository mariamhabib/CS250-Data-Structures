#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{    
    map<string, int> employees;
    employees["Harry"] = 1024;
    employees["Ron"] = 256;
    employees["Hermione"] = 512;
    
    string key;
    cout << "Enter an employee name: ";
    cin >> key;
    
    cout << "That employee ID is " << employees[ key ] << endl;
    
    

    return 0;
}

