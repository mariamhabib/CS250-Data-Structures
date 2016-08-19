# CS 250 - Assignment 0
## Classes & Inheritance Review

---

# Introduction

This assignment deals with some simple classes and inheritance to
help you warm up after the break.

You will declare a base class, **shape**, which will contain common
functions that all *types* of shapes share.

Then, using inheritance, you will create subclasses of **shape**, such
as **rectangle**, **triangle**, and **circle**.

## Turn-in

Upload your **.cpp**, **.hpp** (or **.h**) files.

Project files are not needed.

## Group Work Policy

### Collaborating with classmates

* You can **collaborate** with other classmates by brainstorming
and discussing the problem **verbally**.
* Copying another student's assignment is **not allowed**.
* Sharing your code with another student for review is **not allowed**.
* If you need to illustrate a point for a classmate, **draw a picture**.
Do not allow them to copy your code.

---

# Review

## Shape Information

### Rectangle

Perimeter: 2 * Width + 2 * Length

Area: Width * Length

### Right-Triangle

Perimeter: SideA + SideB + SideC

Area: 0.5 * Base * Height

### Circle

Perimeter (Circumference): 2 * pi * r

Area: pi * r^2

## Classes and Inheritance

### Declaration vs. Definition

A function **declaration** is just the signature of the function,
with a semi-colon at the end:

    int GetSum( int a, int b, int c );
    
A function **definition** is when the function is "fleshed-out".
It has an internal code block, between { and }.

    int GetSum( int a, int b, int c )
    {
        return a + b + c;
    }
    
### Instantiation

When the term **[class] instantiation** is used, it essentially means
the act of declaring a variable whose data-type is that **[class]**.

### Public Inheritance

When inheriting from a base class, it will be in the form:

    class ChildClass : public ParentClass
    
Make sure that the inheritance is **public**.

### Abstract Class

An **Abstract Class** is a class that cannot be instantiated.
*(i.e., you cannot create a variable whose type is this class)*.

To create an abstract class, the class must contain at least one
**Pure Virtual Function**.

### Pure Virtual Function

A **Pure Virtual Function** is declared like this:

    virtual void MyFunction() = 0;

When the function is declared with this "=0" at the end,
the class will not require this function to be **defined**.

In any **child classes** of the abstract base class, in order to
be able to **instantiate** the class, the function will need to be
**defined**.

## Review Resources

If you're unclear on some topic(s), you can use these resources to refresh your memory:

### Lecture Videos (CS200)

* [Inheritance](http://edu.moosader.com/_CPP_LECTURES/15%20Inheritance%20Lecture.mp4) (19 minutes)
* [Abstract Classes, Virtual Functions, & Polymorphism](http://edu.moosader.com/_CPP_LECTURES/22%20Polymorphism%20Lecture.mp4) (19 minutes) 
* Class basics: 
  * [1: Structs](http://edu.moosader.com/_CPP_LECTURES/10%20Struct%20Lecture.mp4) (40 minutes)
  * [2: Classes Pt 1](http://edu.moosader.com/_CPP_LECTURES/11%20Class%20Lecture%201.mp4) (25 minutes)
  * [3: Classes Pt 2](http://edu.moosader.com/_CPP_LECTURES/12%20Class%20Lecture%202.mp4) (18 minutes)
  * [4: Class Design](http://edu.moosader.com/_CPP_LECTURES/13%20Class%20Design.mp4) (8 minutes)

### Written Resources

* [Inheritance](http://www.learncpp.com/cpp-tutorial/112-basic-inheritance-in-c/) from learncpp.com
* [Abstract Classes, Virtual Functions, Interface Classes](http://www.learncpp.com/cpp-tutorial/126-pure-virtual-functions-abstract-base-classes-and-interface-classes/) from learncpp.com
* [Classes](http://www.learncpp.com/cpp-tutorial/82-classes-and-class-members/) from learncpp.com


---

# Classes

Define these classes either all in **shape.cpp** and **shape.hpp**, or
create separate code files for each class.

## Shape - Abstract Base Class
For the base class, we're not going to create a "Shape" variable itself; 
this will just be a class to define the functionality that
all shapes we're going to make share - such as area and perimeter.

### Member Variables

* None - Each shape has its own variables

### Public Member Functions

* GetPerimeter
  * Returns a float or double - do not define in Shape class
  * No parameters
* GetArea
  * Returns a float or double - do not define in Shape class
  * No parameters

## Rectangle Class

### Member Variables

These should be declared as **private**!

* width - float or double
* length - float or double

### Member Functions

* Setup
  * No returns (void return type)
  * Takes in a width and length as parameters
  * Stores the #s passed in, into the member variables **width** and **length**
* GetArea (Overwritten from Shape)
  * Calculate area and return it
* GetPerimeter (Overwritten from Shape)
  * Calculate perimeter and return it

## Circle Class

### Member Variables

These should be declared as **private**!

* radius - float or double

### Member Functions

* Setup
  * No returns (void return type)
  * Takes in a radius
  * Stores the # passed in, into the member variables **radius**
* GetArea (Overwritten from Shape)
  * Calculate area and return it
* GetPerimeter (Overwritten from Shape)
  * Calculate perimeter and return it

## RightTriangle Class

### Member Variables

These should be declared as **private**!

* base - float or double
* height - float or double
* hypoteneuse - float or double

### Member Functions

* Setup
  * No returns (void return type)
  * Takes in a base, height, and hypoteneuse as parameters
  * Stores the #s passed in, into the member variables **base**, **height**, and **hypoteneuse**
* GetArea (Overwritten from Shape)
  * Calculate area and return it
* GetPerimeter (Overwritten from Shape)
  * Calculate perimeter and return it
  
---

## Main Program

Within the main() function, it should do the following:

1. Create a variable whose type is **Rectangle**
    1. Ask user to enter the **width** and **length** for a rectangle. 
    Store these in *temporary variables*, 
    then use the **Setup** function to pass these variables in
    as arguments.
    
    2. Display the text "Area:", then use the **GetArea** function
    to get the Rectangle's area.
    
    3. Display the text "Perimeter:", then use the **GetPerimeter**
    function to get the Rectangle's perimeter.
    
2. Create a variable whose type is **Circle**
    1. Ask user to enter the **radius** for a circle. 
    Store this in a *temporary variable*, 
    then use the **Setup** function to pass this variable in
    as an argument.
    
    2. Display the text "Area:", then use the **GetArea** function
    to get the Circle's area.
    
    3. Display the text "Circumference:", then use the **GetPerimeter**
    function to get the Circle's perimeter.
    
3. Create a variable whose type is **Triangle**
    1. Ask user to enter the **base**, **height**, and **hypoteneuse** for a triangle. 
    Store these in *temporary variables*, 
    then use the **Setup** function to pass these variables in
    as arguments.
    
    2. Display the text "Area:", then use the **GetArea** function
    to get the Trinagle's area.
    
    3. Display the text "Perimeter:", then use the **GetPerimeter**
    function to get the Trinagle's perimeter.

---

# Sample Output


    Enter a width and length for a rectangle: 3 4
    Area: 12
    Perimeter: 14

    Enter a base, height, and hypoteneuse for a triangle: 3 4 5
    Area: 6
    Perimeter: 12

    Enter a radius for a circle: 5
    Area: 78.5
    Perimeter: 31.4
