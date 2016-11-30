#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

#include "Timer.hpp"
#include "BigObject.hpp"

bool Search( BigObject* objList, int arraySize, int searching )
{
    for ( int i = 0; i < arraySize; i++ )
    {
        if ( objList[i] == searching )
        {
            return true;
        }
    }

    return false;
}

void Test1()
{
    cout << "Test1" << endl;
    cout << "Building object list..." << endl;
    int arraySize = 100000;
    BigObject* objList = new BigObject[ arraySize ];

    cout << "Searching..." << endl;
    dal::Timer::Start();
    bool result = Search( objList, arraySize, 4 );
    cout << "Result: " << result << endl;
    cout << "Timer:  " << dal::Timer::GetElapsedTime().count() << endl;

    delete [] objList;
}

void Test2()
{
    cout << "Test2" << endl;
    cout << "Building object list..." << endl;
    int arraySize = 1000000;
    BigObject* objList = new BigObject[ arraySize ];

    cout << "Searching..." << endl;
    dal::Timer::Start();
    bool result = Search( objList, arraySize, 4 );
    cout << "Result: " << result << endl;
    cout << "Timer:  " << dal::Timer::GetElapsedTime().count() << endl;

    delete [] objList;
}

int main()
{
    srand( time( NULL ) );

    Test1();
    Test2();

    return 0;
}
