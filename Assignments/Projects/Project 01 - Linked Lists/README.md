# Linked list project

CS 250, Spring 2017

![screenshot](images/LinkedListScreenshot.png)

## Setup

Make sure to download the starter code, which contains the shell for the doubly linked list.

## Turn-in

Upload your code to your class repository on GitHub,
as well as turning in your code in the class Dropbox.

Make sure to include **all source files: .cpp, .hpp, .h, etc.**. (Project files / solution files are not required.)

## Group work policy

* This project is a **solo effort**.
* You can brainstorm with others, but you cannot code together, share code, etc.

---

# Starter project

The starter project contains quite a few code files. You will only
be responsible for modifying **LinkedList.cpp**.

The project contains the **cuTEST** framework and **Tester.hpp** for testing,
as well as a **BookProgram** object and **Page** object - these load a book
into the program and allow you to read the book from the terminal.
There is also **CPP-Utilities**, which contain string utilities and menu
utilities -- you don't have to do anything with these.

---

# Linked list basics

A linked list is a type of structure that only allocates memory
for new objects as-needed. Unlike the Dynamic Array, it doesn't pre-allocate
large chunks of memory and resize as needed. Instead, each time a new
item is pushed into the list, memory for a new "Node" is allocated.

A linked list requires two different classes: A **Node** and a **List**.

## Node

A Node contains the data itself, as well as pointers. In a doubly-linked-list,
the Node contains pointers to the **next node** and the **previous node**.
In a singly-linked-list, the node only contains a pointer to the next node.

Using these "ptrNext", "ptrPrev" nodes, we can traverse the list by
updating a "traversal" pointer... starting at the first node,
and step-by-step going to each node's "ptrNext".

## List

The list class itself contains the standard Push, Insert, Pop, etc.
functions. Instead of storing an array as a private member variable,
instead it stores **pointers** to nodes, usually the first node
and the last node.

The list keeps track of the itemCount (amount of items that have been
pushed in), as well as the memory addresses of the first item in the list,
and the last item in the list.

When a list is empty, ptrFirst and ptrLast should be pointing to **nullptr**.

For functions like Push, there will be different sets of code that will be
executed depending on whether the list is empty, or whether there is already
something in the list. We use an if statement to check the list's state
and decide how to go about adding a new item.

If a list is empty, then ptrFirst and ptrLast should both be pointing to
nullptr.

## Memory allocation

As we add new items to the linked list, each new element needs memory allocated.

To do this, create a local pointer variable within the function where
new memory needs to be allocated.

	Node<T>* ptrNew;
	
And allocate the data...

	ptrNew = new Node<T>;
	
And you can set up the data as well.

	ptrNew->data = newItem;

You won't need to call **delete** in the same function; the **Pop** function
will be responsible for freeing any allocated memory.

## List traversal

When traversing the list, we need to make a traversal pointer, which
begins at the first item, and steps through each node via each node's
*ptrNext* pointer.

We cannot **randomly access data** in a linked list because it is not
implemented with an array. Because we only keep track of the first
and last item with pointers, we have to *traverse* the list to find
some item at position *n*.

First, we create a pointer:

	Node<T>* ptrCurrent;
	
**We do not allocate memory with this pointer!** This pointer is meant
to point at existing data.

To begin at the beginning of the list, you need to point this to the first item:

	ptrCurrent = m_ptrFirst;

And to step to the next item, make use of *ptrNext*:

	ptrCurrent = ptrCurrent->ptrNext; // Go to the next item
	
If you want to go to item *n* in the list, then you'll just have to
do the above step *n* times (via a loop.)

## Common errors

### New node pointer vs. Traversal pointer

It is common to mix up utilizing pointers for list traversal with
utilizing pointers for making new nodes. Know whether you're traversing
a list, or creating a new node!

When traversing, you **will not allocate new memory**!

---

# Linked list specs

Some of the methods have been implemented already, but you will need
to fill in others.

## void Push( const T& newItem )

When a list is first made, ptrFirst and ptrLast should be pointing
to **nullptr**. We will use this fact to check whether our list is empty
prior to adding an item.

### Adding the first item

* Allocate memory using the **m_ptrFirst** pointer.
* Set m_ptrFirst's **data** field to the data passed in as the parameter (newItem).
* Make sure to set m_ptrLast to also point to m_ptrFirst.
* Increment **m_itemCount**.

### Adding additional items

* Allocate memory for a new Node.
* Set up the new node's **data** field to the data passed in as the parameter (newItem).
* Set the new node's ptrPrev to the current m_ptrLast.
* m_ptrLast's new ptrNext value should be this new node.
* Update m_ptrLast to point to the new node.
* Increment **m_itemCount**.

## bool Insert( int index, const T& newItem )

## void Extend( const LinkedList& other )

## bool Pop()

## bool Remove( int index )

## T Get( int index ) const

## LinkedList& operator=( const LinkedList& other )

## bool operator==( const LinkedList& other )

---

# Grading rubric

<table border="0" cellspacing="0" cellpadding="0" class="ta1"><colgroup><col width="12"/><col width="175"/><col width="256"/><col width="163"/><col width="162"/></colgroup><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td colspan="4" style="text-align:left;width:113.44pt; " class="ce1"><p>Grading Rubric</p></td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce2"><p>Name:</p></td><td colspan="3" style="text-align:left;width:165.94pt; " class="ce8"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce2"><p>Assignment:</p></td><td colspan="3" style="text-align:left;width:165.94pt; " class="ce9"><p>CS 250, Linked List HW Project</p></td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td colspan="4" style="text-align:left;width:113.44pt; " class="ce1"><p>Breakdown</p></td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce3"><p>Item</p></td><td style="text-align:left;width:165.94pt; " class="ce3"><p>Description</p></td><td style="text-align:left;width:105.76pt; " class="ce3"><p>Total %</p></td><td style="text-align:left;width:104.94pt; " class="ce3"><p>Your Score</p></td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce4"><p>Builds &amp; Runs</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce14"><p>50.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce14"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce5"><p>Insert</p></td><td style="text-align:left;width:165.94pt; " class="ce11"> </td><td style="text-align:right; width:105.76pt; " class="ce15"><p>7.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce15"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce4"><p>Remove</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce14"><p>7.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce14"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce5"><p>Extend</p></td><td style="text-align:left;width:165.94pt; " class="ce11"> </td><td style="text-align:right; width:105.76pt; " class="ce15"><p>6.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce15"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce4"><p>operator=</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce14"><p>6.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce14"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce5"><p>Push</p></td><td style="text-align:left;width:165.94pt; " class="ce11"> </td><td style="text-align:right; width:105.76pt; " class="ce15"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce15"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce4"><p>Pop</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce14"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce14"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce5"><p>Get</p></td><td style="text-align:left;width:165.94pt; " class="ce11"> </td><td style="text-align:right; width:105.76pt; " class="ce15"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce15"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce4"><p>operator==</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce14"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce14"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce5"><p>Clean code</p></td><td style="text-align:left;width:165.94pt; " class="ce11"> </td><td style="text-align:right; width:105.76pt; " class="ce15"><p>2.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce15"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce4"><p>No logic errors</p></td><td style="text-align:left;width:165.94pt; " class="ce10"> </td><td style="text-align:right; width:105.76pt; " class="ce14"><p>2.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce14"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce6"> </td><td style="text-align:left;width:165.94pt; " class="ce12"> </td><td style="text-align:left;width:105.76pt; " class="ce16"> </td><td style="text-align:left;width:104.94pt; " class="ce16"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce7"> </td><td style="text-align:left;width:165.94pt; " class="ce7"> </td><td style="text-align:left;width:105.76pt; " class="ce17"> </td><td style="text-align:left;width:104.94pt; " class="ce17"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce2"><p>Totals</p></td><td style="text-align:left;width:165.94pt; " class="ce2"> </td><td style="text-align:left;width:105.76pt; " class="ce17"> </td><td style="text-align:left;width:104.94pt; " class="ce17"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce7"> </td><td style="text-align:left;width:165.94pt; " class="ce7"> </td><td style="text-align:right; width:105.76pt; " class="ce17"><p>100.00%</p></td><td style="text-align:right; width:104.94pt; " class="ce18"><p>0.00%</p></td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="ce7"> </td><td style="text-align:left;width:165.94pt; " class="ce7"> </td><td style="text-align:left;width:105.76pt; " class="ce7"> </td><td style="text-align:left;width:104.94pt; " class="ce7"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:113.44pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td colspan="4" style="text-align:left;width:113.44pt; " class="ce1"><p>Notes</p></td></tr></table>
