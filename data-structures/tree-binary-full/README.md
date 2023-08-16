# Full Binary Tree

A full binary tree is a type of binary tree in which every parent node/internal node has either two or no children

It is also known as **a proper binary tree**

<pre>
       1
      / \
     2   3
    / \
   4   5
      / \
     6   7
</pre>

## Full Binary Tree Theorems
<pre>
i = number of internal nodes
n = total number of nodes
l = number of leaves
$\lambda$ = number of levels
</pre>

1. The number of leaves is $i + 1$
2. The total number of nodes is $2i + 1$
3. The number of internal nodes is $\frac{(n - 1)}{2}$
4. The number of leaves is $\frac{n + 1}{2}$
5. The total number of nodes is: $2l - 1$
6. The number of internal nodes is $l - 1$
7. The number of leaves is at most $2^{\lambda - 1}$

<br>

$ l = i + 1 $

<br>

$ n = 2i + 1 $

<br>

$i = \frac{n - 1}{2}$

<br>

$l = \frac{n + 1}{2}$

<br>

$n = 2l - 1$

<br>

$i = l - 1$

<br>

$l = 2^{\lambda - 1}$
