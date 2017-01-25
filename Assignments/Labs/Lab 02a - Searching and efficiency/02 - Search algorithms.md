# Searching and efficiency lab (part 2)

![Searching](images/preview.png)

## Setup

Make sure to download **countrylist.txt** and **lab2.cpp**. There is some pre-written code,
and you will only need to implement the three search functions.

## Turn-in

Upload your code to your class repository on GitHub,
as well as turning in your code in the class Dropbox.

Make sure to include **all source files: .cpp, .hpp, .h, etc.**. (Project files / solution files are not required.)

## Group Work Policy

* Group work and/or collaboration is allowed for this assignment
* You are allowed to research on the internet
* You are allowed to ask the instructor for help

---

# Searching Algorithms

For these algorithms, you will be using the already-sorted **countrylist.txt** file.

Do not modify main() or the LoadData() functions.

### cycleCounter

In each of the search functions, there is a **cycleCounter** reference parameter.
Every time a cycle of a loop is executed within your search algorithm, you should
make sure to increment this counter by 1.

## Algorithm 1: Linear Search

Implement a simple linear search algorithm, along with the counter
to let you know how many iterations it took.

### Pseudocode

        From i = 0 to size-1, incrementing by 1 each time...:
                Add 1 to the *cycleCounter*.
                Is item at position *i* in the array equal to the *findMe* item?
                        Yes: return this index *i*.
        
        If loop finishes without returning, it means the item was not in the list.
        Return -1 instead.

## Algorithm 2: Custom Search

Implement your own search algorithm to search the list intelligently.
You can do this however you wish, but make it more intelligent than
just a linear search.

Tips:

* Maybe search beginning-to-end, or end-to-beginning, based on if the search item is closer (alphabetically) to the first item or the last item.
* Maybe check the first item and the last item each iteration, closing in towards the middle each cycle. (begin++, end--)
* What other techniques can you think of for searching a sorted list?

## Algorithm 3: Binary Search

Implement the [Binary Search](https://en.wikipedia.org/wiki/Binary_search_algorithm#Algorithm) algorithm.

### Pseudocode

        Create three integer variables: left, right, and mid.
        
        Initialize *left* to 0 and *right* to the size-1.
