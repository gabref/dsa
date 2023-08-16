# Tree Data Structure

## Terminology

### Node
A node is an entity that contains a key or value and pointers to its child nodes <br/>
The last nodes of each path are called **leaf nodes** or **external nodes** that do not contain a link/pointer to child nodes
The node having at least a child node is called an **internal node**

### Edge
It is the link between any two nodes

### Root
It is the topmost node of a tree

### Height of a Node
The height of a node is the number of edges from the node to the deepest leaf

### Depth of a Node
The depth of a node is the number of edges from the root to the node

### Height of a tree
The height of a tree is the height of the root node or the depth of the deepest node

### Degree of a node
The degree of a node is the total number of branches of that node

### Forest
A collection of disjoint trees is called a forest

## Tree Traversal

Traversing a tree means visiting every nodes in the tree

### Inorder traversal
1. visit all the nodes in the left subtree
2. visit the root node
3. visit all the nodes in the right subtree

### Preorder traversal
1. visit the root node
2. visit all the nodes in the left subtree
3. visit all the nodes in the right subtree

### Postorder traversal
1. visit all the nodes in the left subtree
2. visit all the nodes in the right subtree
3. visit the root node
