#include "DocList.hpp"

DocList::DocList()
{
    cout << "(DocList Constructor)" << endl;
}

DocList::~DocList()
{
    cout << "(DocList Destructor)" << endl;
}

void DocList::AllocateMemory( int size )
{
    cout << "(DocList AllocateMemory)" << endl;
}

void DocList::FreeMemory()
{
    cout << "(DocList FreeMemory)" << endl;
}

bool DocList::FreeDocument( int index )
{
    cout << "(DocList FreeDocument " << index << ")" << endl;
    return false;
}

int DocList::GetSize()
{
    return -1;
}


bool DocList::AddItem( IDocument* item )
{
    cout << "(DocList AddItem " << item->GetFriendlyName() << ")" << endl;
    return false;
}

bool DocList::RemoveItem( int index )
{
    cout << "(DocList RemoveItem " << index << ")" << endl;
    return false;
}

void DocList::ShiftItemsLeft( int index )
{
    cout << "(DocList ShiftItemsLeft " << index << ")" << endl;
}

IDocument* DocList::operator[]( int index )
{
    return nullptr;
}

bool DocList::ResizeArray()
{
    cout << "(DocList ResizeArray)" << endl;
    return false;
}
