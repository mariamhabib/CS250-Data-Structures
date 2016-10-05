# Brainstorming: Exceptions

*What could possibly go wrong?*

# Introduction

We've all received errors from software that we use that go something like this: "ERROR 39814", then you hit OK and it quits. What happened? How can you even fix it? The error code is really only meant for the programmer, so they can look it up in the code (and if it's not open source, you're S.O.L. in the regard.)

Number codes are an antiquity of programming, these days replaced in modern software development with *exceptions*. These days we can write in smarter error handling into our programs by specifying different types of exceptions ("logic error", "runtime error", "out of range", etc.) 

A function may even have multiple things that could go wrong within it, and it could throw different *types* of errors, to be caught by the programmer invoking the function.

The structures provided by the C++ libraries also utilize exceptions, which allow us to rely on them, and know *what* we can rely on.

When dealing with errors in our programs, we should make sure that no resources are **leaked**, and that data does not become **corrupted** - we want to use exceptions to get our program back on-track in a stable manner, or at least exit cleanly.

## Types of guarantees

In writing exception-safe functions, there are three different types of guarantees you can provide:

### The basic guarantee

If your function offers a "basic guarantee", that means that the program will remain in a *valid state*, even if an exception is thrown. This means, no corrupt data and the program is still functional.

### The strong guarantee

If your function offers a "strong guarantee", that means that if an exception is thrown, then the state of the program will be *unchanged*. If the function succeeds, it succeeds. If it fails, it is as if it were never called in the first place.

### The nothrow guarantee

If your function offers a "nothrow guarantee", that means the function will never thrown an exception. Additionally, this means that whatever the function is designed to do, it will do.

---

# Where use exceptions?

## Exceptions and Static Arrays

What could cause an error when working with static arrays? What kind of exception should be thrown?

<details>
	<summary><strong>
		Solutions
	</strong></summary>
	
* Trying to access elements of the array at invalid positions (negative index, or >= the size of the array) (**[out of range](http://www.cplusplus.com/reference/stdexcept/out_of_range/) exception**)

</details>	

---

## Exceptions and Dynamic Arrays

What could cause an error when working with dynamic arrays? What kind of exception should be thrown?

<details>
	<summary><strong>
		Solutions
	</strong></summary>
	
* Trying to access elements of the array at invalid positions (negative index, or >= the size of the array) (**[out of range](http://www.cplusplus.com/reference/stdexcept/out_of_range/) exception**)
* Inability to allocate memory when creating or resizing the array. (**[bad alloc](http://www.cplusplus.com/reference/new/bad_alloc/) exception**)

</details>	

---

## Exceptions and Linked Lists

What could cause an error when working with linked lists? What kind of exception should be thrown?

<details>
	<summary><strong>
		Solutions
	</strong></summary>
	
* Accessing nullptr (for node, next node) -- Nothing in C++ throws an exception for this, but you could check for it in your data structure and throw a custom exception.

</details>	

---

## Exceptions and File I/O

What could cause an error when trying to read a file? [ios_base::failure reference](http://en.cppreference.com/w/cpp/io/basic_ios/exceptions)

<details>
	<summary><strong>
		Solutions
	</strong></summary>
	
* File passed in during constructor / open() function does not exist or not found.

</details>	

---

## Other uses for exceptions

What other uses are there for exceptions?

<details>
	<summary><strong>
		Solutions
	</strong></summary>
	
* Division by zero
* Overflow - May occur if a computation results in a very large number; a number that is too big for the data type it belongs to.
* Underflow - May occur if a computation results in a very small number.
* System error - An error that is raised by the operating system.
* Invalid number, such as sqrt( -1 ).
* Bad cast - something fails when trying to cast a value to a different data type.

</details>

[View the family of exceptions at cplusplus.com reference](http://www.cplusplus.com/reference/exception/exception/)

---

## Exceptions and STL Structures

If you look at the reference documentation for the STL structures, they will list whether or not a given function will throw an error.

Examples:

### [list::insert](http://www.cplusplus.com/reference/list/list/insert/)

*Strong guarantee: if an exception is thrown, there are no changes in the container.
If allocator_traits::construct is not supported with the appropriate arguments for the element constructions, or if an invalid position or range is specified, it causes undefined behavior.*

### [list::erase](http://www.cplusplus.com/reference/list/list/erase/)

*If position (or the range) is valid, the function never throws exceptions (no-throw guarantee).
Otherwise, it causes undefined behavior.*

---

# More about exceptions

* [When and how to use exceptions, Herb Sutter (drdobbs.com)](http://www.drdobbs.com/when-and-how-to-use-exceptions/184401836)
* [exceptions (isocpp.org)](https://isocpp.org/wiki/faq/exceptions)
* [Appendix E: Standard-Library Exception Safety, Bjarne Stroustrup (stroustrup.com)](http://stroustrup.com/3rd_safe.pdf)