#include "SmartArrayTester.hpp"

#include "SmartArray_Static.hpp"

#include <iostream>

bool SmartArrayTester::RunTests()
{
    bool testsPassed = true;

    if ( TestPush() == false )
    {
        testsPassed = false;
    }

    if ( TestGet() == false )
    {
        testsPassed = false;
    }

    if ( TestGetSize() == false )
    {
        testsPassed = false;
    }

    return testsPassed;
}

bool SmartArrayTester::TestPush()
{
    // Test 1
    SmartArray arr;
    arr.Push( "asdf" );
    if ( arr.Get( 0 ) != "asdf" )
    {
        cout << "Error: Get didn't return asdf" << endl;
        return false;
    }

    // Test 2
    SmartArray arr2;

    if ( arr2.Push( "asdf1" ) == false )
    {
        cout << "Error: Didn't return true on push" << endl;
        return false;
    }
    if ( arr2.Push( "asdf2" ) == false )
    {
        cout << "Error: Didn't return true on push" << endl;
        return false;
    }
    if ( arr2.Push( "asdf3" ) == false )
    {
        cout << "Error: Didn't return true on push" << endl;
        return false;
    }
    if ( arr2.Push( "asdf4" ) == false )
    {
        cout << "Error: Didn't return true on push" << endl;
        return false;
    }
    if ( arr2.Push( "asdf5" ) == false )
    {
        cout << "Error: Didn't return true on push" << endl;
        return false;
    }

    if ( arr2.Push( "asdf6" ) != false )
    {
        cout << "Error: Didn't return false on push to full array" << endl;
        return false;
    }

    cout << "TestPush passed" << endl;

    return true;
}

bool SmartArrayTester::TestGet()
{
    // Test 1
    SmartArray arr;
    arr.Push( "asdf" );
    if ( arr.Get( 0 ) != "asdf" )
    {
        cout << "Error: Get didn't return asdf" << endl;
        return false;
    }

    // Test 2
    SmartArray arr1;
    arr1.Push( "asdf" );
    arr1.Push( "jkl" );
    if ( arr1.Get( 0 ) != "asdf" )
    {
        cout << "Error: Get didn't return asdf" << endl;
        return false;
    }
    if ( arr1.Get( 1 ) != "jkl" )
    {
        cout << "Error: Get didn't return jkl" << endl;
        return false;
    }

    // Test 3
    SmartArray arr2;
    arr2.Push( "asdf" );
    arr2.Push( "jkl" );
    if ( arr2.Get( -1 ) != "" )
    {
        cout << "Error: Invalid index didn't return empty string" << endl;
        return false;
    }
    if ( arr2.Get( MAX_SIZE ) != "" )
    {
        cout << "Error: Invalid index didn't return empty string" << endl;
        return false;
    }

    cout << "TestGet passed" << endl;

    return true;
}

bool SmartArrayTester::TestGetSize()
{
    // Test 1
    SmartArray arr;
    if ( arr.GetSize() != 0 )
    {
        cout << "Error: Array size is not 0" << endl;
        return false;
    }

    // Test 2
    SmartArray arr2;
    arr2.Push( "asdf" );
    if ( arr2.GetSize() != 1 )
    {
        cout << "Error: Array size is not 1" << endl;
        return false;
    }

    // Test 3
    SmartArray arr3;
    arr3.Push( "asdf" );
    arr3.Push( "fdsa" );
    arr3.Push( "qwerty" );
    if ( arr3.GetSize() != 3 )
    {
        cout << "Error: Array size is not 3" << endl;
        return false;
    }

    cout << "TestGetSize passed" << endl;

    return true;
}
