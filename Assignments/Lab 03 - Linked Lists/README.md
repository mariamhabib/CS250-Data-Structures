# Linked List Lab

## Introduction

For this assignment, you will read in a text file and count the amount of words
in the document.

You will modify a standard Linked List so that the node contains
a string ("word") and an int ("count").

## Turn-in

Upload your **.cpp**, **.hpp** (or **.h**) files.

## Group Work Policy

* Group work and/or collaboration is allowed for this assignment.
* You are allowed to research on the internet.
* You are allowed to ask the instructor for help.

## Setup

Make sure to download the following files:

* WordCounter.hpp
* main.cpp
* story.txt

---

## Reference

* [View a C++ implementation of Linked List](https://github.com/Rachels-Courses/CS250-Data-Structures/tree/master/Resources/Example%20Code/Singly%20Linked%20List%20with%20Templates)

---

# WordCounter Linked List

The WordCounter class is a linked list but with some changes:

* The Node class contains a word and a word-count.
* The functionality to add a new word to the list is modified
from a normal linked list so that each word can only be in the
list once - if a word is added in an additional time, it adds
one to the word count of the Node.
* The Print function outputs a text file with the word counts.

## WordCounter Constructor

1. Initialize the m_count to 0
2. Initialize the m_ptrFirst and m_ptrLast to nullptrs

## WordCount Destructor

1. Call the ClearList() function

## ClearList

Iterate through every Node of the list, freeing the memory and
settings the address to 0.
You might want to call the **FreeNode** function.

## FindItem

This function takes in a string, and you need to traverse the entire
list to find if any elements' "word" variable match the parameter.

This will return either the Node if found, or nullptr if the parameter is not found.

## AddItem

This will first need to check if there is already a node for this word.

If the word is already in the list, increment its *count* by 1.

Otherwise, create a new Node, set up the word, set its count to 1,
and add it to the list.

	* If this is the first Node of the list, you'll set the m_ptrFirst
	and m_ptrLast to the new node.
	* Otherwise you'll point the m_ptrLast's ptrNext to this new node.
	
Make sure to increment m_count, but only if you're adding a new word.

## FreeNode

First check to see if the node passed in is pointing to nullptr.

If it is not nullptr, delete the node, set the node to point to nullptr,
and decrease the *m_count*.

## Size

Return the size of the list (m_count).

## Print

Print is already set up and will display the elements of the list when called.
