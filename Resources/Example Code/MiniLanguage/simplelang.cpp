#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <sstream>
using namespace std;

void ReadCode( list<string>& linesOfCode, const string& filename );
void ExecuteCode( list<string>& linesOfCode, list<string>::iterator& startPoint );
void SkipCode( list<string>& linesOfCode, list<string>::iterator& startPoint );
int StringToInt( const string& str );

int main()
{
	int arraySize = 2;
	string files[] = { "set_and_print.moo", "add_vars.moo" };
	
	
	while ( true )
	{
		cout << endl << endl << "PROGRAM LIST" << endl << "------------------------------" << endl;
		
		for ( int i = 0; i < arraySize; i++ )
		{
			cout << i << "\t" << files[i] << endl;
		}
		
		int which;
		cout << endl << "Run which? ";
		cin >> which;
		
		if ( which == -1 ) { break; }
		
		list<string> linesOfCode;
		
		cout << endl << endl << "READ CODE" << endl << "------------------------------" << endl;
		ReadCode( linesOfCode, files[ which ] );
		
		cout << endl << endl << "EXECUTE CODE" << endl << "------------------------------" << endl;
		list<string>::iterator it = linesOfCode.begin();
		ExecuteCode( linesOfCode, it );
	}
	
	return 0;
}

void ReadCode( list<string>& linesOfCode, const string& filename )
{
	string line;
	ifstream input( filename.c_str() );
	
	while ( getline( input, line ) )
	{
		linesOfCode.push_back( line );
	}
	
	cout << linesOfCode.size() << " lines of code" << endl;
	
	input.close();
}

void SkipCode( list<string>& linesOfCode, list<string>::iterator& startPoint )
{
	string token;
	
	for ( list<string>::iterator it = startPoint;
		it != linesOfCode.end();
		it++ )
	{
		istringstream lineStream;
		lineStream.str( *it );
		
		while ( lineStream >> token )
		{
			if ( token == "END_IF" )
			{
				++it;
				break;
			}
		}		
	}
}

void ExecuteCode( list<string>& linesOfCode, list<string>::iterator& startPoint )
{
	int memorySlots[10];
	
	string token;
	
	for ( list<string>::iterator it = startPoint;
		it != linesOfCode.end();
		it++ )
	{
		istringstream lineStream;
		lineStream.str( *it );
		
		while ( lineStream >> token )
		{
			if ( token == "SET_VAR" )
			{
				// Store where?
				int index;
				lineStream >> index;
				
				// To what value?	
				int value;
				lineStream >> value;
				
				memorySlots[ index ] = value;
			}
			else if ( token == "PRINT_TEXT" )
			{				
				// Print what?
				string text;
				while ( lineStream >> text )
				{
					cout << text << " ";
				}
			}
			else if ( token == "PRINT_ENDL" )
			{
				cout << endl;
			}
			else if ( token == "PRINT_VAR" )
			{				
				// Store where?
				int index;
				lineStream >> index;
				
				cout << memorySlots[ index ] << " ";
			}
			else if ( token == "ADD_VARS" )
			{				
				// Store where?
				int index;
				lineStream >> index;
				
				// Add which variables?
				int a, b;
				lineStream >> a >> b;
				
				memorySlots[ index ] = memorySlots[ a ] + memorySlots[ b ];
			}
			else if ( token == "ADD_NUM" )
			{
				// Add to which?
				int index;
				lineStream >> index;
				
				// Add which number?
				int value;
				lineStream >> value;
				
				memorySlots[ index ] += value;				
			}
		}
	}
}

int StringToInt( const string& str )
{
    istringstream ss( str );
    int val;
    ss >> val;
	return val;
}

