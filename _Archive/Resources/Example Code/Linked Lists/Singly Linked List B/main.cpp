#include "singlyLinkedList.hpp"

#include <iostream>
#include <string>
using namespace std;

int main()
{
    SinglyLinkedList<int> listo;

    listo.Push( 1 );
    listo.Push( 2 );
    listo.Push( 3 );
    listo.Push( 4 );
    listo.Push( 5 );

    int* find = listo.Get( 2 );

    cout << *find << endl;
    
    return 0;
}
