#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Food
{
    public:
    Food( string name, int calories )
    {
        this->name = name;
        this->calories = calories;
    }
    
    string name;
    int calories;
};

// Who remembers what "&" means?
void SetupFoods( vector<Food>& allFood )
{
    allFood.push_back( Food( "Turkey", 110 ) );
    allFood.push_back( Food( "Chicken", 80 ) );
    allFood.push_back( Food( "Mayonnaise", 110 ) );
    allFood.push_back( Food( "Lettuce", 5 ) );
    allFood.push_back( Food( "Tomatoes", 5 ) );
    allFood.push_back( Food( "Pepperjack Cheese", 50 ) );
    allFood.push_back( Food( "Cheddar Cheese", 60 ) );
    allFood.push_back( Food( "White bread", 200 ) );
    allFood.push_back( Food( "Wheat bread", 210 ) );
}

int main()
{
    vector<Food> allFood;
    vector<Food> yourSandwich;
    
    SetupFoods( allFood );
    int totalCalories = 0;
    
    while ( true )
    {
        cout << "Sandwich total calories: " << totalCalories << endl << endl;
        
        cout << "What do you want to put on your sandwich?" << endl;
        for ( unsigned int i = 0; i < allFood.size(); i++ )
        {
            cout << i << ". " << allFood[i].name << "\t" << allFood[i].calories << endl;
        }
        cout << "OR -1 TO STOP" << endl;
        
        int choice;
        cout << "ADD: ";
        cin >> choice;
        
        if ( choice == -1 ) { break; }
        
        yourSandwich.push_back( allFood[choice] );
        totalCalories += allFood[choice].calories;
    }
    
    cout << endl << "YOUR SANDWICH:" << endl;
    for ( unsigned int i = 0; i < yourSandwich.size(); i++ )
    {
        cout << yourSandwich[i].name << "\t" << yourSandwich[i].calories << endl;
    }
    cout << "Total Calories: " << totalCalories << endl;
    
    return 0;
}
