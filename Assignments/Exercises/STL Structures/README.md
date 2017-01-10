# Homework Exercise: STL Structures

![preview screenshot](images/previewimage.png)

## Downloads

Before you get started, make sure to download a .zip file of the Visual Studio or Code::Blocks project (based on what you're using at home or at school).

* [Visual Studio project](https://github.com/Rachels-Courses/CS250-Data-Structures/blob/master/Assignments/Exercises/STL%20Structures/Starter%20Files/Visual%20Studio%20Project.zip?raw=true)
* [Code::Blocks project]()

## Rules

* Team size: 1 person
    * You can brainstorm with others - that is, you can verbally discuss the problem.
    * You cannot copy another person's work. Code will be checked against other submissions with a diff tool. If a copy is found, both people will receive a 0 on the assignment.
* Open book / open note - do research as-needed.

## Overview

The starter files contains a simple application that is a book reader. It loads in text from a .txt file, and stores the pages of a book in a static array. Because of this, there is a maximum amount of pages, and not all books can be fully read!

For this project, you will replace the usage of a static array with a STL vector, so that there can be a virtually infinite amount of pages.

---

## To Do...

The program is already mostly done, you just need to update the things specific to the static array.

### Includes

Make sure to include the vector library

### main() function

Instead of declaring an array of pages, you will change this to a **vector< Page >**.

### LoadPages function

#### Parameters

First, you will have to update the Page array that is a parameter of this function!

Original:

	void LoadPages(Page pages[100], const string& filename)

Replace **Page pages[100]** with a vector of Pages, and make sure it is passed by reference! (As a note, that string is being passed by reference.)

#### Adding pages to the vector

This code will need to be updated:

		if (lineCount == 27)
		{
			// Add page to book now
			pages[pageCount].text = pageText;
			pageCount++;

		

Instead of directly assigning a value to the array like

	pages[pageCount].text = pageText;

You will need to use the **push_back** function that is part of the vector! But... to do this, you will also need to create a new Page variable and set it up before pushing it into the vector. So, in summary:

1. Declare a new **Page** variable within this if statement.