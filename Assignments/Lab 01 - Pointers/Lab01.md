# CS 250 - Lab 1

## Working with Pointers, Memory Management, and Dynamic Arrays

Read this document in Chrome if you want answers to be hidden
as "spoilers" until you choose to open them!

---

## Introduction

It is important to remember and understand the concepts of pointers
as you will be working with them throughout the class.


### Turn-in

Upload your **.cpp**, **.hpp** (or **.h**) files.

Project files are not needed.

### Group Work Policy

* Group work is allowed for this assignment.
* You can also ask questions between each other.
* You are allowed to research on the internet.
* You are allowed to ask the instructor for help.

---

# Program A: Pointers and Classes

![screenshot](images/screenshot.png)

## Setup

Make sure to download the base project, "A - Pointers and Classes".

Create a new project and import these files into the project.

### Person.hpp

You won't have to update this file; it contains three classes:
**Person**, an abstract class, **Employee** and **Customer**, which
inherit from Person.

Each of these have a **Display()** method, which will display
information about each object.

### main.cpp

Contains the core functionality using arrays.

* EditEmployee - Allows user to change name of an employee
* EditCustomer - Allows user to change name of a customer
* DisplayEmployee - Displays all employees
* DisplayCustomer - Displays all customers

Notice that for these two pairs of functions have a lot of duplicate
code; we will be updating this to cut down on duplication.

Within **main()**, there is a program loop, where you can edit an
employee, a customer, or view everybody. The list of Employees and
Customers are stored in two static arrays.

## Using Pointers

We're going to update this program to take advantage of pointers.

Since Employee and Customer both inherit from the Person class,
we can essentially treat them as generic "Person" objects instead
of having separate functions for each type.

### EditPerson function

Instead of utilizing EditEmployee and EditCustomer, we can create
a generic function that will have the same code.

You can either make a version with a *reference* to a Person:

	void EditPerson( Person& person )
	{
	}

Or a version that has a *pointer* to a Person:

	void EditPerson( Person* ptrPerson )
	{
	}

The way that the "person"/"ptrPerson" parameter will be accessed will
vary slightly depending on which you do.

The internals of the function will be similar to the existing Display
functions, so you can start with this as a guideline:

    string newName;
    cout << endl;
    cout << "Current name: " << employee.name << endl;
    cout << "New name: ";
    cin >> newName;
    employee.name = newName;
    
But we're going to want to remove "employee" and use our new parameter.

**Using the Reference (Person& person):** Simply swap "employee" with "person".

**Using the Pointer (Person* ptrPerson):** You will swap "employee" with "ptrPerson",
but the pointer needs to be **dereferenced** in order to get to the object's
internal member variables.

<details>
	<summary>Method one, dereferencing the pointer THEN getting the name.</summary>
	(*ptrPerson).name
</details>	

	
*Keeping the dereference in parenthesis is required.
Order of operations re dereferencing and the dot operator.*

<details>
	<summary>Method two, using the "member-of" operator shorthand.</summary>
	ptrPerson->name
</details>	
	

After you've written the function, down in **main()**, 
change the references to EditCustomer and EditEmployee to both just
call EditPerson.

<details>
	<summary>**If your parameter is a reference:** Then your code will look like:</summary>
	EditPerson( customers[index] );
</details>	
	
<details>
	<summary>
		**If your parameter is a pointer:** Then you need to pass in the
		*address* of the person, so it will look like this:
	</summary>
	EditPerson( &employees[index] );
</details>	

	
#### Test!

Make sure to build and test the program to make sure it still works properly!

#### Double-check

Here is the relevant code so you can check:

	// Reference version
	void EditPerson( Person& person )
	{
		string newName;
		cout << endl;
		cout << "Current name: " << person.name << endl;
		cout << "New name: ";
		cin >> newName;
		person.name = newName;
	}

	// Pointer version
	void EditPerson( Person* ptrPerson )
	{
		string newName;
		cout << endl;
		cout << "Current name: " << ptrPerson->name << endl;
		cout << "New name: ";
		cin >> newName;
		ptrPerson->name = newName;
	}

	// main():
	// Reference version
	if ( tolower( choice ) == 'c' )
	{
		EditPerson( customers[index] );
	}
	
	// Pointer version
	if ( tolower( choice ) == 'e' )
	{
		EditPerson( &employees[index] );
	}


### Creating an array of pointers

In **main()**, after

	Employee employees[10];
    Customer customers[10];
    SetupPeople( employees, customers );
    
we will create an array of pointers that will store all the 
Employees and Customers, all lumped in together.

This array will be a static array, it will be of size 20, and
it will store Person pointers.

<details>
	<summary>Your declaration will look like this:</summary>
	Person* people[20];
</details>

Then, create a for-loop that iterates from 0 to 10 to populate each
element of the array with the employees and customers.

Remember that because the people array stores pointers, you need
to get the address of each employee/customer as you're storing it
in the array.

1. Set indices 0 - 9 of the *people* array to employees 0 - 9.
2. Set indices 10 - 19 of the *people* array to customers 0 - 9.

<details>
	<summary>View solution</summary>
    <pre>
    for ( int i = 0; i < 10; i++ )
    {
        people[i] = &employees[i];
        people[i+10] = &customers[i];
    }
    </pre>
</details>

### Creating a DisplayPeople function

Now we're going to replace the DisplayEmployees and DisplayCustomers
functions with a generic DisplayPeople function.

	void DisplayPeople( Person* people[20] )
	{
	}

Its parameter will be the same array of Person pointers.

Within the function, iterate through each element of the people array,
and call the **Display()** function for each person.

Remember that, since these are pointers we're dealing with, you have 
to either **dereference then use the dot operator** or **use the
address-of operator**.

<details>
	<summary>View solution</summary>
    <pre>
    for ( int i = 0; i < 20; i++ )
    {
        people[i]->Display();
    }
    </pre>
</details>

Within **main()**, change out the code for "view all" to
call DisplayPeople, with the *people* array we created earlier.

#### Test!

Make sure to build and test the program to make sure it still works properly!

### Turn in

Zip up your source files and label them "Lab1A.zip" and upload this 
project to the Dropbox.

If you worked with someone else, make sure to put their name in the
Dropbox comments.

---

