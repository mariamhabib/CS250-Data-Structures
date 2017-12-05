# Project 3 Hints

## Get Max

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
