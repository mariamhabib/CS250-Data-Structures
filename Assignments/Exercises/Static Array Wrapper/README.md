# Homework Exercise: Wrapping a Static Array

## Downloads

Download the starter files for this project.

* Visual Studio project
* Code::Blocks project

Or you can download the files directly on GitHub:

* [main.cpp]()
* [SmartStaticArray.hpp]()
* [SmartStaticArray.cpp]()
* [Tester_SmartStaticArray.hpp]()
* [Tester_SmartStaticArray.cpp]()

## Rules

### Open book / Open note:
    Do research for this assignment as-needed. Use your textbook, the web, class example code, etc.
     
### Solo work
    
    This is a solo assignment and you should be working on this alone. This means...:
    
        ✓ You can verbally brainstorm with others to discuss the problem and techniques for problem solving.
        
        ✓ Your work must be your own work.
        
        ✓ Email the instructor, or ask in the Slack channel, if you are stuck or need clarification on the instructions.
        
        ✗ You cannot give your code to somebody else for them to "verify their work" with (more often than not they just copy it, and then you both get 0%!)
        
        ✗ You cannot copy another student's work. I will use a diff tool to compare student assignments (and code online). If there is obvious copying, all people involved will receive a 0%.

* Team size: 1 person
    * You can brainstorm with others - that is, you can verbally discuss the problem.
    * You cannot copy another person's work. Code will be checked against other submissions with a diff tool. If a copy is found, both people will receive a 0 on the assignment.
* Open book / open note - do research as-needed.

 
## Overview

The starter files contain the stub for the Smart Array, with functions
that need to be implemented.

The project also contains tester files that you can use to judge
whether your functions are working properly.

## Turn in

Once you're done, upload all source files (.cpp, .hpp, .h) to the class dropbox
and up on your GitHub page.

---

# Explanation

For this program, you will be building a smart static array.

Included in the files is a tester. This will test every function of your
array implementation, and either pass or fail the tests.
If a test fails, it gives a comment hint.

You will need to figure out the algorithms for the array functionality,
but these testers will help you figure out if you're on the right path.

All you have to do is run the program, and the test is executed
when main() starts.

---

# SmartStaticArray Specification

The SmartStaticArray already has its member variables and functions declared.

The class contains a string array, **m_data**, and an item count, **m_itemCount**.
There is also a global named constant, **MAX_SIZE**.

The following functions are declared, but not implemented:

* SmartStaticArray();
* bool Push( const string& newItem );
* bool Insert( int index, const string& newItem );
* bool Extend( const SmartStaticArray& other );
* bool Pop();
* bool Remove( int index );
* string Get( int index ) const;
* int Size() const;
* bool IsFull() const;
* bool IsEmpty() const;
* string operator[]( int index );
* SmartStaticArray& operator=( const SmartStaticArray& other );
* bool operator==( const SmartStaticArray& other );

Descriptions of the functions are below.

## Functions

### SmartStaticArray()

The constructor is automatically run when a SmartStaticArray is *instantiated*.

### bool Push( const string& newItem )

* INPUT: A new item to add to the array
* OUTPUT: True on success, False on failure

Push should insert an item to the *end* of the array. For example,
the first item will go at 0, then the next one at 1, then 2, and so on.

It should return false if the array happens to be full. Otherwise,
it will return true if the assignment was successful.

### bool Insert( int index, const string& newItem )

* INPUT: The index to insert the new item, the new item to add to the array
* OUTPUT: True on success, False on failure

Insert will allow an item to be inserted into the middle of the array,
or at the end or at the beginning.

This should not overwrite existing elements; you will need to shift
all existing elements over to make room for this new item.

**NON-CONTIUGOUS** items are not allowed - if you have an array of size 5, 
you cannot insert something at position 100. Make sure to return false in this case,
without changing the array.

Make sure to validate the index: It shouldn't be negative, or MAX_SIZE or greater.
Return false if there is an invalid index given, without changing the array.

If the insert is successful, return true.

### bool Extend( const SmartStaticArray& other )

* INPUT: A second array
* OUTPUT: True on success, False on failure

This function will take the second array, and append it to the end
of **this** array.

If there isn't enough room to append the second array, then return false
without modifying the **this** array.

After the extend, return true on success.

### bool Pop()

* INPUT: None
* OUTPUT: True on succes, False on failure

This function will remove the item at the very end of the array.

Lazy-deletion: You don't actually have to remove the item;
you just have to adjust *m_itemCount*.

If the array is empty, return false and don't do anything.
Otherwise, return true.

### bool Remove( int index )

* INPUT: Index of item to remove
* OUTPUT: True on succes, False on failure

Remove the item at the given index. If there are any items to
the *right* of this element, shift them over left to fill in the
space so that the array remains continugous.

If the index is invalid (negative or MAX_SIZE or greater), then return
false without doing any modifications.

On success, return true.

### string Get( int index ) const

* INPUT: Index of item to access
* OUTPUT: Value of the item accessed

Return the value of the item at the index given.

If the index is invalid, return an empty string instead. ""

### int Size() const

* INPUT: None
* OUTPUT: Count of items in the array

Return the count of items stored in the array.

### bool IsFull() const

* INPUT: None
* OUTPUT: True if full, false if not full

### bool IsEmpty() const

* INPUT: None
* OUTPUT: True if empty, false if not empty

### string operator[]( int index )

* INPUT: Index of item to access
* OUTPUT: Value of the item accessed

Basically the same functionality as Get(), but it is the subscript operator.

### SmartStaticArray& operator=( const SmartStaticArray& other )

* INPUT: A second array
* OUTPUT: A reference to the **this** array

Set the **this** array equal to the second array's values.

Iterate through all the items of the second array, copying the values over
to the **this** array.

Make sure to also update the *m_itemCount*.

Return a reference to *this afterward.

### bool operator==( const SmartStaticArray& other )

* INPUT: A second array
* OUTPUT: True if the second array is the same as **this**, or False if not.

Iterate through all elements of both arrays and compare the values.

If they are equivalent, then return true.

Otherwise, return false.

---

# Grading Rubric

<table border="0" cellspacing="0" cellpadding="0" class="ta1"><colgroup><col width="12"/><col width="175"/><col width="256"/><col width="163"/><col width="162"/></colgroup><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td colspan="4" style="text-align:left;width:113.44pt; " class="ce1"><p>Grading Rubric</p></td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce2"><p>Name:</p></td><td colspan="3" style="text-align:left;width:165.94pt; " class="ce7"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce2"><p>Assignment:</p></td><td colspan="3" style="text-align:left;width:165.94pt; " class="ce8"><p>CS 250, Wrapping a static array HWEX</p></td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td colspan="4" style="text-align:left;width:113.44pt; " class="ce1"><p>Breakdown</p></td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce3"><p>Item</p></td><td style="text-align:left;width:165.94pt; " class="ce3"><p>Description</p></td><td style="text-align:left;width:105.76pt; " class="ce3"><p>Total %</p></td><td style="text-align:left;width:104.94pt; " class="ce3"><p>Your Score</p></td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce4"><p>Builds &amp; Runs</p></td><td style="text-align:left;width:165.94pt; " class="ce9"> </td><td style="text-align:right; width:105.76pt; " class="ce12"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce12"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce5"><p>Clean Code</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce13"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce13"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce4"><p>No logic errors</p></td><td style="text-align:left;width:165.94pt; " class="ce9"> </td><td style="text-align:right; width:105.76pt; " class="ce12"><p>10.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce12"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce5"><p>Constructor</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce13"><p>2.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce13"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce4"><p>Push</p></td><td style="text-align:left;width:165.94pt; " class="ce9"> </td><td style="text-align:right; width:105.76pt; " class="ce12"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce12"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce5"><p>Insert</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce13"><p>13.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce13"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce4"><p>Extend</p></td><td style="text-align:left;width:165.94pt; " class="ce9"> </td><td style="text-align:right; width:105.76pt; " class="ce12"><p>13.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce12"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce5"><p>Pop</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce13"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce13"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce4"><p>Remove</p></td><td style="text-align:left;width:165.94pt; " class="ce9"> </td><td style="text-align:right; width:105.76pt; " class="ce12"><p>10.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce12"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce5"><p>Get</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce13"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce13"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce4"><p>Size</p></td><td style="text-align:left;width:165.94pt; " class="ce9"> </td><td style="text-align:right; width:105.76pt; " class="ce12"><p>2.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce12"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce5"><p>IsFull</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce13"><p>2.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce13"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce4"><p>IsEmpty</p></td><td style="text-align:left;width:165.94pt; " class="ce9"> </td><td style="text-align:right; width:105.76pt; " class="ce12"><p>2.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce12"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce5"><p>Operator[]</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce13"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce13"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce4"><p>Operator=</p></td><td style="text-align:left;width:165.94pt; " class="ce9"> </td><td style="text-align:right; width:105.76pt; " class="ce12"><p>8.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce12"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce5"><p>Operator==</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce13"><p>8.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce13"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce5"> </td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:left;width:105.76pt; " class="ce13"> </td><td style="text-align:left;width:104.94pt; " class="ce13"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce6"> </td><td style="text-align:left;width:165.94pt; " class="ce6"> </td><td style="text-align:left;width:105.76pt; " class="ce14"> </td><td style="text-align:left;width:104.94pt; " class="ce14"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce2"><p>Totals</p></td><td style="text-align:left;width:165.94pt; " class="ce2"> </td><td style="text-align:left;width:105.76pt; " class="ce14"> </td><td style="text-align:left;width:104.94pt; " class="ce14"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce6"> </td><td style="text-align:left;width:165.94pt; " class="ce6"> </td><td style="text-align:right; width:105.76pt; " class="ce14"><p>100.00%</p></td><td style="text-align:right; width:104.94pt; " class="ce15"><p>0.00%</p></td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce6"> </td><td style="text-align:left;width:165.94pt; " class="ce6"> </td><td style="text-align:left;width:105.76pt; " class="ce6"> </td><td style="text-align:left;width:104.94pt; " class="ce6"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td colspan="4" style="text-align:left;width:113.44pt; " class="ce1"><p>Notes</p></td></tr></table>




