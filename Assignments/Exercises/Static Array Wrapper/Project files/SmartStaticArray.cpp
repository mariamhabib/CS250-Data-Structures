#include "SmartStaticArray.hpp"

#include "cuTEST/Menu.hpp"

SmartStaticArray::SmartStaticArray()
{
	m_itemCount = 0;
}

bool SmartStaticArray::Push( const string& newItem )
{
	return false; // placeholder
}


bool SmartStaticArray::Insert( int index, const string& newItem )
{
	return false; // placeholder
}


bool SmartStaticArray::Extend( const SmartStaticArray& other )
{
	return false; // placeholder
}


bool SmartStaticArray::Pop()
{
	return false; // placeholder
}


bool SmartStaticArray::Remove( int index )
{
	return false; // placeholder
}


string SmartStaticArray::Get( int index ) const
{
	return "placeholder"; // placeholder
}


int SmartStaticArray::Size() const
{
	return -1; // placeholder
}


bool SmartStaticArray::IsFull() const
{
	return false; // placeholder
}

bool SmartStaticArray::IsEmpty() const
{
	return false; // placeholder
}


string SmartStaticArray::operator[]( int index )
{
	return "placeholder"; // placeholder
}


SmartStaticArray& SmartStaticArray::operator=( const SmartStaticArray& other )
{
    return *this; // placeholder
}

bool SmartStaticArray::operator==( const SmartStaticArray& other )
{
	return false; // placeholder
}


bool SmartStaticArray::operator!=( const SmartStaticArray& other )
{
	return !( *this == other );
}
