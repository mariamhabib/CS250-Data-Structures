# Searching and Sorting lab

## Turn-in

Upload your .cpp, .hpp, and/or .h files

## Group Work Policy

* Group work and/or collaboration is allowed for this assignment
* You are allowed to research on the internet
* You are allowed to ask the instructor for help

---

## Starting Off
 
Make sure to download the **countrylist_jumbled.txt** and **countrylist.txt** files. We will use
this to search and sort the data.

---

# Searching Algorithms

For these algorithms, you will be using the already-sorted **countrylist.txt** file.

In each of these algorithms, implement a counter as well, so that when
the item is found, it will also output how many "cycles" were executed,
so that you can compare the efficiency of each searching algorithm for this case.

Each search should have its own function.

Load the list of countries into a **vector<string>** object to work with.

You will do a search for the following items, using each of the algorithms:

* Austria
* Yemen
* Curacao
* CS250Land

## Algorithm 1: Linear Search

Implement a simple linear search algorithm, along with the counter
to let you know how many iterations it took.

## Algorithm 2: Custom Search

Implement your own search algorithm to search the list intelligently.
You can do this however you wish, but make it more intelligent than
just a linear search.

## Algorithm 3: Binary Search

Implement the [Binary Search](https://en.wikipedia.org/wiki/Binary_search_algorithm#Algorithm)
algorithm. (You might also look for other sources online if the pseudocode doesn't help)

---

# Sorting Algorithms

For these algorithms, you will be using the jumbled **countrylist_jumbled.txt** file.

For each of these algorithms, implement a counter as well,
so that you can tell how many "cycles" it took to sort the list.

Each sort will have its own function.

Load the list of countries into a **vector<string>** object to work with,
and then pass a copy of this object to each function to sort.

## Algorithm 1: Insertion Sort

Implement the [Insertion Sort](https://en.wikipedia.org/wiki/Insertion_sort#Algorithm_for_insertion_sort)
algorithm, including the counter to know how many cycles it took to sort the list.

## Algorithm 2: Selection Sort

Implement the [Selection Sort](https://en.wikipedia.org/wiki/Selection_sort#Implementation) algorithm.

## Algorithm 3: Bubble Sort

Implement the [Bubble Sort](https://en.wikipedia.org/wiki/Bubble_sort#Implementation) algorithm.

## Algorithm 4: Quicksort

Implement the [Quicksort](https://en.wikipedia.org/wiki/Quicksort#Algorithm) algorithm.
Note that it is recursive, so you'll need to add an extra parameter to keep the counter going.


