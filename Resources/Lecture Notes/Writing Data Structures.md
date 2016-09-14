# Writing Data Structures

## What is a Data Structure?

A Data Structure is just an object that is built for storing data, and doing operations on that data.

For example, we can "wrap" a vanilla array within a class, then add functions like "Insert", "Remove", "Length", and so on, to make utilizing that array more easy.

## Designing Data Structures

Structures have different designs based on *what* they use behind-the-scenes (arrays, pointers, etc.) and *how* they organize/handle their data.

In this class, we're going to be covering...

### **Lists** and **LinkedLists**

Basically just alternatives to having to use an array to store a sequence of data.

![Linked List](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d4/CPT-LinkedLists-deletingnode.svg/380px-CPT-LinkedLists-deletingnode.svg.png)

From [Wikimedia](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d4/CPT-LinkedLists-deletingnode.svg/380px-CPT-LinkedLists-deletingnode.svg.png)

### **Stacks**

First-in-last-out type of structure that is used so that only one data item is available at any given time: the "top-most" item.

![Stack](https://upload.wikimedia.org/wikipedia/commons/b/b4/Lifo_stack.png)

From [Wikimedia](https://upload.wikimedia.org/wikipedia/commons/b/b4/Lifo_stack.png)

### **Queues**

First-in-first-out type of structure that is used so that only one data item is available at any given time: the item at the "front" of the queue.

![Queue](https://upload.wikimedia.org/wikipedia/commons/d/d3/Fifo_queue.png)

From [Wikimedia](https://upload.wikimedia.org/wikipedia/commons/d/d3/Fifo_queue.png)

### **Trees and Heaps**

A structure we can use to store *sorted data*, like a binary tree. Each Node of a tree can have 0, 1, or 2 "children". Usually a "left" child would be "less than", and a "right" child would be "greater than".

![Morse Code tree](https://upload.wikimedia.org/wikipedia/commons/thumb/1/19/Morse-code-tree.svg/2000px-Morse-code-tree.svg.png)

From [Wikimedia](https://upload.wikimedia.org/wikipedia/commons/thumb/1/19/Morse-code-tree.svg/2000px-Morse-code-tree.svg.png)

### **Dictionaries and Hash Tables**

A dictionary is like an array, but where the *key* can be something else besides a *position of an array* (0, 1, 2, 3, ...).

For example, the key could be a numeric ID (1011, 1012, 1013) or a string ("cat", "dog", "mouse"), or other data types.

![Dictionary](https://upload.wikimedia.org/wikipedia/commons/thumb/5/5a/Hash_table_5_0_1_1_1_1_0_LL.svg/2000px-Hash_table_5_0_1_1_1_1_0_LL.svg.png)

From [Wikipedia](https://upload.wikimedia.org/wikipedia/commons/thumb/5/5a/Hash_table_5_0_1_1_1_1_0_LL.svg/2000px-Hash_table_5_0_1_1_1_1_0_LL.svg.png)



## Efficiency

Another topic that we're concerned with when working with data structures is their **efficiency**. Different data types might be more efficient at inserting items, but slower at accessing them, or vice versa.

For analyzing efficiency of each function of a data structure, we use something called "Big-O Notation".

[This Big-O Cheat Sheet is really handy!](http://bigocheatsheet.com/)

