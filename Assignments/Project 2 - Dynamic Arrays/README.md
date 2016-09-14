# Programming Assignment 2: Dynamic Arrays

## Introduction

For this project, a document management program has already been written for you.

It is currently using the **vector** structure from the C++
Standard Template Library.

In this project, we will be replacing the usage of the vector class
with our own list structure.

### Turn-In

Make sure to turn in all source files (.cpp and .hpp)

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

