# Project 3 Hints

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
