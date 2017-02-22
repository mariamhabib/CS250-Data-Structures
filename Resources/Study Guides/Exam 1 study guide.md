# Data structures

![data structures icon](https://online.jccc.edu/content/enforced/83878-12334.201701/stack_queue.png?_&d2lSessionVal=vvpB1Es8rDdgm5VRKvGPaOhsm)

* [CS 201R Lecture slides - Data structures](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/master/Resources/Lecture%20Slides/20%20Data%20Structures/Data%20Structures%20Intro.pdf)
* [CS 250 Lecture slides - Data structures](https://github.com/Rachels-Courses/CS250-Data-Structures/blob/master/Lectures/Lecture%2000%20-%20What%20are%20data%20structures.pdf)
* [CS 250 Lecture video - Data structures](http://edu.moosader.com/classes/cs250/videos/CS250_Lecture00%20What%20are%20Data%20Structures.mp4)

## Knowledge

* Why do we build data structures? Why are there different types of structures?

## Vocabulary

* Interface
* Coupling
* Cohesion
* Method
* Class
* Object
* Instance/Instantiation

---

# STL structures

* [CS 201R Lecture slides - STL structures](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/master/Resources/Lecture%20Slides/19%20STL/STL.pdf) 
* [CS 201R Lecture video - STL structures](http://edu.moosader.com/_CPP_LECTURES/27%20STL.mp4) 
* [CS 250 Lecture slides - STL structures](https://github.com/Rachels-Courses/CS250-Data-Structures/blob/master/Lectures/Lecture%2001%20-%20The%20Standard%20Template%20Library.pdf)
* [CS 250 Lecture video - STL structures](http://edu.moosader.com/classes/cs250/videos/CS250_Lecture01%20Standard%20Template%20Library.mp4)

## Knowledge

* A vector is implemented with…
  * How to add items to a vector
  * How to access items in a vector
* A list is implemented with…
* Functional differences between list and vector

## Vocabulary

---

# Static arrays 

![static array icon](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/Artwork/Topics/CS250/staticarray.png?raw=true)

* [CS 200 Lecture slides - Arrays](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/master/Resources/Lecture%20Slides/08%20Arrays/Arrays.pdf)
* [CS 200 Lecture video - Arrays](http://edu.moosader.com/_CPP_LECTURES/08%20Arrays%20Lecture.mp4)
* [CS 250 Lecture slides - Wrapping a static array](https://github.com/Rachels-Courses/CS250-Data-Structures/blob/master/Lectures/Lecture%2003%20-%20Wrapping%20a%20static%20array.pdf)
* [CS 250 Lecture video - Wrapping a static array](http://edu.moosader.com/classes/cs250/videos/CS250_Lecture02%20Wrapping%20a%20static%20array.mp4)

## Knowledge

* What are the “dangers” of using a static array? What kind of validation do you need to do to ensure the structure can’t crash the program?
* How are arrays stored in memory? Why can’t static arrays be resized?
* What are things we need to keep in mind when using static arrays? (Error checking?)

---

# Pointers and memory management

![pointer icon](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/Artwork/Topics/CS200/pointers.png?raw=true)

* [CS 200 Lecture slides - Pointers](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/master/Resources/Lecture%20Slides/12%20Pointers/Pointers.pdf) 
* [CS 200 Lecture video - Pointers](http://edu.moosader.com/_CPP_LECTURES/16%20Pointer%20Lecture.mp4)
* [CS 200 Lecture slides - Memory management](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/master/Resources/Lecture%20Slides/12%20Pointers/Memory%20Management.pdf) 
* [CS 200 Lecture video - Memory management](http://edu.moosader.com/_CPP_LECTURES/17%20Memory%20Management%20Lecture.mp4)

## Knowledge

* How to declare a pointer, assign an address to it, accessing the value it is pointing to.
* Dynamic variables vs. arrays – allocating memory, freeing memory, accessing data at the address.
* Utilization of “NULL” or “nullptr” - why?
* Types of memory errors

## Vocabulary

* Stack
* Heap
* Address-of operator
* De-reference operator
* Member-access operator

## Vocabulary

---

# Dynamic arrays

![dynamic array icon](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/Artwork/Topics/CS250/dynamicarray.png?raw=true)

* [CS 200 Lecture slides - Dynamic arrays](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/master/Resources/Lecture%20Slides/12%20Pointers/Dynamic%20Arrays.pdf)
* [CS 200 Lecture video - Dynamic arrays](http://edu.moosader.com/_CPP_LECTURES/18%20Dynamic%20Arrays%20Lecture.mp4)

## Knowledge

* What are the “dangers” of using a dynamic array? What kind of validation do you need to do to ensure the structure can’t crash the program?
* When do dynamic arrays hit a speed bottleneck?
* Steps to “resize” a dynamic array
* Where local variables are allocated in memory vs. where dynamic variables are allocated.

## Vocabulary

---

# Linked lists

![linked list icon](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/Artwork/Topics/CS250/linkedlist.png?raw=true)

## Knowledge

* The anatomy of a Node class and a Linked List class
* How much space does a linked list need? How does it expand?
* Knowledge of how the following works (should understand how to be able to derive the code later):
  * Push (to back)
  * Pop (from back)
  * Insert (at index)
  * Remove (at index)
  * Operator== to Compare two linked lists

## Vocabulary

* Node
* Singly-linked list
* Doubly-linked list

---

# Algorithm efficiency

![efficiency icon](https://github.com/Rachels-Courses/Course-Common-Files/blob/master/Artwork/Topics/CS250/efficiency.png?raw=true)

* [CS 201R Lecture slides - Searching and sorting](https://github.com/Rachels-Courses/CS200-Concepts-of-Progamming-Algorithms/blob/master/Resources/Lecture%20Slides/17%20Searching%20and%20Sorting/Searching%20and%20Sorting%201.pdf) 
* [CS 250 Lecture slides - Searching and efficiency](https://github.com/Rachels-Courses/CS250-Data-Structures/blob/master/Lectures/Lecture%2002%20-%20Searching%20and%20Efficiency.pdf)

## Knowledge

* How to estimate the worst-case efficiency of an algorithm (given code).

## Vocabulary

* O(n)
* Linear
* Quadratic
* Exponential
* Logarithmic
