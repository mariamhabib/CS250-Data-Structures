#ifndef WordCounter_HPP
#define WordCounter_HPP

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Node
{
    public:
    Node() { ptrNext = nullptr; }

    Node* ptrNext;
    string word;
    int count;
};

class WordCounter
{
    public:
    WordCounter()
    {
    }

    ~WordCounter()
    {
    }

    void ClearList()
    {
    }

    Node* FindItem( const string& data )
    {
		return nullptr;
    }

    void AddItem( const string& data )
    {
    }

    void FreeNode( Node*& node )
    {
    }

    int Size()
    {
		return m_count;
    }

    void Print()
    {
        ofstream output( "wordcount.txt" );
		output << endl << "List Size: " << m_count << endl;
        Node* ptrCurrent = m_ptrFirst;

        int counter = 0;
        while ( counter < m_count )
        {
            output << "#" << counter << "\tCount: " << ptrCurrent->count << "\tWord: " << ptrCurrent->word << endl;
            ptrCurrent = ptrCurrent->ptrNext;
            counter++;
        }
        output.close();
    }

    private:
    Node* m_ptrFirst;
    Node* m_ptrLast;
    int m_count;
};

#endif
