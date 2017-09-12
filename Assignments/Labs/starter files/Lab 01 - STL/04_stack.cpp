#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    // Create a stack of strings, called sentence.
    
    bool done = false;

    cout << "Enter the next word of the sentence, or UNDO to undo, or DONE to stop." << endl;
    
    while ( !done )
    {
        string word;
        cout << ">> ";
        cin >> word;

        if ( word == "UNDO" )
        {
            // Pop the top-most item out of the sentence stack.
        }
        else if ( word == "DONE" )
        {
            done = true;
        }
        else
        {
            // Push a new item onto the sentence stack.
        }
    }

    cout << endl << endl << "Finished sentence: ";

    // Use a while loop to continue looping while the sentence stack is not empty.
    // Inside the loop...
    //      Display the top-most item
    //      Pop the top item off the stack.
    
    
    return 0;
}
