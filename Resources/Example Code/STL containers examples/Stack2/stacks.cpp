#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string text;
    cout << "Enter some text: ";
    cin >> text; // cats stac
    
    stack<char> letters;
    
    for ( unsigned int i = 0; i < text.size(); i++ )
    {
        cout << "Letter " << i << " = " << text[i] << endl;
        letters.push( text[i] );
    } 
    
    cout << endl << "Pop off stack: " << endl;
    
    while ( !letters.empty() )
    {
        cout << letters.top();
        letters.pop();
    }
    
    return 0;
}

