# Perfect Binary Tree

A perfect binary tree is a type of binary tree in which every internal node has exactly two child nodes and all the leaf nodes are at the same level.

* All the internal nodes have a degree of 2

1. If a single node has no children, it is a perfect binary tree of height $h = 0$ 
2. If a node has $h > 0$, it is a perfect binary tree if both of its subtrees are of height $h - 1$ and are non-overlapping

## Theorems

$nodes = n = 2^{h + 1} - 1$

<br>

$height = h = \log(n + 1) - 1 = \Theta(\ln(n))$

<br>

$leaf nodes = l = 2^h$

<br>

$average depth of a node = \Theta(ln(n))$

<br>

## Implementation

* [ ] calculate depth
* [ ] is perfect
