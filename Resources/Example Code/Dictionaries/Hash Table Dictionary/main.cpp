#include <iostream>
#include <string>
using namespace std;

#include "Dictionary.hpp"

int main()
{
    Dictionary englishToEsperanto;
    
    englishToEsperanto.Insert( "cat", "kato" );
    englishToEsperanto.Insert( "dog", "hundo" );
    englishToEsperanto.Insert( "bird", "birdo" );
    englishToEsperanto.Insert( "mouse", "muso" );
    englishToEsperanto.Insert( "cow", "bovino" );
    englishToEsperanto.Insert( "horse", "chevalo" );
    englishToEsperanto.Insert( "goat", "kapro" );
    englishToEsperanto.Insert( "chicken", "koko" );
    englishToEsperanto.Insert( "turkey", "meleagro" );
    englishToEsperanto.Insert( "pig", "porko" );
    englishToEsperanto.Insert( "sheep", "shafo" );
    englishToEsperanto.Insert( "elephant", "elefanto" );
    englishToEsperanto.Insert( "bunny", "kuniklo" );
    englishToEsperanto.Insert( "owl", "strigo" );
    englishToEsperanto.Insert( "lion", "leono" );
    englishToEsperanto.Insert( "monkey", "simio" );
    englishToEsperanto.Insert( "penguin", "pingveno" );
    
    return 0;
}
