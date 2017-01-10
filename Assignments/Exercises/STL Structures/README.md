# Homework Exercise: STL Structures

![preview screenshot](images/previewimage.png)

## Downloads

Before you get started, make sure to download a .zip file of the Visual Studio or Code::Blocks project (based on what you're using at home or at school).

* [Visual Studio project](https://github.com/Rachels-Courses/CS250-Data-Structures/blob/master/Assignments/Exercises/STL%20Structures/Starter%20Files/Visual%20Studio%20Project.zip?raw=true)
* [Code::Blocks project](https://github.com/Rachels-Courses/CS250-Data-Structures/blob/master/Assignments/Exercises/STL%20Structures/Starter%20Files/CodeBlocks%20Project.zip?raw=true)

## Rules

* Team size: 1 person
    * You can brainstorm with others - that is, you can verbally discuss the problem.
    * You cannot copy another person's work. Code will be checked against other submissions with a diff tool. If a copy is found, both people will receive a 0 on the assignment.
* Open book / open note - do research as-needed.

## Overview

The starter files contains a simple application that is a book reader. It loads in text from a .txt file, and stores the pages of a book in a static array. Because of this, there is a maximum amount of pages, and not all books can be fully read!

For this project, you will replace the usage of a static array with a STL vector, so that there can be a virtually infinite amount of pages.

## Reference

You might find the [CPlusPlus.com's Vector Reference](http://www.cplusplus.com/reference/vector/vector/)
to be useful for this assignment!

## Turn In

Once you're done, zip up your project file and upload it to the assignment Dropbox.

Also upload your source files (any .cpp, .hpp, .h files) to your GitHub class repository.

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
2. Set the **Page**'s .text variable to the **pageText**.
3. Call the [**push_back**](http://www.cplusplus.com/reference/vector/vector/push_back/) function from your **pages** vector, and pass in your temporary Page object as the argument to insert it into the vector.

#### Remove the page limit

The LoadPages function automatically stops reading pages once the static array is full:

	if (pageCount == 100)
	{
		// The book is full! Can't load any more.
		return;
	}

This will no longer be needed!

### ReadBook function

#### Parameters

Update the Page array parameter here, too, to be a vector instead.

#### Total pages

Right now, the total pages is hard coded to 100:

	void ReadBook(Page pages[100])
	{
		int currentPage = 0;
		int totalPages = 100;

Update this! The new totalPages will be the size of our vector. Use the
[**size()**](http://www.cplusplus.com/reference/vector/vector/size/) function to get the vector's size.

---

## Grading Rubric

<table border="0" cellspacing="0" cellpadding="0" class="ta1"><colgroup><col width="12"/><col width="268"/><col width="256"/><col width="163"/><col width="162"/></colgroup><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td colspan="4" style="text-align:left;width:173.91pt; " class="ce1"><p>Grading Rubric</p></td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="ce2"><p>Name:</p></td><td colspan="3" style="text-align:left;width:165.94pt; " class="ce7"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="ce2"><p>Assignment:</p></td><td colspan="3" style="text-align:left;width:165.94pt; " class="ce7"><p>Homework Exercise: STL Structures</p></td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td colspan="4" style="text-align:left;width:173.91pt; " class="ce1"><p>Breakdown</p></td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="ce3"><p>Item</p></td><td style="text-align:left;width:165.94pt; " class="ce3"><p>Description</p></td><td style="text-align:left;width:105.76pt; " class="ce3"><p>Total %</p></td><td style="text-align:left;width:104.94pt; " class="ce3"><p>Your Score</p></td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="ce4"><p>Builds and runs</p></td><td style="text-align:left;width:165.94pt; " class="ce8"> </td><td style="text-align:right; width:105.76pt; " class="ce11"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce11"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="ce5"><p>Clean code</p></td><td style="text-align:left;width:165.94pt; " class="ce9"> </td><td style="text-align:right; width:105.76pt; " class="ce12"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce12"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="ce4"><p>No logic errors</p></td><td style="text-align:left;width:165.94pt; " class="ce8"> </td><td style="text-align:right; width:105.76pt; " class="ce11"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce11"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="ce5"><p>No runtime errors</p></td><td style="text-align:left;width:165.94pt; " class="ce9"> </td><td style="text-align:right; width:105.76pt; " class="ce12"><p>5.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce12"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="ce4"><p>updates to main()</p></td><td style="text-align:left;width:165.94pt; " class="ce8"> </td><td style="text-align:right; width:105.76pt; " class="ce11"><p>15.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce11"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="ce5"><p>updates to LoadPages()</p></td><td style="text-align:left;width:165.94pt; " class="ce9"> </td><td style="text-align:right; width:105.76pt; " class="ce12"><p>50.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce12"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="ce4"><p>updates to ReadBook()</p></td><td style="text-align:left;width:165.94pt; " class="ce8"> </td><td style="text-align:right; width:105.76pt; " class="ce11"><p>15.00%</p></td><td style="text-align:left;width:104.94pt; " class="ce11"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="ce5"> </td><td style="text-align:left;width:165.94pt; " class="ce9"> </td><td style="text-align:left;width:105.76pt; " class="ce12"> </td><td style="text-align:left;width:104.94pt; " class="ce12"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="ce6"> </td><td style="text-align:left;width:165.94pt; " class="ce6"> </td><td style="text-align:left;width:105.76pt; " class="ce13"> </td><td style="text-align:left;width:104.94pt; " class="ce13"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="ce2"><p>Totals</p></td><td style="text-align:left;width:165.94pt; " class="ce2"> </td><td style="text-align:left;width:105.76pt; " class="ce13"> </td><td style="text-align:left;width:104.94pt; " class="ce13"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="ce6"> </td><td style="text-align:left;width:165.94pt; " class="ce6"> </td><td style="text-align:right; width:105.76pt; " class="ce13"><p>100.00%</p></td><td style="text-align:right; width:104.94pt; " class="ce14"><p>0.00%</p></td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="ce6"> </td><td style="text-align:left;width:165.94pt; " class="ce6"> </td><td style="text-align:left;width:105.76pt; " class="ce6"> </td><td style="text-align:left;width:104.94pt; " class="ce6"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro2"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td style="text-align:left;width:173.91pt; " class="Default"> </td><td style="text-align:left;width:165.94pt; " class="Default"> </td><td style="text-align:left;width:105.76pt; " class="Default"> </td><td style="text-align:left;width:104.94pt; " class="Default"> </td></tr><tr class="ro1"><td style="text-align:left;width:7.71pt; " class="Default"> </td><td colspan="4" style="text-align:left;width:173.91pt; " class="ce1"><p>Notes</p></td></tr></table>
