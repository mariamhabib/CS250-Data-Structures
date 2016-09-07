#include <string>
#include <iostream>
using namespace std;

#include "StudentList.hpp"

void AddNewStudent( string* students, int& studentCount, int& arraySize );
void ViewAllStudents( const string* students, int studentCount );
void ResizeStudentArray( string* students, int studentCount, int& arraySize );

int main()
{
    StudentList students;

    bool done = false;
    while ( !done )
    {
        cout << endl;
        cout << "1. Add new student" << endl;
        cout << "2. View all students" << endl;

        int choice;
        cout << ">> ";
        cin >> choice;

        if ( choice == 1 )
        {
            students.AddNewStudent();
        }
        else if ( choice == 2 )
        {
            students.ViewAllStudents();
        }
    }

    return 0;
}
