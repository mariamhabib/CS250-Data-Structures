#ifndef _function2
#define _function2

int SumArray( int arr[], int size )
{
    for ( int i = 0; i <= size; i++ )
    {
        int sum = 0;
        sum += arr[i];
    }
    return sum;
}

/* Add a test to this function */
void Test_SumArr()
{
    cout << "************ Test_SumArr ************" << endl;

    int input1, input2, input3;
    int expectedOutput;
    int actualOutput;

    /* TEST 1 ********************************************/
    int inputArray1[] = { 1, 2, 3, 4 };
    expectedOutput = 10;

    actualOutput = SumArray( inputArray1, 4 );
    if ( actualOutput == expectedOutput )
    {
        cout << "Test_SumArr: Test 1 passed!" << endl;
    }
    else
    {
        cout << "Test_SumArr: Test 1 FAILED! \n\t"
        << "Inputs: 1, 2, 3, 4 \n\t"
        << "Expected: " << expectedOutput << "\n\t"
        << "Actual: " << actualOutput << endl << endl;
    }

    /* TEST 2 ********************************************/
    // CREATE YOUR OWN TEST
    input1 = 0;             // change me
    input2 = 0;             // change me
    input3 = 0;             // change me
    expectedOutput = -1;    // change me


    // Run test (keep this as-is):
    actualOutput = SumThree( input1, input2, input3 );
    if ( actualOutput == expectedOutput )
    {
        cout << "Test_SumArr: Test 2 passed!" << endl;
    }
    else
    {
        cout << "Test_SumArr: Test 2 FAILED! \n\t"
        << "Inputs: PUT YOUR INPUTS HERE \n\t"
        << "Expected: " << expectedOutput << "\n\t"
        << "Actual: " << actualOutput << endl << endl;
    }

    /* TEST 3 ********************************************/
    // CREATE YOUR OWN TEST
    input1 = 0;             // change me
    input2 = 0;             // change me
    input3 = 0;             // change me
    expectedOutput = -1;    // change me


    // Run test (keep this as-is):
    actualOutput = SumThree( input1, input2, input3 );
    if ( actualOutput == expectedOutput )
    {
        cout << "Test_SumArr: Test 3 passed!" << endl;
    }
    else
    {
        cout << "Test_SumArr: Test 3 FAILED! \n\t"
        << "Inputs: PUT YOUR INPUTS HERE \n\t"
        << "Expected: " << expectedOutput << "\n\t"
        << "Actual: " << actualOutput << endl << endl;
    }
}

#endif

