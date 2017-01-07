# Lab 1: STL containers

**Please read this in Chrome so that hints are collapsed by default!**

## Setup

Download the starter code from the GitHub repo:

* 01 STL Vector
* 02 STL List
* 03 STL Queue
* 04 STL Bookdrop
* 05 STL Map

## Turn in

Upload your code to your class repository on GitHub,
as well as turning in your code in the class Dropbox.

Make sure to include **all source files: .cpp, .hpp, .h, etc.**. (Project files / solution files are not required.)

---

# 1. STL Vector

In this one, you will use the [STL Vector](http://www.cplusplus.com/reference/vector/vector/) object.

## Starter code

    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std;

    void AddIngredients( vector<string>& ingredients )
    {
        // Use the push_back function to add "lettuce", "tomato", "mayo", "mustard", and "bread" to the vector.
    }

    void DisplayIngredients( const vector<string>& ingredients )
    {
        // Use a for-loop, going from 0 to the ingredient's size(), to display each of the ingredients
    }

    int main()
    {    
        // 1. Declare a vector of strings named ingredients.
        
        // 2. Call the AddIngredients function, passing in ingredients as an argument.
        
        // 3. Call the DisplayIngredients function, passing in ingredients as an argument.
        
        return 0;
    }

## Instructions

### main()

In **main**, create a vector of strings called **ingredients**.

Afterward, call the **AddIngredients** function, passing in ingredients as an argument.

Finally, call the **DisplayIngredients** function, passing in ingredients as an argument.

### AddIngredients

Within this function, use the vector's **push_back** function to add
a series of strings to your ingredients vector, such as *lettuce, tomato, mayo, mustard, and bread*.

### DisplayIngredients

Within this function, use a *for-loop* to iterate through all the elements of
the ingredients vector. You can use the vector's **size** function to get
the amount of items in the vector, and iterate from 0 to that item count.

Use **cout** to display the current ingredient. You can access an item
at index *i* in the vector with a subscript, just like with an array.

### Solution

<details>
	<summary><strong><em>
		Solution
	</em></strong></summary>
	
    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std;

    void AddIngredients( vector<string>& ingredients )
    {
        // Use the push_back function to add "lettuce", "tomato", "mayo", "mustard", and "bread" to the vector.
        ingredients.push_back( "lettuce" );
        ingredients.push_back( "tomato" );
        ingredients.push_back( "mayo" );
        ingredients.push_back( "mustard" );
        ingredients.push_back( "bread" );
    }

    void DisplayIngredients( const vector<string>& ingredients )
    {
        // Use a for-loop, going from 0 to the ingredient's size(), to display each of the ingredients
        for ( unsigned int i = 0; i < ingredients.size(); i++ )
        {
            cout << ingredients[i] << endl;
        }
    }

    int main()
    {    
        // 1. Declare a vector of strings named ingredients.
        vector<string> ingredients;
        
        // 2. Call the AddIngredients function, passing in ingredients as an argument.
        AddIngredients( ingredients );
        
        // 3. Call the DisplayIngredients function, passing in ingredients as an argument.
        DisplayIngredients( ingredients );
        
        return 0;
    }
</details>
