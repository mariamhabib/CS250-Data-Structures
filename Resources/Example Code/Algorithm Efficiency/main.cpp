#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Timer.hpp"

#include "Algorithms/SinglyLinkedList.hpp"
#include "Algorithms/DoublyLinkedList.hpp"
#include "Algorithms/BinaryTree.hpp"
#include "Algorithms/StupidArray.hpp"
#include "Algorithms/Dictionary.hpp"

void InitArray( int arrayOfData[], int arraySize )
{
    cout << "Initializing..." << endl;
    for ( int i = 0; i < arraySize; i++ )
    {
	cout << "Adding item " << i << endl;
        arrayOfData[ i ] = rand() % arraySize;
	cout << "Value: " << arrayOfData[i] << endl;
    }
}

bool FindValue( const int arrayOfData[], int arraySize, int findMe )
{
    cout << "Searching..." << endl;
    for ( int i = 0; i < arraySize; i++ )
    {
        if ( arrayOfData[i] == findMe )
        {
            return true;
        }
    }
    return false;
}

int main()
{
  srand( time( NULL ) );

    int arraySize = 1000000;
    int arrayOfData[ 1000000 ];
    InitArray( arrayOfData, arraySize );

    int searchFor = rand() % arraySize;
    cout << "Found value " << searchFor << "? " << FindValue( arrayOfData, arraySize, searchFor ) << endl;

    return 0;
}
