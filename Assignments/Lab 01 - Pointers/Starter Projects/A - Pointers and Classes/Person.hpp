#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
using namespace std;

class Person
{
    public:
    Person() { type = "Person"; }
    virtual void Display() const = 0;
    string name;
    string type;
};

class Employee : public Person
{
    public:
    Employee() { type = "Employee"; }
    virtual void Display() const
    {
        cout << "Wage: $" << wage << "\t Type: " << type << "\t Name: " << name << endl;
	}

    float wage;
};

class Customer : public Person
{
    public:
    Customer() { type = "Customer"; }
    virtual void Display() const
    {
        cout << "Is satisfied? " << isSatisfied << "\t Type: " << type << "\t Name: " << name << endl;
	}

    bool isSatisfied;
};

#endif
