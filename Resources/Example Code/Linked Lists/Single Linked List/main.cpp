#include <iostream>
using namespace std;

#include "SingleLinkedList.hpp"

int main()
{
    SingleLinkedList<string> myList;

    cout << "--------------------------------" << endl;
    cout << "Insert letters A - G" << endl;
    myList.AddItem( "A" );
    myList.AddItem( "B" );
    myList.AddItem( "C" );
    myList.AddItem( "D" );
    myList.AddItem( "E" );
    myList.AddItem( "F" );
    myList.AddItem( "G" );
//    myList.Print();

    cout << "--------------------------------" << endl;
    cout << "Remove last item" << endl;
    myList.RemoveItem( "G" );
//    myList.Print();

    cout << "--------------------------------" << endl;
    cout << "Remove first item" << endl;
    myList.RemoveItem( "A" );
////    myList.Print();
//
//    cout << "--------------------------------" << endl;
//    cout << "Remove center item" << endl;
//    myList.RemoveItem( "D" );
////    myList.Print();
////
//    cout << "--------------------------------" << endl;
//    cout << "Remove item that isn't in the list" << endl;
//    myList.RemoveItem( "Z" );
//    myList.Print();

    return 0;
}
