#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <string>
#include <iostream>
using namespace std;

class Entry
{
    public:
    string key;
    string value;
};

class Dictionary
{
    public:    
    Dictionary()
    {
        m_arraySize = 10;
        for ( int i = 0; i < m_arraySize; i++ )
        {
            m_strings[i].key = "";
            m_strings[i].value = "";
        }
    }
    
    void Insert( const string& key, const string& value )
    {
        int index = ConvertKeyToIndex( key );
        m_strings[index].value = value;
        m_strings[index].key = key;
        cout << "Inserted \"" << value << "\" at index " << index << endl;
    }
    
    void Remove( const string& key )
    {
        int index = GetIndexOfKey( key );
        m_strings[index].key = "";
        m_strings[index].value = "";
    }
    
    string Get( const string& key )
    {
        int index = GetIndexOfKey( key );
        return m_strings[index].value;
    }
    
    private:    
    
    int ConvertKeyToIndex( const string& key )
    {
        int intkey = StringToInt( key );        
        int index = HashFunction( intkey );
        
        // Linear probing
        while ( m_strings[index].value != "" )
        {
            index++;
        }
        
        return index;
    }
    
    int GetIndexOfKey( const string& key )
    {
        int intkey = StringToInt( key );        
        int index = HashFunction( intkey );
        
        while ( m_strings[index].key != key )
        {
            index++;
        }
        
        return index;
    }
    
    int HashFunction( int value )
    {
        return value % 23;
    }
    
    int StringToInt( const string& str )
    {
        int num = 0;
        for ( unsigned int i = 0; i < str.size(); i++ )
        {
            num += str[i];
        }
        return num;
    }
    
    Entry m_strings[10];
    int m_arraySize; 
};

#endif
