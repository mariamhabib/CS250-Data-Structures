#include "SmartArrayTester.hpp"
#include "SmartArray_Static.hpp"
#include <iostream>
#include <string>
using namespace std;


bool SmartArrayTester::RunTests()
{
    bool allTestsPassed = true;

    if ( TestPush() == false )
    {
        cout << "TestPush failed" << endl;
        allTestsPassed = false;
    }
    else
    {
        cout << "TestPush passed" << endl;
    }

    if ( TestGet() == false )
    {
        cout << "TestGet failed" << endl;
        allTestsPassed = false;
    }
    else
    {
        cout << "TestGet passed" << endl;
    }

    if ( TestGetSize() == false )
    {
        cout << "TestGetSize failed" << endl;
        allTestsPassed = false;
    }
    else
    {
        cout << "TestGetSize passed" << endl;
    }

    return allTestsPassed;
}

bool SmartArrayTester::TestPush()
{
    // test 1
    SmartArray arr;
    arr.Push( "asdf" );
    if ( arr.Get( 0 ) != "asdf" )
    {
        cout << "TestPush failed 1" << endl;
        return false;
    }

    // test 2
    SmartArray arr2;
    arr2.Push( "asdf" );
    arr2.Push( "qwerty" );
    if ( arr2.Get( 0 ) != "asdf" )
    {
        cout << "TestPush failed 2" << endl;
        return false;
    }
    if ( arr2.Get( 1 ) != "qwerty" )
    {
        cout << "TestPush failed 3" << endl;
        return false;
    }

    // test 3: trying to insert too many items
    SmartArray arr3;
    if ( arr3.Push( "asdf1" ) != true )
    {
        cout << "TestPush failed 4" << endl;
        return false;
    }

    if ( arr3.Push( "asdf2" ) != true )
    {
        cout << "TestPush failed 5" << endl;
        return false;
    }

    if ( arr3.Push( "asdf3" ) != true )
    {
        cout << "TestPush failed 6" << endl;
        return false;
    }

    if ( arr3.Push( "asdf4" ) != true )
    {
        cout << "TestPush failed 7" << endl;
        return false;
    }

    if ( arr3.Push( "asdf5" ) != true )
    {
        cout << "TestPush failed 8" << endl;
        return false;
    }

    if ( arr3.Push( "asdf6" ) != false )
    {
        cout << "TestPush failed 9" << endl;
        return false;
    }

    return true;
}

bool SmartArrayTester::TestGet()
{
    // test 1
    SmartArray arr;
    arr.Push( "asdf" );
    if ( arr.Get( 0 ) != "asdf" )
    {
        cout << "TestGet failed 1" << endl;
        return false;
    }

    // test 2
    SmartArray arr2;
    arr2.Push( "asdf" );
    arr2.Push( "qwerty" );
    if ( arr2.Get( 0 ) != "asdf" )
    {
        cout << "TestGet failed 2" << endl;
        return false;
    }
    if ( arr2.Get( 1 ) != "qwerty" )
    {
        cout << "TestGet failed 3" << endl;
        return false;
    }
    if ( arr2.Get( MAX_SIZE ) != "" )
    {
        cout << "TestGet failed 4" << endl;
        return false;
    }

    // test 3
    string names[MAX_SIZE] = { "a", "b", "c", "d", "e" };
    SmartArray arr3;
    for ( int i = 0; i < MAX_SIZE; i++ )
    {
        arr3.Push( names[i] );
    }

    for ( int i = 0; i < MAX_SIZE; i++ )
    {
        if ( arr3.Get( i ) != names[i] )
        {
            cout << "TestGet failed 5" << endl;
            return false;
        }
    }

    return true;
}

bool SmartArrayTester::TestGetSize()
{

    // test 0
    SmartArray arr3;
    if ( arr3.GetSize() != 0 )
    {
        cout << "TestGetSize failed 0" << endl;
        return false;
    }

    // test 1
    SmartArray arr;
    arr.Push( "asdf" );
    if ( arr.GetSize() != 1 )
    {
        cout << "TestGetSize failed 1" << endl;
        return false;
    }

    // test 2
    SmartArray arr2;
    arr2.Push( "asdf" );
    arr2.Push( "qwerty" );
    if ( arr2.GetSize() != 2 )
    {
        cout << "TestGetSize failed 2" << endl;
        return false;
    }

    // test 4
    SmartArray arr4;
    arr4.Push( "asdf" );
    arr4.Push( "qwerty" );
    arr4.Push( "asdf" );
    arr4.Push( "qwerty" );
    arr4.Push( "asdf" );
    arr4.Push( "qwerty" );
    if ( arr4.GetSize() != 5 )
    {
        cout << "TestGetSize failed 4" << endl;
        return false;
    }

    return true;
}









