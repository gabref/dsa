# Binary Search Tree

Binary search tree is a datastructure that quickly allows us to maintain a osrted list of numbers.
1. it is called a binary tree because each tree node has a maximum of two children
2. it is called a search tree because it can be used to earch for the presence of a number in $O(\log(n))$ time.

1. All nodes of left subtree are less than the root node
2. All nodes of right subtree are more than the root node
3. Both subtrees of each node are also BST

<pre>
        8
       / \
      3   10
     / \
    1   6
       /
      4
</pre>
- [x] BST

<pre>
        8
       / \
      3   10
     / \
    1   6
       /
      2
</pre>
- [ ] BST

## Algorithm

### search

```c
if root == NULL
    return NULL;
if number == root->data
    return root->data
if number < root->data
    return search(root->left)
if number > root->data
    return search(root->right)
```

### insert
```c
if node == NULL
    return createNode(data)
if (data < node->data)
    node->left = insert(node->left, data)
if (data > node->data)
    node->right = insert(node->right, data)
return node;
```

### deletion
1. node to delete is a leaf
Simply delete the leaf node from the tree

2. node to be deleted, has a single child node
    1. replace that node with its child node
    2. remove the child node from its original position

3. node to be deleted has two children
    1. get the inorder successor of that node
    2. replace the node with the inorder successor
    3. remove the inorder successor from its original position
