#include <iostream>
#include <string>
using namespace std;

#include "Dictionary.hpp"

int main()
{
    Dictionary<string, string> classList;

    classList.Add( "CS 134", "Programming Fundamentals" );
    classList.Add( "CS 200", "Concepts of Programming Algorithms Using C++" );
    classList.Add( "CS 201", "Concepts of Programming Algorithms Using C#" );
    classList.Add( "CS 205", "Concepts of Programming Algorithms Using Java" );
    classList.Add( "CS 210", "Discrete Structures I" );
    classList.Add( "CS 211", "Discrete Structures II" );
    classList.Add( "CS 235", "Object-Oriented Programming Using C++" );
    classList.Add( "CS 236", "Object-Oriented Programming Using C#" );
    classList.Add( "CS 250", "Basic Data Structures Using C++" );
    classList.Add( "CS 255", "Basic Data Structures Using Java" );
    classList.Add( "CS 200H", "HON: Concepts of Programming Algorithms Using C++" );
    classList.Add( "CS 210H", "HON: Discrete Structures I" );
    classList.Add( "CS 211H", "HON: Discrete Structures II" );

    classList.Display();

    cout << endl << "Class list contains CS 100? " << classList.Contains( "CS 100" ) << endl;
    cout << endl << "Class list contains CS 134? " << classList.Contains( "CS 134" ) << endl;
    cout << endl << "Value of 134: " << classList.GetValue( "CS 134" ) << endl;
    cout << endl << "List size: " << classList.GetSize() << endl;

    return 0;
}
