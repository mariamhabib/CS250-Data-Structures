#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct TicTacToe
{
    char grid[3][3];
    
    TicTacToe()
    {
        for ( int y = 0; y < 3; y++ )
        {
            for ( int x = 0; x < 3; x++ )
            {
                grid[x][y] = ' ';
            }
        }
    }
    
    void Draw()
    {
        for ( int y = 0; y < 3; y++ )
        {
            for ( int x = 0; x < 3; x++ )
            {
                cout << grid[x][y];
                if ( x == 0 || x == 1 ) { cout << "|"; }
            }
            cout << endl;
            if ( y == 0 || y == 1 ) { cout << "------" << endl; }
        }
    }
};

int main()
{
    TicTacToe board;
    stack<TicTacToe> states;
    
    int turn = 0;
    
    while ( true )
    {
        system( "clear" );
        board.Draw();
        cout << endl;
        
        int x, y;
        cout << states.size() << " states" << endl;
        cout << "Player " << turn << " turn, enter location for move or -1 to undo: ";
        cin >> x >> y;
        
        if ( x == -1 || y == -1 )
        {
            states.pop();
            board = states.top();
        }
        else
        {
            if ( turn == 0 )
            {
                board.grid[x][y] = 'x';
                turn = 1;
            }
            else
            {
                board.grid[x][y] = 'o';
                turn = 0;
            }
            
            states.push( board );
        }
    }
    
    
    return 0;
}

