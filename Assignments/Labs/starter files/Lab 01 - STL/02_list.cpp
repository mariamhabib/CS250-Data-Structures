#include <iostream> // required for cout
#include <list>   // required for list
#include <string>   // required for strings
using namespace std;

void AddCourses( list<string>& courses )
{
    // Use push_back to add some courses to the courses list.
}

void DisplayCourses( list<string>& courses )
{
    // Keep as-is
    int counter = 0;
    for( list<string>::iterator it = courses.begin(); it != courses.end(); it++ )
    {
        if ( counter != 0 ) { cout << ", "; }
        cout << counter++ << ". " << (*it);
    }
}

void SortList( list<string>& courses )
{
    // Call the sort() function through the courses object.
}

void ReverseList( list<string>& courses )
{
    // Call the reverse() function through the courses object.
}

int main()
{
    // Create a list of strings, named courses.
    
    // Call the AddCourses function, passing in courses.

    // 1. Normal
    cout << "\n\nNormal order" << endl;
    // Call the DisplayCourses function, passing in courses.

    // 2. Sorted
    cout << "\n\nSorted order" << endl;
    // Call the SortList function, passing in courses.
    
    // Call the DisplayCourses function, passing in courses.

    // 3. Reversed
    cout << "\n\nReverse order" << endl;
    // Call the ReverseList function, passing in courses.
    
    // Call the DisplayCourses function, passing in courses.
    
    return 0;
}
