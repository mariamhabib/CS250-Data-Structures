#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

struct Racer
{
    int speed;
    int position;
    
    void Move()
    {
        position += speed;
    }
};

int main()
{
    vector<Racer> racers;
    
    for ( unsigned int i = 0; i < 4; i++ )
    {
        Racer newRacer;
        newRacer.position = 0;
        newRacer.speed = rand() % 10 + 1;
        racers.push_back( newRacer );
    }
    
    int finishLine = 100;
    bool done = false;
    
    while ( !done )
    {
        for ( unsigned int i = 0; i < 4; i++ )
        {
            racers[i].Move();
            if ( racers[i].position >= finishLine )
            {
                done = true;
            }
            
            cout << "Racer " << i << " is at position " << racers[i].position << endl;
        }
        
        cout << endl << endl;
    }
    
    return 0;
}

