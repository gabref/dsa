# B-tree

B-tree is a special type of self-balancing search tree in which each node can contain more than one key and can have more than two children. It is a generalized form of the [binary search tree](../tree-binary-search/)

It is also known as a height-balanced m-way tree

## B-tree properties
1. for each node x, the keys are stored in increasing order
2. in each node, there is aboolean value x.leaf
3. if n is the order of the tree, each internal node can contain at most $n - 1$ keys along with a pointer to each child
4. each node except root can have at most n children and at least n/2 children
5. all leaves have the same depth
6. the root has at least 2 children and contains a minimum of 1 key
7. if $n \get 1$, then for any n-key B-tree of height h and minimum degree $t \get 2$, $h \get \log_{t}{\frac{n + 1}{2}}$


