# Linked Lists

Linked Lists are a type of data structure that is implemented differently than the static and dynamic arrays that we've worked with so far.

**A Con of Dynamic Arrays...**

One of the problems of dynamic arrays is that, once you run out of memory, you have to spend processing time creating a new array, copying over the old array, and freeing the memory.

If your array is storing a lot of large data, or is pretty big, this could mean a noticeable performance hit.

Wouldn't it be nice to have a structure that adds memory as-needed, a little bit at a time, so that we don't have this bottleneck?

## Two parts of a Linked List

When programming a Linked List, there are two parts to it: 

The **first part** is the List class itself, which contains functions like **Add**, **Remove**, **Get**, etc., but rather than it storing an array of items internally,  it only stores pointers - usually to the very first and very last thing in the list.

The **second part** of a Linked List is the data wrapper. We create a **Node** object, which *stores the data*, but also *stores a pointer to the next item in the list* (and sometimes the previous item.)

A node looks like this:

	struct Node
	{
		string data;
		Node* ptrNext;
	};

A Node could be a class or a struct, and can contain more information than this, but this is a pretty common node and similar to what you would see in many implementations.

(Except for that "string data", usually we'd use **Templates** to be able to store other data-types than just strings!)

## Allocating memory as-needed

Let's assume we have the following List class written:

	class List
	{
		public:
		List();
		~List();

		void AddItem( const string& newItem );
		string GetItem( int index );
	
		private:
		Node* m_ptrFirst;
		int m_nodeCount;
	};

When we go to add our **first element** of the list,
we simply need to initialize m_ptrFirst as a new Node instance, set its *data* value to the new item being passed in, and make sure the "next node" it is pointing to is nullptr:

	m_ptrFirst = new Node;
	m_ptrFirst->data = newItem;
	m_ptrFirst->ptrNext = nullptr;

(And we would also want to increment m_nodeCount.)

Then, the next time we go to add something, it will now be the **second element** in the list. We can't just overwrite m_ptrFirst, but we can create a new node - which is the one it is pointing to with ptrNext:

	Node* newNode = new Node;
	newNode->data = newItem;
	newNode->ptrNext = nullptr;

	m_ptrFirst->ptrNext = newNode;

But we can't hardcode this logic, so we would have to write it in more general terms...

### Add Item pseudocode

This is assuming that we've added a constructor to our Node class that initializes the ptrNext to nullptr so we don't have to explicitly!

1. Add new data "d" to the list.
2. Is this the first item to be added to the list?
	1. YES:
		1. Instantiate our first-element Node pointer as a new item.
		2. Set its data to "d" 
		3. Add 1 to the Node Count
	2. NO: 
		1. Find the end of the list!
			1. Keep traversing through Nodes by going to each Node's *ptrNext* until one Node's *ptrNext* is *nullptr* - that's how we know we're at the end.
		2. Create and instantiate a new Node* item.
		3. Set the new item's data to "d".
		4. For the last element of the list, set its new "ptrNext" pointer to the new Node that we made.
		5. Add 1 to the Node Count

Note: If we store a pointer to the last element of our list, we don't have to *traverse* the entire list to find the last item! Then, we just go through the "last" pointer.

## Implementing a Linked List...

[View the example Linked List project here](https://github.com/Rachels-Courses/CS250-Data-Structures/tree/master/Resources/Example%20Code/Singly%20Linked%20List%20with%20Templates)

## Pros and Cons of Linked Lists

### Pros

* Avoid the stop-and-resize processing time like with a dynamic array
* Insertion and Deletion is cheap and easy - just moving pointers around!
* Stacks and Queues can be implemented easily with a Linked List

### Cons

* No random-access like with arrays: Have to traverse the list to get a specific element (Sequential access)
* More memory is needed due to next/prev pointers (vs. no pointers in an array)

### Other notes

* Elements of the list don't have to be in contiguous memory spaces like with an array.


## Common Types of Linked Lists

If your Node only points to the next item in the list, then it is a **Singly Linked List**.

If your Node points to the next and the previous Node, it is a **Doubly Linked List**.

If your "last" Node points to the "first" Node of the list, then it is a **Circular Linked List**.


## Stacks and Queues?

What's the point of having these kinds of data structures? Well, our computers run on them...

* Ever heard of "Stack Overflow"? Besides a website, it is a kind of error that can occur from running out of space, usually from calling too many functions.
	* Memory that isn't allocated dynamically is allocated on the stack, so any time you create a local variable or call a function and pass in arguments, memory is being allocated on the Stack.

* A "Message Queue" is used in a lot of software to store a list of messages (sometimes requests for something to be processed), and execute them in order. Having the queue is useful, so if a message can't be immediately processed, it waits its turn, rather than be denied and lost.

* Some User Interfaces use a "Stack" to store menus that you're on - such as when you press button A, B, then C, each one pops "Menu A", "Menu B", "Menu C", onto a stack. When you hit the "Back" button, it removes the current menu from the stack and goes backwards by one.

A **Stack** is a First-In-Last-Out or Last-In-First-Out structure.

* In Pringles, the last chip added to the can is the first one you have to eat before getting to the next chip down. 

A **Queue** is a First-In-First-Out structure.

* Like at a grocery store or anywhere else you have to stand in line - first come, first serve.

### Gotta know 'em

Just warning you early - you're going to be tested on implementations of functions of Queues and Stacks, among other things.