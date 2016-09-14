# Programming Assignment 2: Dynamic Arrays

## Introduction

For this project, a document management program has already been written for you.

It is currently using the **vector** structure from the C++
Standard Template Library.

In this project, we will be replacing the usage of the vector class
with our own list structure.

### Turn-In

Make sure to turn in all source files (.cpp and .hpp)

If you worked in a team, make sure to add a comment to the submission (in Dropbox) with the link to your repository so the instructor can view the commit log.

### Group Rules

* You can work on this program in teams of 2. However, if you're 
working as a group, you must collaborate through source control
and the repository / commit log must be made available to the instructor.

---

# Data Structures

## The Vector Class

The [cplusplus.com website has reference docs for vector](http://www.cplusplus.com/reference/vector/vector/)

We will be interested in writing our own list class with the following
features:

* push_back (or "append") - Add an item to the list
* erase - Remove an item from the list, at a specific index
* operator[] - Access specific items in the list
* size - Return the amount of items in the list

You will also want to implement your own functions to handle the
behind-the-scenes work, such as resizing the array, freeing and
allocating memory, etc.

## Your List Class

You will be updating the **DocList.cpp** file to complete the
implementation of the list.

### Array of Pointers

Note that the list uses a **Dynamic Array of Pointers**, which looks like this in the code:

    IDocument ** m_ptrDocArray;

This means that both the dynamic array itself will need to have memory allocated for it (for whatever size it begins as), and each element
of the array also must be dynamically created (but this is done in ImageCowProgram when creating a new document).

The result of this is that you have to remember to free all memory when the DocList goes out of scope!

### IDocument*

The **Document.hpp** file contains several classes:

* IDocument - an abstract base class
* TextDocument
* WebDocument
* CsvDocument

TextDocument, WebDocument, and CsvDocument inherit from the same
IDocument "interface", so they share certain functions,
such as Save, Load, GetFilename, GetType, and GetFriendlyName.

Because they have a common parent and they are using **virtual** methods,
we can simply store an array of pointers to the parent interface IDocument, treat them all as IDocuments - our list doesn't care
what specifically the class is.

### Private members of DocList

DocList contains the following private members:

	IDocument ** m_ptrDocArray;
	int m_itemCount;
	int m_arraySize;

The m_itemCount variable keeps track of how many items are currently in the array, while the m_arraySize variable keeps track of the actual size of the array (how many "slots" have been allocated to it).

---

# DocList function specifications

## AllocateMemory

*This function allocates memory for the array, used to initialize it*

First, you need to check if the **m_ptrDocArray** variable is
pointing to any memory.
Basically, if it is NOT a *nullptr*, then display an error message
and return from the function.

	if ( m_ptrDocArray != nullptr )
	{
		cerr << "Error: Memory has already been allocated!" << endl;
		return;
	}

After that check, it should be assumed that m_ptrDocArray is pointing
to a nullptr so we can allocate the memory to get the array ready.

1. Instantiate the m_ptrDocArray using the **new** keyword.
	1. Remember that this is an array of pointers, so you are NOT
	allocating it as a "new IDocument[size]" - it has to be IDocument pointers.

2. Iterate through every element of the array m_ptrDocArray:
	1. Assign every element of the m_ptrDocArray to a nullptr.

3. Make sure to set the member variable m_arraySize to the size that was passed in.


## FreeDocument

*This function will take in an index and free the memory that the pointer element is pointing to.*

1. Check to see if the element at this index is pointing to nullptr.
2. If it is already pointing to nullptr:
	1. Display an error message and return. "Error: No item at index " (then display the index).
	2. Return false.
3. If the element is NOT pointing to nullptr, then:
	1. Delete the memory at that address. (**delete** keyword)
	2. Point the element to nullptr.
	3. Return true.


## FreeMemory

1. Check to see if m_ptrDocArray is already pointing to a nullptr.
2. If it is NOT pointing to nullptr...
	1. Iterate through every element of the array, calling FreeDocument on each index.

## DocList Constructor

This function should initialize the m_ptrDocArray as a *nullptr*,
then call the **AllocateMemory** function. 

Start off by passing AllocateMemory a small number, so when you're testing it gets a chance to resize the array during some AddItem calls.

## DocList Destructor

Call the FreeMemory method.

## GetSize

Return the value of m_itemCount;

## operator[]

*Return the IDocument pointer at the index passed in.*

1. If the index is valid (between 0 and the item count):
	1. Return the element at that position.
2. Otherwise...
	1. Display an error message "Error: Accessing index outside of list"
	2. Return a nullptr.

## ResizeArray

*Create a new dynamic array, copy the values over from the old array, then free up necessary memory.*

1. Increment the array size (m_arraySize) by 10 (or some other amount).
2. Create a new IDocument** array. (use the new keyword).
3. Copy over the items from the old m_ptrDocArray to the new array.
4. Destroy the m_ptrDocArray (NOT its elements)
5. Point the m_ptrDocArray to the new list.
6. Return true (until we deal with try/catch statements, this will stay as just true).

Note, when you're deleting the array itself, this will work:

	delete [] m_ptrDocArray

This will not destroy the elements, it only destroys the list itself.


## AddItem

*Add an item to the array*

1. First, check to see if the array is full (is the item count the same as the array size?). If so...
	1. Resize the array with ResizeArray.
	2. If ResizeArray returned false...
		1. Display an error message: "Error: Resizing array failed!"
		2. Return false
3. After the resize, add the new item to the end of the list (at position m_itemCount)
4. Increment m_itemCount by 1.
5. Return true.


## ShiftItemsLeft

*Move all items over to keep all elements concurrent in the list.*

1. First, check to see if the element at that index is pointing to nullptr (we don't want to overwrite the pointer to allocated memory, because then it would be lost forever!). If it is not nullptr...
	1. Display an error message: "Error: Cannot overwrite non-null element!"
	2. Return
3. Otherwise:
	1. Iterate through the elements in the list, from the *index* passed in, to the end of the list (m_itemCount). For each...
		1. Copy the item immediately to the "right" of the element over to the current element.
2. After the loop, make sure to **free** the item at position *m_itemCount-1*, because otherwise it would be a duplicate!
3. Decrease the item count m_itemCount by one.


## RemoveItem

*Remove an item at that index and shift everything over*

1. Call the FreeDocument function, passing in the index. If it fails, return false. Otherwise...
2. Call the ShiftItemsLeft function, passing in the index.
3. Return true.
