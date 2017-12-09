# Project 3 Hints

Make sure to pay attention to the member variables available in each class...

```c++
template <typename TK, typename TD>
class Node
{
public:
    Node();
    ~Node();
    Node<TK, TD>* ptrLeft;
    Node<TK, TD>* ptrRight;
    TD data;
    TK key;
};
```

```c++
template <typename TK, typename TD>
class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void Insert( const TK& newKey, const TD& newData );
    void Delete( const TK& key );
    bool Contains( const TK& key );
    bool RecursiveContains( const TK& key, Node<TK, TD>* ptrCurrent );
    string GetInOrder();
    string GetPreOrder();
    string GetPostOrder();
    TK* GetMax();
    int GetCount();
    int GetHeight();
    TD* GetData( const TK& key );
    Node<TK, TD>* FindNode( const TK& key );
    Node<TK, TD>* RecursiveFindNode( const TK& key, Node<TK, TD>* ptrCurrent );
    Node<TK, TD>* FindParentOfNode( const TK& key );
    void RecursiveInsert( const TK& newKey, const TD& newData, Node<TK, TD>* ptrCurrent );
    void GetInOrder( Node<TK, TD>* ptrCurrent, stringstream& stream );
    void GetPreOrder( Node<TK, TD>* ptrCurrent, stringstream& stream );
    void GetPostOrder( Node<TK, TD>* ptrCurrent, stringstream& stream );
    TK* GetMax( Node<TK, TD>* ptrCurrent );
    int GetHeight( Node<TK, TD>* ptrCurrent );

private:
    Node<TK, TD>* m_ptrRoot;
    int m_nodeCount;

friend class Tester;
};
```


## Get Max

```TK* GetMax( Node<TK, TD>* ptrCurrent )```

Given some tree...

```
    C
  /   \
 B     E
      / \
     D   F
```

The max will always be the right-most node in the tree. Continue traversing the tree right-ward until you run out of children off to the right.

Terminating case: If the right child is NULL, then return the current node

Recursive case: If the right child is NOT NULL, then return the GetMax function, passing in the right child.

## Get Height

```int GetHeight( Node<TK, TD>* ptrCurrent )```

Given some tree...

```
    C
  /   \
 B     E
      / \
     D   F
```

Given some node `ptrCurrent`, the max height will be the greater of either: The height of the left subtree OR the height of the right subtree (plus adding 1 to the height for the current node.)

Cases:

* Current has no children (Current is a leaf)
    * Return 0
* Current has only left child
    * Return height of left subtree + 1
* Current has only right child
    * Return height of right subtree + 1
* Current has left and right children
    * Find the MaxHeight of the left subtree and the right subtree, storing each in variables.
    * Compare which is greater
    * Return GREATER + 1
    
## Contains

```c++
    bool Contains( const TK& key )
    {
		Node<TK, TD>* ptrCurrent = m_ptrRoot;

		// Keep looping until we're out of nodes
		while (ptrCurrent != nullptr)
		{
			// Did we find it?
			if (key == ptrCurrent->key)
			{
				// Found the node we're looking for - return true
				return true;
			}
			else if (key < ptrCurrent->key)
			{
				// Go left and search there
				ptrCurrent = ptrCurrent->ptrLeft;
			}
			else if (key > ptrCurrent->key)
			{
				// Go right and search there
				ptrCurrent = ptrCurrent->ptrRight;
			}
		}

		return false; // didn't find the node - return false
    }
```

Your FindNode function will be similar.
