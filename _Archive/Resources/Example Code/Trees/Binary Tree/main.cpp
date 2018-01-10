#include <iostream>
#include <string>
using namespace std;

#include "BinaryTree.hpp"

void AddStates( BinaryTree<string>& states );
void AddLetters( BinaryTree<string>& states );

int main()
{
    BinaryTree<string> letters;
    BinaryTree<string> states;
    
    AddLetters( letters );
    AddStates( states );
    
    cout << "Letters" << endl;
    letters.DisplayPreorder();
    letters.DisplayInorder();
    letters.DisplayPostorder();
    
    cout << endl << endl << "Is B in the tree? " << letters.Contains( "B" ) << endl;
    cout << "Is XYZ in the tree? " << letters.Contains( "XYZ" ) << endl;
    cout << endl << "Tree height: " << letters.GetHeight() << endl;
    
    cout << "Remove R" << endl;
    letters.Remove( "R" );
    letters.DisplayInorder();
    
    cout << endl << endl << "States" << endl;
    states.DisplayPreorder();
    states.DisplayInorder();
    states.DisplayPostorder();
    
    cout << endl << endl << "Is Kerala in the tree? " << states.Contains( "Kerala" ) << endl;
    cout << "Is Kansas in the tree? " << states.Contains( "Kansas" ) << endl;
    cout << endl << "Tree height: " << states.GetHeight() << endl;
    
    return 0;
}

void AddStates( BinaryTree<string>& states )
{
    
    states.Insert( "Kerala" );
    states.Insert( "Maharashtra" );
    states.Insert( "Manipur" );
    states.Insert( "Meghalaya" );
    states.Insert( "Uttar Pradesh" );
    states.Insert( "Uttarakhand" );
    states.Insert( "West Bengal" );
    states.Insert( "Daman" );
    states.Insert( "Dadra" );
    states.Insert( "Mizoram" );
    states.Insert( "Nagaland" );
    states.Insert( "Delhi" );
    states.Insert( "Odisha" );
    states.Insert( "Puducherry" );
    states.Insert( "Punjab" );
    states.Insert( "Rajasthan" );
    states.Insert( "Sikkim" );
    states.Insert( "Tamil Nadu" );
    states.Insert( "Telangana" );
    states.Insert( "Tripura" );
    states.Insert( "Andaman" );
    states.Insert( "Andhra Pradesh" );
    states.Insert( "Arunachal Pradesh" );
    states.Insert( "Assam" );
    states.Insert( "Bihar" );
    states.Insert( "Chandigarh" );
    states.Insert( "Chhattisgarh" );
    states.Insert( "Jharkhand" );
    states.Insert( "Karnataka" );
    states.Insert( "Goa" );
    states.Insert( "Gujarat" );
    states.Insert( "Haryana" );
    states.Insert( "Himachal Pradesh" );
    states.Insert( "Jammu" );
    states.Insert( "Lakshadweep" );
    states.Insert( "Madhya Pradesh" );
}

void AddLetters( BinaryTree<string>& states )
{
    
    states.Insert( "V" );
    states.Insert( "W" );
    states.Insert( "X" );
    states.Insert( "Y" );
    states.Insert( "F" );
    states.Insert( "I" );
    states.Insert( "P" );
    states.Insert( "Q" );
    states.Insert( "G" );
    states.Insert( "H" );
    states.Insert( "D" );
    states.Insert( "E" );
    states.Insert( "S" );
    states.Insert( "A" );
    states.Insert( "B" );
    states.Insert( "C" );
    states.Insert( "J" );
    states.Insert( "K" );
    states.Insert( "L" );
    states.Insert( "M" );
    states.Insert( "N" );
    states.Insert( "O" );
    states.Insert( "U" );
    states.Insert( "T" );
    states.Insert( "R" );
    states.Insert( "Z" );
}
