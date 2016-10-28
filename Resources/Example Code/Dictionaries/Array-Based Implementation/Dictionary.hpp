#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

template <typename T1, typename T2>
struct Node
{
    T1 m_key;
    T2 m_value;
};

template <typename T1, typename T2>
class Dictionary
{
public:
    Dictionary()
    {
        m_itemCount = 0;
        AllocateMemory( 10 );
    }

    ~Dictionary()
    {
        DeallocateMemory();
    }

    bool IsEmpty()
    {
        return ( m_itemCount == 0 );
    }

    int GetSize()
    {
        return m_itemCount;
    }

    void Add( const T1& key, const T2& value )
    {
        if ( m_arraySize == m_itemCount )
        {
            Resize();
        }

        m_list[ m_itemCount ].m_key = key;
        m_list[ m_itemCount ].m_value = value;
        m_itemCount++;
    }

    bool Remove( const T1& key )
    {
        int index = GetIndexOfKey( key );
        if ( index == -1 )
        {
            // Key not found
            return false;
        }

        ShiftElementsLeftAt( index );
        return true;
    }

    void Clear()
    {
        int originalSize = m_arraySize;
        DeallocateMemory();
        AllocateMemory( originalSize );
    }

    const T2& GetValue( const T1& key )
    {
        int index = GetIndexOfKey( key );

        if ( index == -1)
        {
            return T2();
        }
        else
        {
            return m_list[ index ].m_value;
        }
    }

    bool Contains( const T1& key )
    {
        return ( GetIndexOfKey( key ) != -1 );
    }

    void Display()
    {
        for ( int i = 0; i < m_itemCount; i++ )
        {
            cout << "KEY: " << m_list[i].m_key << "\t VALUE: " << m_list[i].m_value << endl;
        }
    }

private:
    void Resize()
    {
        // Create bigger array
        int newSize = m_arraySize*2;
        Node<T1, T2>* newList = new Node<T1, T2>[ newSize ];

        // Copy values over
        for ( int i = 0; i < m_arraySize; i++ )
        {
            newList[i] = m_list[i];
        }

        // Delete old array
        delete [] m_list;

        // Update pointer
        m_list = newList;

        // Update array size
        m_arraySize = newSize;
    }

    void AllocateMemory( int size )
    {
        m_arraySize = size;
        m_list = new Node<T1, T2>[ m_arraySize ];
    }

    void DeallocateMemory()
    {
        if ( m_list != nullptr )
        {
            delete [] m_list;
            m_list = nullptr;
            m_arraySize = 0;
            m_itemCount = 0;
        }
    }

    void ShiftElementsLeftAt( int index )
    {
        for ( int i = index; i < m_itemCount-1; i++ )
        {
            m_list[i] = m_list[i+1];
        }
    }

    int GetIndexOfKey( const T1& key )
    {
        for ( int i = 0; i < m_itemCount; i++ )
        {
            if ( m_list[ i ].m_key == key )
            {
                return i;
            }
        }

        return -1;
    }

    Node<T1, T2>* m_list;
    int m_itemCount;
    int m_arraySize;
};

#endif
