#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    vector<int> myVector;
    myVector.push_back( 20 );

    cout << "Vector out of bounds:" << endl;
    try
    {
        cout << myVector.at(2) << endl;
    }
    catch( const out_of_range& ex )
    {
        cout << "out_of_range: "
            << ex.what() << endl;
    }

    return 0;
}
