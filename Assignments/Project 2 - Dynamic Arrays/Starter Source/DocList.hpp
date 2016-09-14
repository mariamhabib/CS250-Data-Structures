#ifndef DOCLIST_HPP
#define DOCLIST_HPP

#include "Document.hpp"

#include <iostream>
using namespace std;

class DocList
{
    public:
    DocList();
    ~DocList();

    bool AddItem( IDocument* item );
    bool RemoveItem( int index );

    int GetSize();

    IDocument* operator[]( int index );

    private:
    void AllocateMemory( int size );
    void FreeMemory();
    bool FreeDocument( int index );
    bool ResizeArray();
    void ShiftItemsLeft( int index );

    IDocument ** m_ptrDocArray;
    int m_itemCount;
    int m_arraySize;
};

#endif
