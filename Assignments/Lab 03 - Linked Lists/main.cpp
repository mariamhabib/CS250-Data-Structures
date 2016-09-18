#include <fstream>
#include <iostream>
using namespace std;

#include "WordCounter.hpp"

int main()
{
    WordCounter wordList;
    string buffer;

    ifstream input( "story.txt" );

    while ( input >> buffer )
    {
        wordList.AddItem( buffer );
    }
    wordList.Print();

    input.close();

    wordList.Print();

    return 0;
}
