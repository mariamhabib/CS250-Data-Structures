#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

int main()
{
    srand( time( NULL ) );
    vector<string> data;
    
    ifstream input( "countrylist.txt" );
    
    string buffer;
    while ( getline( input, buffer ) )
    {
        data.push_back( buffer );
    }
    
    input.close();
    
    
    ofstream output( "countrylist_jumbled.txt" );
    
    while ( !data.empty() )
    {
        unsigned int index = rand() % data.size();
        output << data[ index ] << endl;
        
        // Remove item from list
        data.erase( data.begin() + index );
    }
    
    output.close();
    
    return 0;
}
