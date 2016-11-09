# Dictionary Lab

## Introduction

You will use the pre-written Dictionary class for this project:

* Dictionary.hpp
* Dictionary.txt

This dictionary doesn't use templates - the key and the value are both expected to be strings.

## Turn-in

Upload your **.cpp**, **.hpp** (or **.h**) files.

## Group Work Policy

* Group work and/or collaboration is allowed for this assignment.
* You are allowed to research on the internet.
* You are allowed to ask the instructor for help.

---

# String Operations

You will need the reference documentation for the following:

* [substr](http://www.cplusplus.com/reference/string/string/substr/)
* [find](http://www.cplusplus.com/reference/algorithm/find/)
* [getline](http://www.cplusplus.com/reference/string/string/getline/)

---

# Instructions

For this program, we will be implementing a language lookup dictionary. The Dictionary.txt file contains text in the following format:

	ENGLISH = ESPERANTO

Keep in mind that the text on either side of the = sign may be more than one word, so you will need to do some text parsing. The English term becomes the Dictionary key, and the Esperanto word becomes the value.

Then, for the program, you will have a simple text prompt to have the user enter a word in English, and utilize the Dictionary to **Get** the entry relating to that key. 

You will also implement a **Find** feature in the existing Dictionary, so that it will be able to return a list of partial matches for what the user enters.

## Dictionary Program

You will at least need the following functions:

* LoadDictionary - Called at initialization, loads in and parses the Dictionary.txt file and sets up the Dictionary object.
* WordLookup - The main menu that keeps asking the user to enter a term and returning results.

You will also need to store a Dictionary item. An example name is **enToEo** (EnglishToEsperanto).

## Parsing the file

To parse the file, I suggest that you use three string variables - **english**, **esperanto**, and **line**.

You will use a while loop to read in a single line of the file at a time, using the [**getline**](http://www.cplusplus.com/reference/string/string/getline/) command on your **ifstream** object.

Use the [**find**](http://www.cplusplus.com/reference/algorithm/find/) function to find the position at where the = is. It will return an index, so store this in an integer.

Then, use this integer with the [**substr**](http://www.cplusplus.com/reference/string/string/substr/) function to pull out the values for the **english** and **esperanto** variables.

Once you've stored these two values, insert the entry into the **enToEo** dictionary.

## Searching the file

When the user is entering an English word to search for, the first thing you will try is to just get the value for that key and display it.

It is possible that the user only entered part of the word, however, so we should also search the Dictionary object - but this will be inefficient, since the dictionary could be unsorted, and a hash table!

Start off by creating a Find function in the Dictionary object:

* Return type: Some list type (could be vector<string> or array of strings. The former is easier).
* Parameter: the search key, a string.

For now, iterate through every element of the dictionary in order. Use **find** to see if the element's key at all matches the search key. If so, add it to your vector<string> object or whatever structure you're using.

Return the vector<string> once you're done. Back in the main program, display each value of the array/vector.

Sample output:

	Look up word: catch
	1 Results:
	* catch: kapti.

	Look up word: cat
	27 Results:
	* abdicate: demeti la re─¥econ.
	* advocate: defendi.
	* altercation: malpaco.
	* annual (publication): jarlibro.
	* application: atento.
	* authenticate: verigi.
	* bifurcation: disdui─¥o.
	* caricature: karikaturi.
	* cat: kato.
	* catacombs: subteraj galerioj.
	* catafalque: katafalko.
	* catalepsy: katalepsio.
	* catalogue: katalogo.
	* cataract (eyes): katarakto.
	* catarrh: kataro.
	* catch: kapti.
	* catechise: kate─Ñizi.
	* catechism: kate─Ñismo.
	* catechist: kate─Ñisto.
	* category: kategorio.
	* cater: provizi.
	* caterpillar: ra┼¡po.
	* cathedral: katedro.
	* catholic: katoliko.
	* catholicism: katolikismo. [error in book: katolicismo]
	* cattle: bestaro.
	* cattle-pen: bestejo.

## Smarter searching

The contents of the dictionary actually *is* sorted going in, since the text file itself was sorted. Dictionary structures are great for looking things up if you have the key, but a search is less efficient.

Can you come up with some algorithm - any algorithm - that is more efficient than beginning your search at the beginning of the array, going one-at-a-time, and searching through until either you find the item or the end of the array?
