#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
using namespace std;

template <typename T>
class Node
{
    public:
    Node()
    {
        ptrLeft = nullptr;
        ptrRight = nullptr;
    }
    
    T data;
    
    Node<T>* ptrLeft;
    Node<T>* ptrRight;
};

template <typename T>
class BinaryTree
{
    public:
    BinaryTree()
    {
        m_ptrRoot = nullptr;
        m_nodeCount = 0;
    }
    
    ~BinaryTree()
    {
        RecursiveFree( m_ptrRoot );
    }
    
    void Insert( T value )
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        
        if ( m_ptrRoot == nullptr )
        {
            m_ptrRoot = newNode;
        }
        else
        {
            RecursiveInsert( m_ptrRoot, newNode );
        }
        
        m_nodeCount++;
    }
    
    void Remove( T value )
    {
        Node<T>* deleteme = RecursiveFind( m_ptrRoot, value );
        
        if ( deleteme == nullptr )
        {
            return;
        }
        
        Node<T>* parent = RecursiveParentFind( m_ptrRoot, deleteme );
        
        // Break the tree first
        if ( parent->ptrLeft == deleteme )
        {
            parent->ptrLeft = nullptr;
        }
        else if ( parent->ptrRight == deleteme )
        {
            parent->ptrRight = nullptr;
        }
        
        if ( deleteme->ptrLeft != nullptr || deleteme->ptrRight != nullptr )
        {          
            // Reinsert the children.
            RecursiveReinsertSubtree( deleteme );
        }
        
        delete deleteme;
        deleteme = nullptr;
    }
    
    bool Contains( T value )
    {
        return ( RecursiveFind( m_ptrRoot, value ) != nullptr );
    }
    
    int GetNodeCount()
    {
        return m_nodeCount;
    }
    
    int GetHeight()
    {
        return RecursiveHeightFinder( m_ptrRoot );
    }
    
    void DisplayPreorder()
    {
        cout << endl << endl << "PREORDER" << endl;
        RecursivePreorder( m_ptrRoot );
    }
    
    void DisplayInorder()
    {
        cout << endl << endl << "INORDER" << endl;
        RecursiveInorder( m_ptrRoot );
    }
    
    void DisplayPostorder()
    {
        cout << endl << endl << "POSTORDER" << endl;
       RecursivePostorder( m_ptrRoot );
    }
    
    private:    
    void RecursiveInsert( Node<T>* node, Node<T>* newNode )
    {
        // If value is < node's value, then it goes left.
        // If value is > node's value, then it goes right.
        // If the direction is empty, put the new node here. 
        // Otherwise, choose this node next and keep traversing.
        
        if ( newNode->data < node->data ) 
        {
            if ( node->ptrLeft == nullptr )
            {
                node->ptrLeft = newNode;
            }
            else
            {
                RecursiveInsert( node->ptrLeft, newNode );
            }
        }
        else if ( newNode->data > node->data )
        {
            if ( node->ptrRight == nullptr )
            {
                node->ptrRight = newNode;
            }
            else
            {
                RecursiveInsert( node->ptrRight, newNode );
            }
        }
    }
    
    void RecursivePreorder( Node<T>* node )
    {
        if ( node != nullptr )
        {
            cout << node->data << " ";
            RecursivePreorder( node->ptrLeft );
            RecursivePreorder( node->ptrRight );
        }
    }
    
    void RecursiveInorder( Node<T>* node )
    {
        if ( node != nullptr )
        {
            RecursiveInorder( node->ptrLeft );
            cout << node->data << " ";
            RecursiveInorder( node->ptrRight );
        }
    }
    
    void RecursivePostorder( Node<T>* node )
    {
        if ( node != nullptr )
        {
            RecursivePostorder( node->ptrLeft );
            RecursivePostorder( node->ptrRight );
            cout << node->data << " ";
        }
    }
    
    void RecursiveFree( Node<T>* node )
    {
        if ( node != nullptr )
        {
            RecursiveFree( node->ptrLeft );
            RecursiveFree( node->ptrRight );
            delete node;
            node = nullptr;
        }
    }
    
    Node<T>* RecursiveFind( Node<T>* node, T value )
    {
        if ( node->data == value )
        {
            return node;
        }
        
        else if ( value < node->data && node->ptrLeft == nullptr )
        {
            return nullptr;
        }
        else if ( value > node->data && node->ptrRight == nullptr )
        {
            return nullptr;
        }
        
        else if ( value < node->data )
        {
            return RecursiveFind( node->ptrLeft, value );
        }
        
        else if ( value > node->data )
        {
            return RecursiveFind( node->ptrRight, value );
        }
    }
    
    Node<T>* RecursiveParentFind( Node<T>* node, Node<T>* findMe )
    {
        if ( node->ptrLeft == findMe || node->ptrRight == findMe )
        {
            return node;
        }
        
        else if ( findMe->data < node->data && node->ptrLeft == nullptr )
        {
            return nullptr;
        }
        
        else if ( findMe->data > node->data && node->ptrRight == nullptr )
        {
            return nullptr;
        }
        
        else if ( findMe->data < node->data )
        {
            return RecursiveParentFind( node->ptrLeft, findMe );
        }
        
        else if ( findMe->data > node->data )
        {
            return RecursiveParentFind( node->ptrRight, findMe );
        }
    }
    
    int RecursiveHeightFinder( Node<T>* node )
    {
        if ( node == nullptr )
        {
            return 0;
        }
        else
        {
            int leftSubtreeHeight = RecursiveHeightFinder( node->ptrLeft );
            int rightSubtreeHeight = RecursiveHeightFinder( node->ptrRight );
            int max = ( leftSubtreeHeight > rightSubtreeHeight ) 
                ? rightSubtreeHeight
                : leftSubtreeHeight;
            
            return max + 1;
        }
    }
    
    void RecursiveReinsertSubtree( Node<T>* node )
    {
        if ( node != nullptr )
        {
            RecursiveReinsertSubtree( node->ptrLeft );
            RecursiveInsert( m_ptrRoot, node );
            RecursiveReinsertSubtree( node->ptrRight );
        }
    }
    
    Node<T>* m_ptrRoot;
    int m_nodeCount;
};

#endif
