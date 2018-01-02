# Binary Search Tree Lab

## Introduction

You will use the pre-written Dictionary class for this project:

* BinaryTree.hpp
* Dictionary.txt

This dictionary doesn't use templates - the key and the value are both expected to be strings.

## Turn-in

Upload your **.cpp**, **.hpp** (or **.h**) files.

## Group Work Policy

* Group work and/or collaboration is allowed for this assignment.
* You are allowed to research on the internet.
* You are allowed to ask the instructor for help.

---

# String Operations

You will need the reference documentation for the following:

* [substr](http://www.cplusplus.com/reference/string/string/substr/)
* [find](http://www.cplusplus.com/reference/algorithm/find/)
* [getline](http://www.cplusplus.com/reference/string/string/getline/)

---

# Instructions

You are going to create a copy of your [Dictionary program] from [Lab 8](https://github.com/Rachels-Courses/CS250-Data-Structures/tree/master/Assignments/Lab%2008%20-%20Dictionary), but implement it with a Binary Search Tree instead.

## Modifications to BinaryTree.hpp

The node for this structure has a Node that only contains data. You will need to update this object to store a **key** and a **value** instead. You can either make these both templates, or just hard-code them as strings.

For the BinaryTree, you will need to update some functions to work with the key/value pair...:

### Insert

Update this function so it takes in a key and a value, rather than just a value. Set up the Node's key and value and allow it to be inserted through RecursiveInsert.

### Remove

Update this function so that it uses a key instead of a value.

### Contains

You will change this function to work with the key of the Node rather than the value.

### RecursiveInsert

You will change this function to work with the key of the Node rather than the value. (It checks the **data** value at the moment to decide whether to traverse left or right.)

### RecursiveFind, RecursiveParentFind

Use **key** instead of **data**.

### RecursivePreorder, RecursiveInorder, RecursivePostorder

Update these functions to display the **key** and **value** instead of the **data**.

### New function: Get

Similar to the dictionary function, this will look for a node whose **key** is exactly the same as the passed-in search key, and then return the value.

The find function is listed on the bottom for bonus points if you want to attempt it.

## Program updates

Currently, the program just asks for an English string and returns an Esperanto string, if found.

Add a simple main menu that lets the user enter a key, and use the Remove function to find that node and remove it.

---

## Bonus points:

Implement a function, "Find", which is the same as the dictionary version - it searches **all** nodes in the tree to find a partial match, and keeps a list of all key/values that match, returning that back to the program.