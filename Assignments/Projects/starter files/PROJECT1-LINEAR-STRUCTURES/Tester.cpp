#include "Tester.hpp"

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

    // Put tests here
}

void Tester::Test_PopFront()
{
    DrawLine();
    cout << "TEST: Test_PopFront" << endl;

    // Put tests here
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
