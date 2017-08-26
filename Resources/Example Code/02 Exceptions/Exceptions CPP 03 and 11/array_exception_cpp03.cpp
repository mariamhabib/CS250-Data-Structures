#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

const int MAX_STUDENTS = 10;

class StudentList
{
    public:
    void SetStudent( int index, string name ) throw(out_of_range);
    
    string GetStudent( int index ) throw(out_of_range);
    
    private:
    string students[MAX_STUDENTS];
};

void StudentList::SetStudent( int index, string name ) throw(out_of_range)
{
    if ( index < 0 || index >= MAX_STUDENTS )
    {
        throw out_of_range( "Invalid index" );
    }

    students[ index ] = name;
}

string StudentList::GetStudent( int index ) throw(out_of_range)
{
    if ( index < 0 || index >= MAX_STUDENTS )
    {
        throw out_of_range( "Invalid index" );
    }

    return students[ index ];
}

int main()
{
    return 0;
}
