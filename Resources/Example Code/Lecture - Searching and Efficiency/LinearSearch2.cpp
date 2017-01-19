#include <iostream>
#include <string>
using namespace std;

char GetFirstLetter( const string& str )
{
	return str[0];
}

int FindItem( string arr[], int arraySize, const string& searchItem )
{
	int operationCount = 0;
	
	int distanceToBegin = GetFirstLetter( searchItem ) - GetFirstLetter( arr[0] );
	int distanceToEnd = GetFirstLetter( arr[arraySize-1] ) - GetFirstLetter( searchItem );
	
	if ( distanceToBegin < distanceToEnd )
	{
		// Search term is closer to the starting point
		cout << "Search beginning to end..." << endl;
	
		for ( int i = 0; i < arraySize; i++ )
		{
			operationCount++;
			if ( arr[i] == searchItem )
			{
				cout << operationCount << " comparisons performed" << endl;
				return i;
			}
		}
	}
	else
	{
		// Search term is closer to the ending point
		cout << "Search end to beginning..." << endl;
	
		for ( int i = arraySize-1; i > 0; i-- )
		{
			operationCount++;
			if ( arr[i] == searchItem )
			{
				cout << operationCount << " comparisons performed" << endl;
				return i;
			}
		}
	}
	
	// Done with loop - item not found, return -1.
	cout << operationCount << " comparisons performed" << endl;
	return -1;
}

int main()
{
	string arr[6] = { "A", "C", "E", "G", "I", "J" };
	
	string findMe;
	cout << "Search for what? ";
	cin >> findMe;
	
	int foundIndex = FindItem( arr, 6, findMe );
	
	if ( foundIndex == -1 )
	{
		cout << "Item was not found" << endl;
	}
	else
	{
		cout << "Found at position " << foundIndex << endl;
	}
	
	return 0;
}
