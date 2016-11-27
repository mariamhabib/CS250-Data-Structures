#include <string>
#include <iostream>
using namespace std;

#ifndef STUDENT_HPP
#define STUDENT_HPP

class StudentList
{
    public:
    StudentList();
    ~StudentList();

    void AddNewStudent();
    void ViewAllStudents();

    private:
    bool IsArrayFull();
    void ResizeArray();

    string* m_studentList;
    int m_studentCount;
    int m_arraySize;
};

#endif
