
# Binary Tree

A bindary tree is a tree data structure in which each parent node can have at most two children. Each node of a binary tree consists of three items:
* data
* address of left child
* address of right child

## Types of binary tree

### [Full Binary Tree](./../tree-binary-full/README.md)
Every parent node/internal node has either two or no children


<pre>
       1
      / \
     2   3
    / \
   4   5
      / \
     6   7
</pre>

### [Perfect Binary Tree](./../tree-binary-perfect/README.md)
Every internal node has exactly two child nodes and all the leaf nodes are at the same level

<pre>
       1
      / \
     2   3
    /\   /\
   4  5 6  7
</pre>

### [Complete Binary Tree](./../tree-binary-full/README.md)
Like a full, but with two differences:

1. Every level must be completely filled
2. All the leaf elements must lean towards left
3. The last leaf element might not have a right sibling

<pre>
       1
      / \
     2   3
    /\   |
   4  5  6  
</pre>

### Degenerate or Pathological Tree

Single child either left or right

<pre>
     1
    /
   2
    \
     3
      \
       4
</pre>

### Skewd Binary Tree
Is a Degenerate Tree in which the tree is either dominated by left nodes or the right nodes. Thus, there are 2 types: left-skewed binary tree and right-skewed binary tree

<pre>
      1 7
     /   \
    2     8
   /       \
  3         9
</pre>

### [Balanced Binary Tree](../tree-binary-balanced/README.md)
Type of binary tree in which the difference between the height of the left and the right subtree for each node is either 0 or 1

<pre>
       1     df = 1
      / \
     2   3   df = 0, df = 0
    /\   
   4  5      df = 0, df = 0
</pre>
