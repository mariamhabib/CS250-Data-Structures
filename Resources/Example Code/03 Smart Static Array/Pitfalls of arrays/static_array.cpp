#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int GAME_MAX = 5;
    int gameCount = 0;

    string games[GAME_MAX];

    bool done = false;
    while ( !done )
    {
        cout << "1. Add game" << endl
            << "2. Edit game" << endl
            << "3. Quit" << endl;
        cout << ">> ";
        int choice;
        cin >> choice;
        cin.ignore();

        switch( choice )
        {
            case 1: // Add game
            if ( gameCount == GAME_MAX )
            {
                cout << "ERROR: Array is full";
            }
            else
            {
                cout << "Game name: ";
                getline( cin, games[gameCount] );
                gameCount++;
            }
            break;

            case 2: // Edit game
            cout << "Game index: ";
            int index;
            cin >> index;
            if ( index < 0 || index >= GAME_MAX )
            {
                cout << "ERROR: Invalid index";
            }
            else
            {
                cin.ignore();
                cout << "Name update: ";
                getline( cin, games[index] );
            }
            break;

            case 3: // Quit
            done = true;
            break;
        }
    }

    return 0;
}
