#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <limits>
using namespace std;

void CreateDummyFiles( list<string>& filenames );
void MoveFiles( list<string>& filenames );
string ToString( int num );
void Pause();

int main()
{
	list<string> filenames;
	CreateDummyFiles( filenames );
	
	cout << "Created files" << endl;
	Pause();
	
	MoveFiles( filenames );
	
	cout << "Moved files" << endl;
	Pause();
	
	return 0;
}

void CreateDummyFiles( list<string>& filenames )
{
	for ( int i = 0; i < 10; i++ )
	{
		string filename = "dummy_" + ToString( i );
		ofstream output( filename.c_str() );
		output << i << endl;
		output.close();
		
		filenames.push_back( filename );
	}
}

void MoveFiles( list<string>& filenames )
{
	string command = "mkdir bob";
	system( command.c_str() );
	
	for ( list<string>::iterator it = filenames.begin();
		it != filenames.end();
		it++ )
	{
		string currentFilename = *it;
		
		command = "mv " + currentFilename + " bob/" + currentFilename;
		system( command.c_str() );
	}
}



string ToString( int num )
{
    stringstream ss;
    ss << num;
    return ss.str();
}

void Pause()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "pause" );
    #else
        cout << endl << " Press ENTER to continue..." << endl;
        cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
    #endif
}
