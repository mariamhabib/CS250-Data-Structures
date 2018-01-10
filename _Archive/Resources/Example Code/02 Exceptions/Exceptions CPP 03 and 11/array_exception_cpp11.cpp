#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

const int MAX_STUDENTS = 10;

class StudentList
{
    public:
    void SetStudent( int index, string name );
    
    string GetStudent( int index );

    void SafeFunction( int abc ) noexcept;
    
    private:
    string students[MAX_STUDENTS];
};

void StudentList::SetStudent( int index, string name )
{
    if ( index < 0 || index >= MAX_STUDENTS )
    {
        throw out_of_range( "Invalid index" );
    }

    students[ index ] = name;
}

string StudentList::GetStudent( int index )
{
    if ( index < 0 || index >= MAX_STUDENTS )
    {
        throw out_of_range( "Invalid index" );
    }

    return students[ index ];
}

void StudentList::SafeFunction( int abc ) noexcept
{
    cout << "Hi!" << abc << endl;
}

int main()
{
    return 0;
}
