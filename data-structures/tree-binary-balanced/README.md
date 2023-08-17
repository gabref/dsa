
# Balanced Binary Tree

A balanced binary tree, also referred to as a height-balanced binary tree, is defined as a binary tree in which the height of the left and right subtree of any node differ by not more than 1

1. differencebetween the left and the right subtree for any node is not more than on
2. the left subtree is balanced
3. the right subtree is balanced

<pre>
             1    df = 1
            / \
df = 0     2   3  df = 0
          / \
df = 0   4   5    df = 0
</pre>

<pre>
             1    df = 2
            / \
df = 1     2   3  df = 0
          / \
df = 0   4   5    df = 1
            /
           6      df = 0
</pre>
