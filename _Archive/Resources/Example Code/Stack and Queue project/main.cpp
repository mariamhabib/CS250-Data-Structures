#include <iostream>
using namespace std;

#include "DoublyLinkedList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

#include "Utilities/Menu.hpp"

void DoublyLinkedListTest()
{
    dal::Menu::Header( "DoublyLinkedList" );
    DoublyLinkedList<int> intList;

    intList.PushBack( 1 );
    intList.PushBack( 2 );
    intList.PushBack( 3 );
    intList.PushBack( 4 );
    intList.PushBack( 5 );
    intList.Display();

    dal::Menu::Pause();
}

void StackTest()
{
    dal::Menu::Header( "Stack" );

    Stack<int> intList;

    intList.Push( 1 );
    intList.Push( 2 );
    intList.Push( 3 );
    intList.Push( 4 );
    intList.Push( 5 );
    intList.Display();

    cout << endl << "Remove values:" << endl;
    while ( intList.GetSize() != 0 )
    {
        cout << "Pop " << intList.Top() << "..." << endl;
        intList.Pop();
    }

    cout << endl << "Done" << endl;

    dal::Menu::Pause();
}

void QueueTest()
{
    dal::Menu::Header( "Queue" );

    Queue<int> intList;

    intList.Enqueue( 1 );
    intList.Enqueue( 2 );
    intList.Enqueue( 3 );
    intList.Enqueue( 4 );
    intList.Enqueue( 5 );
    intList.Display();

    cout << endl << "Remove values:" << endl;
    while ( intList.GetSize() != 0 )
    {
        cout << "Dequeue " << intList.Front() << "..." << endl;
        intList.Dequeue();
    }

    cout << endl << "Done" << endl;

    dal::Menu::Pause();
}

int main()
{
    dal::Logger::Setup();

    StackTest();
    QueueTest();

    dal::Logger::Cleanup();

    return 0;
}
