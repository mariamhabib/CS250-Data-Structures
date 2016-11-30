#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

vector<string> LoadBook( const string& filename )
{
    vector<string> words;
    
    ifstream input( filename );
    
    string buffer;
    while ( input >> buffer )
    {
        words.push_back( buffer );
    }
    
    input.close();
    
    return words;
}

int LinearSearch( vector<string>& haystack, const string& needle )
{
    for ( unsigned int i = 0; i < haystack.size(); i++ )
    {
        if ( haystack[i] == needle )
        {
            cout << "Search ended at position " << i << " of " << haystack.size() << endl;
            return i;
        }
    }
    cout << "Search ended at position " << haystack.size() << " of " << haystack.size() << endl;
    return -1;
}

int CustomSearch( vector<string>& haystack, const string& needle )
{
    // Implement a custom search...
    return -1;
}

int main()
{
    vector<string> words = LoadBook( "hans_christian_andersen.txt" );
    
    cout << "Linear Search for \"facility\"... " << endl;
    int result = LinearSearch( words, "swamp" );
    
    result = CustomSearch( words, "swamp" );
    
    return 0;
}
