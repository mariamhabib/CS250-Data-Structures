#include "Tester.hpp"

/*
This is the testers we are working on for project 1,
but there have been modifications for the following:

* Functions that used to return true on success and false on fail
    have been updated to use exceptions, so they have no return type.
    Therefore, these tests aren't needed and were removed.

* With a linked list there is no "max value" so tests for when the
    list was full was removed.
*/

void Tester::RunTests()
{
    Test_IsEmpty();
    Test_IsFull();
    Test_Size();
    Test_GetCountOf();
    Test_Contains();

    Test_PushFront();
    Test_PushBack();

    Test_Get();
    Test_GetFront();
    Test_GetBack();

    Test_PopFront();
    Test_PopBack();
    Test_Clear();

    Test_ShiftRight();
    Test_ShiftLeft();

    Test_Remove();
    Test_Insert();
}

void Tester::DrawLine()
{
    cout << endl;
    for ( int i = 0; i < 80; i++ )
    {
        cout << "-";
    }
    cout << endl;
}

void Tester::Test_Init()
{
    DrawLine();
    cout << "TEST: Test_Init" << endl;

    // Put tests here
}

void Tester::Test_ShiftRight()
{
    DrawLine();
    cout << "TEST: Test_ShiftRight" << endl;

    // Put tests here
}

void Tester::Test_ShiftLeft()
{
    DrawLine();
    cout << "TEST: Test_ShiftLeft" << endl;

    // Put tests here
}

void Tester::Test_Size()
{
    DrawLine();
    cout << "TEST: Test_Size" << endl;

    {   // Test begin
        cout << endl << "Test 1" << endl;
        List<int> testList;
        int expectedSize = 0;
        int actualSize = testList.Size();

        cout << "Expected size: " << expectedSize << endl;
        cout << "Actual size:   " << actualSize << endl;

        if ( actualSize == expectedSize )
        {
            cout << "Pass" << endl;
        }
        else
        {
            cout << "Fail" << endl;
        }
    }   // Test end

    {   // Test begin
        cout << endl << "Test 2" << endl;
        List<int> testList;

        testList.PushBack( 1 );

        int expectedSize = 1;
        int actualSize = testList.Size();

        cout << "Expected size: " << expectedSize << endl;
        cout << "Actual size:   " << actualSize << endl;

        if ( actualSize == expectedSize )
        {
            cout << "Pass" << endl;
        }
        else
        {
            cout << "Fail" << endl;
        }
    }   // Test end
}

void Tester::Test_IsEmpty()
{
    DrawLine();
    cout << "TEST: Test_IsEmpty" << endl;

    // Put tests here
    {
        // Test 1
        cout << endl << "Test 1" << endl;
        List<int> listA;
        bool expectedValue = true;
        bool actualValue = listA.IsEmpty();

        cout << "Created list, didn't add anything, should be empty..." << endl;
        cout << "Expected value: " << expectedValue << endl;
        cout << "Actual value:   " << actualValue << endl;

        if ( expectedValue == actualValue )
        {
            cout << "Test passed" << endl;
        }
        else
        {
            cout << "Test failed" << endl;
        }
    }

    {
        // Test 2
        cout << endl << "Test 1" << endl;
        List<int> listA;
        listA.PushBack( 5 );
        bool expectedValue = false;
        bool actualValue = listA.IsEmpty();

        cout << "Created list, added one thing, shouldn't be empty..." << endl;
        cout << "Expected value: " << expectedValue << endl;
        cout << "Actual value:   " << actualValue << endl;

        if ( expectedValue == actualValue )
        {
            cout << "Test passed" << endl;
        }
        else
        {
            cout << "Test failed" << endl;
        }
    }
}

void Tester::Test_IsFull()
{
    DrawLine();
    cout << "TEST: Test_IsFull" << endl;

    // Put tests here
}

void Tester::Test_PushFront()
{
    DrawLine();
    cout << "TEST: Test_PushFront" << endl;

    // Put tests here
}

void Tester::Test_PushBack()
{
    DrawLine();
    cout << "TEST: Test_PushBack" << endl;
    {
        cout << endl << "Test 1: Create a list, input 'A'." << endl;

        List<string> testlist;

        // Things to test

        bool expectedReturn = true;
        bool actualReturn = testlist.PushBack( "A" );

        int expectedSize = 1;
        int actualSize = testlist.Size();

        // Remember that Get functions return a pointer in this project.
        string expectedValueAt0 = "A";
        string* actualValueAt0 = testlist.Get(0);

        if ( actualValueAt0 == nullptr )
        {
            cout << "nullptr - exiting test" << endl;
            return;
        }

        // Display checks
        cout << "Return, expected: " << expectedReturn << ", actual: " << actualReturn << endl;
        cout << "Size, expected: " << expectedSize << ", actual: " << actualSize << endl;
        cout << "Value, expected: " << expectedValueAt0 << ", actual: " << *actualValueAt0 << endl;

        // Check each value
        if ( expectedReturn != actualReturn )
        {
            cout << "FAIL - Bad return" << endl;
        }
        else if ( expectedSize != actualSize )
        {
            cout << "FAIL - Bad size" << endl;
        }
        else if ( expectedValueAt0 != *actualValueAt0 )
        {
            cout << "FAIL - Bad value" << endl;
        }
        else
        {
            cout << "PASS" << endl;
        }
    }

    {
        cout << endl << "Test 2: Push Back 'A', 'B', 'C', make sure 0 = A, 1 = B, 2 = C" << endl;

        List<string> testlist;
        testlist.PushBack( "A" );
        testlist.PushBack( "B" );
        testlist.PushBack( "C" );

        string expectedValue_0 = "A";
        string expectedValue_1 = "B";
        string expectedValue_2 = "C";

        string* actualValue_0 = testlist.Get( 0 );
        string* actualValue_1 = testlist.Get( 1 );
        string* actualValue_2 = testlist.Get( 2 );

        if ( actualValue_0 == nullptr || actualValue_1 == nullptr || actualValue_2 == nullptr )
        {
            cout << "nullptrs returned; exiting to avoid segfault" << endl;
            return;
        }

        cout << "Expected value at 0: " << expectedValue_0 << endl;
        cout << "Expected value at 1: " << expectedValue_1 << endl;
        cout << "Expected value at 2: " << expectedValue_2 << endl;

        cout << "Actual value at 0: " << *actualValue_0 << endl;
        cout << "Actual value at 1: " << *actualValue_1 << endl;
        cout << "Actual value at 2: " << *actualValue_2 << endl;

        if ( expectedValue_0 != *actualValue_0 ||
             expectedValue_1 != *actualValue_1 ||
             expectedValue_2 != *actualValue_2 )
        {
            cout << "FAIL - Bad value(s)" << endl;
        }
        else
        {
            cout << "PASS" << endl;
        }
    }

    {
        cout << endl << "Test 3: Create a list, insert 101 items, Size() should return 100" << endl;

        List<string> testlist;
        for ( int i = 0; i < 100; i++ )
        {
            testlist.PushBack( "Z" );
        }

        bool expectedReturn = false;
        bool actualReturn = testlist.PushBack( "A" );

        int expectedValue = 100;
        int actualValue = testlist.Size();

        cout << "Return, expected: " << expectedReturn << ", actual: " << actualReturn << endl;
        cout << "Size, expected: " << expectedValue << ", actual: " << actualValue << endl;

        if ( expectedValue != actualValue )
        {
            cout << "FAIL - Bad size" << endl;
        }
        else if ( expectedReturn != actualReturn )
        {
            cout << "FAIL - Bad return" << endl;
        }
        else
        {
            cout << "PASS" << endl;
        }
    }
}

void Tester::Test_PopFront()
{
    DrawLine();
    cout << "TEST: Test_PopFront" << endl;

    // Put tests here
    {
        cout << endl << "Test 1: Create an empty list. Pop should return false." << endl;

        List<int> testlist;

        bool expectedReturn = false;
        bool actualReturn = testlist.PopFront();

        cout << "Return, expected: " << expectedReturn << ", actual: " << actualReturn << endl;

        if ( expectedReturn != actualReturn )
        {
            cout << "FAIL - Bad return" << endl;
        }
        else
        {
            cout << "PASS" << endl;
        }
    }

    {
        cout << endl << "Test 2: PushBack 'A', 'B', 'C', make sure PopFront removes correct item." << endl;

        List<string> testlist;

        testlist.PushBack( "A" );
        testlist.PushBack( "B" );
        testlist.PushBack( "C" );

        bool expectedReturn = true;
        bool actualReturn = testlist.PopFront();

        string expected0 = "B";
        string* actual0 = testlist.Get(0);

        if ( actual0 == nullptr )
        {
            cout << "nullptr" << endl;
            return;
        }

        cout << "Return, expected: " << expectedReturn << ", actual: " << actualReturn << endl;
        cout << "Item at 0, expected: " << expected0 << ", actual: " << *actual0 << endl;

        if ( expectedReturn != actualReturn )
        {
            cout << "FAIL - Bad return" << endl;
        }
        else if ( expected0 != *actual0 )
        {
            cout << "FAIL - Bad value" << endl;
        }
        else
        {
            cout << "PASS" << endl;
        }
    }
}

void Tester::Test_PopBack()
{
    DrawLine();
    cout << "TEST: Test_PopBack" << endl;

    // Put tests here
}

void Tester::Test_Clear()
{
    DrawLine();
    cout << "TEST: Test_Clear" << endl;

    // Put tests here
}

void Tester::Test_Get()
{
    DrawLine();
    cout << "TEST: Test_Get" << endl;

    // Put tests here
}

void Tester::Test_GetFront()
{
    DrawLine();
    cout << "TEST: Test_GetFront" << endl;

    // Put tests here
    {
        cout << endl << "Test 1: GetFront() from empty list should return nullptr." << endl;

        List<string> testlist;

        string* expectedAddress = nullptr;
        string* actualAddress = testlist.GetFront();

        cout << "Address, expected: " << expectedAddress << ", actual: " << actualAddress << endl;

        if ( expectedAddress != actualAddress )
        {
            cout << "FAIL - Bad address" << endl;
        }
        else
        {
            cout << "PASS" << endl;
        }
    }

    {
        cout << endl << "Test 2: Push Back 'A', 'B', 'C', GetFront() should return A" << endl;

        List<string> testlist;
        testlist.PushBack( "A" );
        testlist.PushBack( "B" );
        testlist.PushBack( "C" );

        string expectedValue = "A";
        string* actualValue = testlist.GetFront();

        if ( actualValue == nullptr )
        {
            cout << "Nullptr" << endl;
            return;
        }

        cout << "Value, expected: " << expectedValue << ", actual: " << *actualValue << endl;

        if ( *actualValue != expectedValue )
        {
            cout << "FAIL - Bad value" << endl;
        }
        else
        {
            cout << "PASS" << endl;
        }
    }
}

void Tester::Test_GetBack()
{
    DrawLine();
    cout << "TEST: Test_GetBack" << endl;

    // Put tests here
}

void Tester::Test_GetCountOf()
{
    DrawLine();
    cout << "TEST: Test_GetCountOf" << endl;

    // Put tests here
}

void Tester::Test_Contains()
{
    DrawLine();
    cout << "TEST: Test_Contains" << endl;

    // Put tests here
}

void Tester::Test_Remove()
{
    DrawLine();
    cout << "TEST: Test_Remove" << endl;

    // Put tests here
}

void Tester::Test_Insert()
{
    DrawLine();
    cout << "TEST: Test_Insert" << endl;

    // Put tests here
}
