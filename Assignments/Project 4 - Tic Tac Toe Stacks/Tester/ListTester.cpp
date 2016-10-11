#include "ListTester.hpp"

#include <cassert>

ListTester::ListTester()
{
    // Create list of function pointers
    tests.push_back( TestListItem( "TestPushFront", bind( &ListTester::TestPushFront, this ) ) );
    tests.push_back( TestListItem( "TestPushBack", bind( &ListTester::TestPushBack, this ) ) );
    tests.push_back( TestListItem( "TestPopFront", bind( &ListTester::TestPopFront, this ) ) );
    tests.push_back( TestListItem( "TestPopBack", bind( &ListTester::TestPopBack, this ) ) );
    tests.push_back( TestListItem( "TestGetFront", bind( &ListTester::TestGetFront, this ) ) );
    tests.push_back( TestListItem( "TestGetBack", bind( &ListTester::TestGetBack, this ) ) );
    tests.push_back( TestListItem( "TestItemCount", bind( &ListTester::TestItemCount, this ) ) );
    tests.push_back( TestListItem( "TestAllItems", bind( &ListTester::TestAllItems, this ) ) );
    totalTestCount = tests.size() - 1; // Don't count the "test all items" test.
}

void ListTester::Menu()
{
    while ( true )
    {
        cout << "_______________________________________" << endl;
        cout << "TEST MAIN" << endl;
        cout << "_______________________________________" << endl;
        for ( unsigned int i = 0; i < tests.size(); i++ )
        {
            cout << i << ". " << tests[i].name << endl;
        }

        cout << "Which test do you want to run? ";
        int index;
        cin >> index;

        // Call and get result
        int result = tests[index].callFunction();

        cout << "Test \"" << tests[index].name << "\" result: " << result << endl;
        cout << endl << endl;
    }
}

int ListTester::TestPushFront()
{
    cout << "TestPushFront()" << endl;

    DoublyLinkedList<int> myList;

    // Test 1
    if ( myList.GetSize() != 0 ) { return 0; }

    // Test 2
    myList.PushFront( 2 );
    if ( myList.GetFront() != 2 ) { return 0; }
    if ( myList.GetSize() != 1 ) { return 0; }

    // Test 3
    myList.PushFront( 4 );
    if ( myList.GetFront() != 4 ) { return 0; }
    if ( myList.GetSize() != 2 ) { return 0; }

    // Test 4
    myList.PushFront( 6 );
    if ( myList.GetFront() != 6 ) { return 0; }
    if ( myList.GetSize() != 3 ) { return 0; }

    return 1;
}

int ListTester::TestPushBack()
{
    cout << "TestPushBack()" << endl;

    DoublyLinkedList<int> myList;

    // Test 1
    if ( myList.GetSize() != 0 ) { return 0; }

    // Test 2
    myList.PushBack( 2 );
    if ( myList.GetBack() != 2 ) { return 0; }
    if ( myList.GetSize() != 1 ) { return 0; }

    // Test 3
    myList.PushBack( 4 );
    if ( myList.GetBack() != 4 ) { return 0; }
    if ( myList.GetSize() != 2 ) { return 0; }

    // Test 4
    myList.PushBack( 6 );
    if ( myList.GetBack() != 6 ) { return 0; }
    if ( myList.GetSize() != 3 ) { return 0; }

    return 1;
}

int ListTester::TestPopFront()
{
    cout << "TestPopFront()" << endl;

    DoublyLinkedList<int> myList;

    myList.PushBack( 1 );
    myList.PushBack( 2 );
    myList.PushBack( 3 );

    // Test 1
    if ( myList.GetSize() != 3 ) { return 0; }

    // Test 2
    myList.PopFront();
    if ( myList.GetFront() != 2 ) { return 0; }
    if ( myList.GetBack() != 3 ) { return 0; }

    // Test 3
    myList.PopFront();
    if ( myList.GetFront() != 3 ) { return 0; }
    if ( myList.GetBack() != 3 ) { return 0; }

    // Test 4
    myList.PopFront();
    if ( myList.GetSize() != 0 ) { return 0; }

    return 1;
}

int ListTester::TestPopBack()
{
    cout << "TestPopBack()" << endl;

    DoublyLinkedList<int> myList;

    myList.PushBack( 1 );
    myList.PushBack( 2 );
    myList.PushBack( 3 );

    // Test 1
    if ( myList.GetSize() != 3 ) { return 0; }

    // Test 2
    myList.PopBack();
    if ( myList.GetFront() != 1 ) { return 0; }
    if ( myList.GetBack() != 2 ) { return 0; }

    // Test 3
    myList.PopBack();
    if ( myList.GetFront() != 1 ) { return 0; }
    if ( myList.GetBack() != 1 ) { return 0; }

    // Test 4
    myList.PopBack();
    if ( myList.GetSize() != 0 ) { return 0; }

    return 1;
}

int ListTester::TestGetFront()
{
    cout << "TestGetFront()" << endl;

    DoublyLinkedList<int> myList;

    myList.PushBack( 1 );
    myList.PushBack( 2 );
    myList.PushBack( 3 );

    // Test 1
    if ( myList.GetFront() != 1 ) { return 0; }

    // Test 2
    myList.PopFront();
    if ( myList.GetFront() != 2 ) { return 0; }

    // Test 3
    myList.PopFront();
    if ( myList.GetFront() != 3 ) { return 0; }

    // Test 4
    myList.PopFront();
    if ( myList.GetSize() != 0 ) { return 0; }

    return 1;
}

int ListTester::TestGetBack()
{
    cout << "TestGetBack()" << endl;

    DoublyLinkedList<int> myList;

    myList.PushBack( 1 );
    myList.PushBack( 2 );
    myList.PushBack( 3 );


    // Test 1
    if ( myList.GetBack() != 3 ) { return 0; }

    // Test 2
    myList.PopBack();
    if ( myList.GetBack() != 2 ) { return 0; }

    // Test 3
    myList.PopBack();
    if ( myList.GetBack() != 1 ) { return 0; }

    // Test 4
    myList.PopBack();
    if ( myList.GetSize() != 0 ) {return 0; }

    return 1;
}

int ListTester::TestItemCount()
{
    cout << "TestItemCount()" << endl;

    DoublyLinkedList<int> myList;

    // Test 1
    if ( myList.GetSize() != 0 ) { return 0; }

    // Test 2
    myList.PushFront( 2 );
    if ( myList.GetSize() != 1 ) { return 0; }

    // Test 3
    myList.PushFront( 4 );
    if ( myList.GetSize() != 2 ) { return 0; }

    return 1;
}

int ListTester::TestAllItems()
{
    cout << endl << "_______________________________________" << endl;
    cout << "TEST ALL ITEMS" << endl;
    cout << "_______________________________________" << endl;
    int resultTotal = 0;
    for ( unsigned int i = 0; i < totalTestCount; i++ )
    {
        int result = tests[i].callFunction();
        resultTotal += result;

        cout << "\t* Test \"" << tests[i].name << "\" result: " << result << endl;
    }

    cout << endl << "FINAL RESULT: " << resultTotal << " out of " << totalTestCount << endl;
    return resultTotal;
}

