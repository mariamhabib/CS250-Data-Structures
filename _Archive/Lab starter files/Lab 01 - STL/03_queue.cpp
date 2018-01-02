#include <iostream> // required for cout
#include <string>   // required for strings
#include <queue>    // required for queues
using namespace std;

int main()
{
    float balance = 0.0;

    // Create a queue of floats called transactions

    cout.precision( 2 );
    cout.setf( ios::fixed );

    // Push some dollar amounts (positive and negative) into the transactions queue.

    // Create a loop that will continue while the transactions queue is NOT empty.
    // Within the loop...
    //      Display the value at the front of the queue.
    //      Add the value at the front of the queue onto the 'balance' variable.
    //      Pop the item at the front of the queue.
    

    // After the while loop:
    cout << endl << "Final balance: $" << balance << endl;
    
    return 0;
}
