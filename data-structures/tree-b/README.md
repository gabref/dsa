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

## Operations
1. starting from the root node, compare k with the first key of the node. if $k = the first key of the node$ return the node and the index
2. if $k.leaf = true$, return NULL (not found)
3. if $k < the first key of the root node$ search the left child of this key recursively
4. if there is more than one key in the current node and $k > the first key$, compare k with the next key in the node
    1. if $k < next key$, search the left child of this key (i.e. k lies in between the first and the second keys)
    2. else search the right child of the key
5. repeat spets 1 to 4 until the leaf is reached

```c
BTreeSearch(x, k)
i = 1
while i <= n[x] and k >= keyi[x]
    do i = i + 1
if i n[x] and k = keyi[x]
    then return (x, i)
if leaf [x]
    then return NIL
else
    return BTreeSearch(ci[x], k)
```

## Insertion

1. If the tree is empty, allocate a root node and insert the key.
2. Update the allowed number of keys in the node.
3. Search the appropriate node for insertion.
4. If the node is full, follow the steps below.
5. Insert the elements in increasing order.
6. Now, there are elements greater than its limit. So, split at the median.
7. Push the median key upwards and make the left keys as a left child and the right keys as a right child.
8. If the node is not full, follow the steps below.
9. Insert the node in increasing order.

```c
BreeInsertion(T, k)
r  root[T]
if n[r] = 2t - 1
    s = AllocateNode()
    root[T] = s
    leaf[s] = FALSE
    n[s] <- 0
    c1[s] <- r
    BtreeSplitChild(s, 1, r)
    BtreeInsertNonFull(s, k)
else BtreeInsertNonFull(r, k)
BtreeInsertNonFull(x, k)
i = n[x]
if leaf[x]
    while i ≥ 1 and k < keyi[x]
        keyi+1 [x] = keyi[x]
        i = i - 1
    keyi+1[x] = k
    n[x] = n[x] + 1
else while i ≥ 1 and k < keyi[x]
        i = i - 1
    i = i + 1
    if n[ci[x]] == 2t - 1
        BtreeSplitChild(x, i, ci[x])
        if k &rt; keyi[x]
            i = i + 1
    BtreeInsertNonFull(ci[x], k)
BtreeSplitChild(x, i)
BtreeSplitChild(x, i, y)
z = AllocateNode()
leaf[z] = leaf[y]
n[z] = t - 1
for j = 1 to t - 1
    keyj[z] = keyj+t[y]
if not leaf [y]
    for j = 1 to t
        cj[z] = cj + t[y]
n[y] = t - 1
for j = n[x] + 1 to i + 1
    cj+1[x] = cj[x]
ci+1[x] = z
for j = n[x] to i
    keyj+1[x] = keyj[x]
keyi[x] = keyt[y]
n[x] = n[x] + 1
```


## Deletion
[theory more here](https://www.programiz.com/dsa/deletion-from-a-b-tree)



