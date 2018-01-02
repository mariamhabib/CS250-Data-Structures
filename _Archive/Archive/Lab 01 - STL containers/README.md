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

---

# 2. STL List

In this one, you will use the [STL List](http://www.cplusplus.com/reference/list/list/) object.

## Starter code

    #include <iostream>
    #include <string>
    #include <list>
    using namespace std;

    class Student
    {
        public:
        Student( const string& name, int grade ) : m_name( name ), m_grade( grade ) { }
        void Display();
        
        bool operator>( const Student& other );
        bool operator<( const Student& other );
        bool operator>=( const Student& other );
        bool operator<=( const Student& other );
        bool operator==( const Student& other );
        
        private:
        string m_name;
        int m_grade;
    };


    int main()
    {
        // Create a list of Student objects called students
        list<Student> students;
        
        // Push multiple students into the list.
        // students.push_back( Student( "Vid",         100 ) );
        
        // Call the sort() function
        // Call the reverse() function to make it descending.
        
        // Display all the students
        for ( list<Student>::iterator it = students.begin(); it != students.end(); it++ )
        {
            it->Display();
        }
        
        return 0;
    }

    void Student::Display()
    {
        cout << m_grade << "\t" << m_name << endl;
    }


    bool Student::operator>( const Student& other )
    {
        return this->m_grade > other.m_grade;
    }

    bool Student::operator<( const Student& other )
    {
        return this->m_grade < other.m_grade;
    }

    bool Student::operator>=( const Student& other )
    {
        return this->m_grade >= other.m_grade;
    }

    bool Student::operator<=( const Student& other )
    {
        return this->m_grade <= other.m_grade;
    }

    bool Student::operator==( const Student& other )
    {
        return this->m_grade == other.m_grade;
    }


## Instructions

### main()

In **main**, create a list of Student objects, called **students**.

Use the list's **push_back** function to add a series of students to the list.

Hint: You can insert a new student without creating a Student variable local to main()
by passing in a constructor with its arguments, like this:

    blahblahblah( Student( "Vid", 100 ) );

Add several students and grades in random order.

Afterward, call the **sort** and **reverse** functions on the list.

Sort will sort it, ascending, and reverse will change it to descending order.

A for loop with an iterator is already provided - it might look strange!
If you haven't seen an iterator before, that's OK. But with lists, we can't iterate
through it like a vector; we can't randomly access items with the subscript operator [ ]
so we have to use the iterator.

### Solution

<details>
	<summary><strong><em>
		Solution
	</em></strong></summary>
	
    #include <iostream>
    #include <string>
    #include <list>
    using namespace std;

    class Student
    {
        public:
        Student( const string& name, int grade ) : m_name( name ), m_grade( grade ) { }
        void Display();
        
        bool operator>( const Student& other );
        bool operator<( const Student& other );
        bool operator>=( const Student& other );
        bool operator<=( const Student& other );
        bool operator==( const Student& other );
        
        private:
        string m_name;
        int m_grade;
    };


    int main()
    {
        list<Student> students;
        
        students.push_back( Student( "Vid",         100 ) );
        students.push_back( Student( "Katarina",    50 ) );
        students.push_back( Student( "Christy",     80 ) );
        students.push_back( Student( "Hakan",       70 ) );
        students.push_back( Student( "Naoki",       90 ) );
        students.push_back( Student( "Thankarat",   75 ) );
        
        students.sort();
        students.reverse();
        
        for ( list<Student>::iterator it = students.begin(); it != students.end(); it++ )
        {
            it->Display();
        }
        
        return 0;
    }

    void Student::Display()
    {
            cout << m_grade << "\t" << m_name << endl;
    }


    bool Student::operator>( const Student& other )
    {
        return this->m_grade > other.m_grade;
    }

    bool Student::operator<( const Student& other )
    {
        return this->m_grade < other.m_grade;
    }

    bool Student::operator>=( const Student& other )
    {
        return this->m_grade >= other.m_grade;
    }

    bool Student::operator<=( const Student& other )
    {
        return this->m_grade <= other.m_grade;
    }

    bool Student::operator==( const Student& other )
    {
        return this->m_grade == other.m_grade;
    }

</details>

---

# 3. STL Queue

In this one, you will use the [STL Queue](http://www.cplusplus.com/reference/queue/queue/) object.

## Starter code

    #include <iostream>
    #include <string>
    #include <queue>
    using namespace std;

    int main()
    {
        float balance = 0.0;
        // Create a queue of floats, named transactions
        
        // Push some + and - floats into the transactions queue.
        
        // Loop through all the transactions - while the queue is empty.
        // Within the loop, whatever amount is at the front of the queue,
        // add it to the balance and then pop it off the queue.

        cout << "Final balance: $" << balance << endl;
        
        return 0;
    }

## Instructions

### main()

In **main**, create a queue of floats called **transactions**.

Push a series of values into the queue: both positive and negative values.
These will be deposits and withdraws into an account.

Create a while loop that will *continue looping while the transactions queue is not empty.*
Use the queue's **empty** function to see if the queue is empty or not.

Within the while loop, you will take the front item of the queue (with the **front** function)
and add it to the balance. Afterward, you will **pop** the front value off the queue.

At the end, it will display the final balance after all the deposits and withdraws.


### Solution

<details>
	<summary><strong><em>
		Solution
	</em></strong></summary>
	
    #include <iostream>
    #include <string>
    #include <queue>
    using namespace std;

    int main()
    {
        float balance = 0.0;
        queue<float> transactions;
        
        transactions.push( 100.00 );
        transactions.push( -5.00 );
        transactions.push( 50.00 );
        transactions.push( -20.00 );
        
        while ( !transactions.empty() )
        {
            float amount = transactions.front();
            cout << amount << " pushed to account" << endl;
            balance += amount;
            transactions.pop();
        }
        cout << "Final balance: $" << balance << endl;
        
        return 0;
    }
</details>

---

# 4. STL Stack

In this one, you will use the [STL Stack](http://www.cplusplus.com/reference/stack/stack/) object.

## Starter code

    #include <iostream>
    #include <string>
    #include <stack>
    #include <vector>
    using namespace std;

    class Book
    {
        public:
        Book( const string& title ) 
        { 
            m_title = title;
            m_checkedIn = false; 
        }
        
        void CheckIn()
        {
            cout << "Checked in \"" << m_title << "\""<< endl;
            m_checkedIn = true;
        }
        
        private:
        string m_title;
        bool m_checkedIn;
    };

    int main()
    {
        // Create a stack of Book objects called bookDrop.
        stack<Book> bookDrop;
        
        // Push a series of books into the bookDrop.   
        
        vector<Book> bookPool;
        
        // Go through the stack of books using a while loop,
        // while the stack is not empty...
        // Take the top-most book, and push it into the bookPool.
        // Then pop the top book off the bookDrop.
        
        return 0;
    }

## Instructions

### main()

In **main**, create a stack of Book objects, called **bookDrop**.

Push a series of books into the bookDrop stack, similar to in our List project, using a Book constructor.

    Book( "The Wrong Side of Goodbye" )
    
A vector of Book objects has already been declared to store all the checked-in books.

Create a while loop that will keep looping until the bookDrop is empty. Use the stack's **empty** function
to see whether the stack is empty or not.

Within the while loop, get the top-most item with the **top** function, and call the **CheckIn()** function
(which is part of Book.)

Then, push the top item into the **bookPool** vector.

Finally, **pop** the book off the bookDrop stack.


### Solution

<details>
	<summary><strong><em>
		Solution
	</em></strong></summary>
	
    #include <iostream>
    #include <string>
    #include <stack>
    #include <vector>
    using namespace std;

    class Book
    {
        public:
        Book( const string& title ) 
        { 
            m_title = title;
            m_checkedIn = false; 
        }
        
        void CheckIn()
        {
            cout << "Checked in \"" << m_title << "\""<< endl;
            m_checkedIn = true;
        }
        
        private:
        string m_title;
        bool m_checkedIn;
    };

    int main()
    {
        stack<Book> bookDrop;
        bookDrop.push( Book( "The Wrong Side of Goodbye" ) );    
        bookDrop.push( Book( "No Man's Land" ) );    
        bookDrop.push( Book( "The Whistler" ) );    
        bookDrop.push( Book( "A Dog's Purpose" ) );    
        bookDrop.push( Book( "Crash and Burn" ) );    
        bookDrop.push( Book( "Two By Two" ) );    
        
        vector<Book> bookPool;
        
        while ( !bookDrop.empty() )
        {
            bookDrop.top().CheckIn();
            bookPool.push_back( bookDrop.top() );
            bookDrop.pop();
        }
        
        return 0;
    }
</details>

---

# 5. STL Map

In this one, you will use the [STL Vector](http://www.cplusplus.com/reference/vector/vector/) object.

## Starter code

    #include <iostream>
    #include <string>
    #include <map>
    using namespace std;

    int main()
    {
        // Create a map that uses two strings. Name it colors.

        
        // Populate several colors and their hex codes
        // red = FF0000, green = 00FF00, blue = 0000FF
        // magenta = FF00FF, yellow = FFFF00, cyan = 00FFFF

        
        string color;
        cout << "Enter a color: ";
        cin >> color;
        
        // Display the hex value of the color, using the user's input as a key.

        
        return 0;
    }

## Instructions

### main()

In **main**, create a map that uses two strings. Name it **colors**.

Set up several colors, using text like "red", "green", and "blue" as the *key*,
and hex codes like "FF0000", "00FF00", and "0000FF" as the *value*.

You can use the subscript operator [ ], along with the string key (like "red")
in order to access a specific item of the map.

The program asks the user to enter a color, and stores it in a string
variable called **color**. We can use this as a key.

Use a **cout** command to display the hex value that corresponds with the
key value that the user entered. You can use the subscript operator with the key.


### Solution

<details>
	<summary><strong><em>
		Solution
	</em></strong></summary>
	
    #include <iostream>
    #include <string>
    #include <map>
    using namespace std;

    int main()
    {
        // Create a map that uses two strings. Name it colors.
        map<string, string> colors;
        
        // Populate several colors and their hex codes
        // red = FF0000, green = 00FF00, blue = 0000FF
        // magenta = FF00FF, yellow = FFFF00, cyan = 00FFFF
        colors[ "red" ]        = "FF0000";
        colors[ "green" ]      = "00FF00";
        colors[ "blue" ]       = "0000FF";
        colors[ "magenta" ]    = "FF00FF";
        colors[ "yellow" ]     = "FFFF00";
        colors[ "cyan" ]       = "00FFFF";
        
        string color;
        cout << "Enter a color: ";
        cin >> color;
        
        // Display the hex value of the color, using the user's input as a key.
        cout << "Hex: " << colors[ color ] << endl;
        
        return 0;
    }
</details>
