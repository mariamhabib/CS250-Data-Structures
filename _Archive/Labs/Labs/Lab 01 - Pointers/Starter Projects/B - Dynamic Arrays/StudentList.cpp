#include "StudentList.hpp"

StudentList::StudentList()
{
}

StudentList::~StudentList()
{
}

void StudentList::AddNewStudent()
{
    cout << endl << "NEW STUDENT" << endl;
    if ( IsArrayFull() )
    {
        cout << "Not enough space! resize..." << endl;
        cout << "Old array size: " << m_arraySize << "\t Old address: " << m_studentList << endl;
        ResizeArray();
        cout << "New array size: " << m_arraySize << "\t New address: " << m_studentList << endl;
    }
}

void StudentList::ViewAllStudents()
{
    cout << endl << "VIEW ALL STUDENTS" << endl;
}

bool StudentList::IsArrayFull()
{
    return m_studentCount == m_arraySize;
}

void StudentList::ResizeArray()
{
    // Create a bigger array

    // Copy over the information

    // Free the old memory

    // Update the pointer
}
