# AVL Tree
AVL tree is a self-balancing binary search tree in which each node maintains extra information called a balance factor whose value is either -1, 0 or +1.

AVL tree got its name after its inventor Georgy Adelson-Velsky and Landis.

## Balance Factor
Balance factor of a node in an AVL tree is the difference between the height of the left subtree and that of the right subtree of that node

Balance Factor = (height of left subtree - height of right subtree) or (height of right subtree - height of left subtree)

The self balancing property of an avl tree is maintained by the balance factor. The value of balance factor should always be -1, 0 or +1.

An example of a balanced avl tree is:
<pre>
        33         df = 1
       /  \
      9    53      df = -1, -1
     / \     \
    8   21    61   df = 0, 1, 0
       /
      11           df = 0
</pre>

# Operations on an AVL tree

## Rotating the subtrees in an AVL Tree

In rotation operation, the position of the nodes of a subtree are interchanged.
There are two types of rotations:

### Left Rotate
In left-rotation, th earrangement of the nodes on the right is transformed into the arragemenets on the left node.

### Algorithm
1. Let the initial tree be:
<pre>
        p
        |
       [X]
       / \
      a  [Y]
         / \
        b   y
</pre>

2. If y has a left subtree, assign x as the parent of the left subtree of y
<pre>
        p
        |
       [X]
       / \
      a   b  [Y]
               \
                y
</pre>

3. If the parent of x is NULL, make y as the root of the tree
4. Else if x is the left child of p, make y as the left child of p
5. else assign y as the right child of p
<pre>
       [X]       p
       / \       |
      a   b     [Y]
                  \
                   y
</pre>

6. Make y as the parent of x
<pre>
       p
       |
      [Y]
     /   \
    [X]   y
    / \
   a   b
</pre>

### Right Rotate
In right-rotation, the arrangement of the nodes on the left is transformed into the arragemenets on the right node.

### Algorithm
1. Let the initial tree be:
<pre>
        p
        |
       [Y]
       / \
      [X] a
      / \
     y   b
</pre>

2. If X has a left subtree, assign y as the parent of the right subtree of x
<pre>
        p
        |
       [Y]
       / \
      b   a  [X]
               \
                y
</pre>

3. If the parent of y is NULL, make x as the root of the tree
4. Else if y is the left child of p, make x as the left child of p
5. else assign x as the right child of p
<pre>
       [Y]       p
       / \       |
      b   a     [X]
                  \
                   y
</pre>

6. Make x as the parent of y
<pre>
       p
       |
      [Y]
     /   \
    y   [X]
        / \
       a   b
</pre>

## Algorithm to Insert a New Node

A `newNode` is always inserted as a leaf node with balance factor equal to 0
1. Let the initial tree be some state
2. go to the appropriate leaf node to insert a newNode usign the following recursive steps. 
    1. if `newKey < rootKey`, call insertion algorithm on the left subtree of the current node until the leaf node is reached
    2. if `newKey > rootKey`, call insertion algorithm on the right subtree of the current node until the leaf node is reached
    3. Else, return `leafNode`
3. compare `leafKey` obtained frm the above steps with `newKey`
    1. if `newKey < leafKey`, make newNode as the leftChild of leafNode
    2. else, make newNode as rightChild of leafNode
4. Update `balanceFactor` of nodes
5. If the nodes are unbalanced, then rebalance the node
    1. if `balanceFactor > 1`, it means the height of the left subtree is greater than that of the right subtree. So, do a right rotatio or left-right rotation
        1. if `newNodeKey < leftChildKey` do right rotation
        2. else, do left-right rotation
    2. if `balanceFactor < -1`, it means the height of the right subtree is greater than that of the left subtree. so, do right rotation or right-left rotation
        1. if `newNodeKey > rightChildKey` do left rotation
        2. else, do right-left rotation
6. The final tree is balanced

## Algorithm to Delete a node

A node is always deleted as a leaf node. After deleting a node, the balance factors of the nodes get changed. In order to rebalance the balance factor, suitable rotations are performed
1. Locate `nodeToBeDeleted` 
    1. if `nodeToBeDeleted` is the leaf node, then remove `nodeToBeDeleted`
    2. If `nodeToBeDeleted` has one child, the subtitute the contents of nodeToBeDeleted with that of the child. remove the child
    3. if `nodeToBeDeleted` has two children, find the inorder successor w of `nodeToBeDeleted` (node of minimun value of key in the right subtree)
        1. substitute the contents of `nodeToBeDeleted`with that of w
        2. remove the leaf node w
2. Update `balanceFactor` of the nodes
3. rebalance the tree if the balance factor of any of the nodes is not equal to -1, 0 or 1
    1. if `balanceFactor` of `currentNode > 1`
        1. if `balanceFactor`of `leftChild >= 0`, do right rotation
        2. else do left-right rotation
    2. if `balanceFactor` of `currentNode < -1`
        1. if `balanceFactor`of `rightChild >= 0`, do left rotation
        2. else do right-left rotation
