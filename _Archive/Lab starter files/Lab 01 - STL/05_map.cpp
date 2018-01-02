#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    // Create a map, where the key and value are both strings.

    // Populate the map with the colors for red, green, blue, magenta, cyan, and yellow
    
    while ( true )
    {
        string color;
        cout << endl << "Enter a color, or QUIT to stop: ";
        cin >> color;

        // Display the value of the color map, using the 'color' variable as the key.
        
        if ( color == "QUIT" )
        {
            break;
        }
    }
    
    return 0;
}
