# Project 4: Tic Tac Toe Stacks

![Screenshot](images/screenshot.png)

## Introduction

For this project, a tic tac toe game has been implemented in C++. You can left-click to place a move, and right-clicking (anywhere) will cause the game to back up by one turn.

This is achieved by storing the state of the grid in a stack every time a move is made.

You will be replacing the STL Stack in the project files with your own stack.

## Turn-In

* Zip up your entire project folder, including the **SDL2-2.0.4** folder, and turn it in via the project Dropbox.

## Group Policy

You can work with another person on this program in teams of 2. However, if you're 
working as a group, you **must** collaborate through source control
and the repository / commit log must be made available to the instructor.

---

# Files Overview

The solution has already been set up to use the [SDL](https://www.libsdl.org/) library to handle drawing basic graphics. Make sure you open the solution file when getting started.

These files are included with the project:

* Files that you won't work with:
	* Application (.hpp, .cpp) - Includes functions for getting SDL set up. 
	* Drawer (.hpp, .cpp) - Includes functions for drawing primitive shapes. 
	* main.cpp - Starts the program.
	* GameBoard.hpp - Contains a 2D char array to represent the game board. 
* Files that you will work with:
	* TicTacToe (.hpp, .cpp) - This class contains a stack of game boards to keep track of history. You will need to update this and a couple other functions (see below).

---

# TicTacToe class

For most of this class, you do not have to make any modifications - all the game logic is already implemented.

However, in the class declaration, a stack of game boards is stored:

	stack<GameBoard> m_gameHistory;

You will eventually be replacing this STL stack with your own Stack object.

Additionally, these two methods handle everything that the game does with the stack:

	void UndoLastMove();
	void PushHistory();

Once your Stack object is implemented, you might have to update these functions (such as, if your push function is named something else.)

---

# DoublyLinkedList Class

Before implementing a Stack, you should implement a generic DoublyLinkedList class. This class should utilize templates and have the standard functions needed for a doubly linked list. Additionally, your LinkedList class should also utilize exceptions and throw exceptions as appropriate.

## Node of a DoublyLinkedList

![Node diagram](images/node_diagram.png)

Note: + is public, top portion is variables, bottom portion is functions.

What makes a DoublyLinkedList "doubly" is that the Node structure/class contains two pointers - one to the next node, and one to the previous node.

### Variables:

* Node<T>* ptrNext
* Node<T>* ptrPrev
* T data

### Functions:

* A constructor should initialize its pointers to **nullptr**.

## DoublyLinkedList

![DoublyLinkedList Diagram](images/doublylinkedlist.png)

Note: + is public, # is protected, top portion is variables, bottom portion is functions.

The DoublyLinkedList will need to be a generic object, because we will be implementing the **Stack** and, later, the **Queue** with this object. Once it is written once, implementing the Stack will use some of these functions, but not require all of them (though some of these functions will be useful for the Queue or a generic List later on.)

### Member Variables

* ptrFirst
* ptrLast
* itemCount

### Member Methods

Initialization/Deinitialization:

* Constructor
* Destructor

List manipulation:

* PushFront
* PopFront
* GetFront
* PushBack
* PopBack
* GetBack
* PushItemAt
* PopItemAt
* GetItemAt


Other:

* GetSize

---

# Stack Class

Your Stack class should be built *on top of* your LinkedList class. You will use a "has-a" (compositional) relationship.

The Stack will contain the functions:

WIP

These functions will act as an interface, delegating the actual tasks to the underlying LinkedList.

---

# Grading Rubric

WIP
