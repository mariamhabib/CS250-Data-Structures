// Part 1: Pointers and Memory Addresses

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

#include "Person.hpp"

void SetupPeople( Employee employees[10], Customer customers[10] );

// Duplicate code is bad. :(
void EditEmployee( Employee& employee )
{
    string newName;
    cout << endl;
    cout << "Current name: " << employee.name << endl;
    cout << "New name: ";
    cin >> newName;
    employee.name = newName;
}

void EditCustomer( Customer& customer )
{
    string newName;
    cout << endl;
    cout << "Current name: " << customer.name << endl;
    cout << "New name: ";
    cin >> newName;
    customer.name = newName;
}

void DisplayEmployees( const Employee employees[10] )
{
    for ( int i = 0; i < 10; i++ )
    {
        employees[i].Display();
    }
}

void DisplayCustomers( const Customer customers[10] )
{
    for ( int i = 0; i < 10; i++ )
    {
        customers[i].Display();
    }
}

int main()
{
    Employee employees[10];
    Customer customers[10];
    SetupPeople( employees, customers );

    bool done = false;
    while ( !done )
    {
        char choice;
        int index;

        cout << "Edit [E]mployee or [C]ustomer, or [V]iew all? >> ";
        cin >> choice;

        if ( tolower( choice ) == 'v' )
        {
            DisplayEmployees( employees );
            DisplayCustomers( customers );
            continue;
        }

        cout << "Enter the index (0 to 9). >> ";
        cin >> index;

        if ( tolower( choice ) == 'e' )
        {
            EditEmployee( employees[index] );
        }
        else if ( tolower( choice ) == 'c' )
        {
            EditCustomer( customers[index] );
        }
    }

    return 0;
}


void SetupPeople( Employee employees[10], Customer customers[10] )
{
    employees[0].name = "Aishwarya";    employees[0].wage = 9.00;
    employees[1].name = "Blanca";       employees[1].wage = 10.00;
    employees[2].name = "Chin";         employees[2].wage = 8.00;
    employees[3].name = "Despoina";     employees[3].wage = 11.00;
    employees[4].name = "Evdokiya";     employees[4].wage = 9.50;
    employees[5].name = "Fady";         employees[5].wage = 9.00;
    employees[6].name = "Gavriil";      employees[6].wage = 10.00;
    employees[7].name = "Hana";         employees[7].wage = 9.25;
    employees[8].name = "Hiroto";       employees[8].wage = 11.00;
    employees[9].name = "Itzel";        employees[9].wage = 13.00;

    customers[0].name = "Jeong";        customers[0].isSatisfied = true;
    customers[1].name = "Kimiko";       customers[1].isSatisfied = true;
    customers[2].name = "Lelia";        customers[2].isSatisfied = false;
    customers[3].name = "Mario";        customers[3].isSatisfied = true;
    customers[4].name = "Ngoc";         customers[4].isSatisfied = true;
    customers[5].name = "Osip";         customers[5].isSatisfied = true;
    customers[6].name = "Priscila";     customers[6].isSatisfied = false;
    customers[7].name = "Qusai";        customers[7].isSatisfied = true;
    customers[8].name = "Seung";        customers[8].isSatisfied = true;
    customers[9].name = "Trung";        customers[9].isSatisfied = true;
}
