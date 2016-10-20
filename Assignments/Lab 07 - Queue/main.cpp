#include <iostream>
#include <string>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <limits>
using namespace std;

#include "Timer.hpp"

void CountUp( int n );
int Fibonacci( int n );
void InitializeQueue( queue<int>& backlog );
void SplitOutWork( queue<int>& backlog, queue<int>& fastQueue, queue<int>& slowQueue );

int main()
{
    // Seed random # generator
    srand( time( NULL ) );

    // Initialize the backlog of work
    queue<int> backlog;
    InitializeQueue( backlog );

    // Separate work into "fast" and "slow" work.
    queue<int> fastQueue;
    queue<int> slowQueue;

    SplitOutWork( backlog, fastQueue, slowQueue );

    // Process fast queue first
    cout << endl << "Process fast queue" << endl;
    while ( fastQueue.size() != 0 )
    {
        CountUp( fastQueue.front() );
        fastQueue.pop();
    }

    cout << endl << "Process slow queue" << endl;
    // Process slow queue afterward
    while ( slowQueue.size() != 0 )
    {
        CountUp( slowQueue.front() );
        slowQueue.pop();
    }

    cout << endl << "Program finished" << endl;

    return 0;
}

void InitializeQueue( queue<int>& backlog )
{
    for ( int i = 0; i < 20; i++ )
    {
        backlog.push( rand() % numeric_limits<int>::max() );
    }
}

void SplitOutWork( queue<int>& backlog, queue<int>& fastQueue, queue<int>& slowQueue )
{
    // Split out the work: Go through each item in the backlog.
    // If the item is < 1000000000, put in the fast queue. Otherwise, put in the slow queue.


}

void CountUp( int n )
{
    cout << "Count from 0 to " << n*n << "... ";
    dal::Timer::Start();
    for ( int i = 0; i < n; i++ ) 
	{ 
		for (int i = 0; i < n; i++)
		{
		}
	}
    cout << "Finished in " << dal::Timer::GetElapsedTime().count() << " ticks" << endl;
}

int Fibonacci( int n )
{
    if ( n == 0 )
    {
        return 0;
    }

    if ( n == 1 )
    {
        return 1;
    }

    return Fibonacci( n-1 ) + Fibonacci( n-2 );
}
