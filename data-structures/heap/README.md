# Heap

A heap is a complete binary tree that satisfies the heap property, where any given node is:
* always **greater** than its child node/s and the key of the root node is the **largest** among all the nodes. **Max Heap**
* always **smaller** than its child node/s and the key of the root node is the **smallest** among all the nodes. **Min Heap**

## Max heap
      9
     / \
    5   4
   / \   \
  1   3   2

## Min heap
      1
     / \
    2   3
   / \   \
  4   5   9

## Operations

### Heapify
Heapify is the process of creating a heap from a binary tree.

1. let the input array be [3, 9, 2, 1, 4, 5]
2. create a complete binary tree
          3
         / \
        9   2
       / \   \
      1   4   5
3. start from the first index of non-leaf node whose index is given by n/2 - 1
4. set the current element i as the largest
5. the index of left child is given by `2i + 1` and the right child is given by `2i + 2`. If leftChild is greater than currentElement, set leftChildIndex as largest. if rightChild is greater than element in largest, set rightChildIndex as largest
6. swap largest with currentElement
          3
         / \
        9   5
       / \   \
      1   4   2
7. repeat 3-7 until the subtrees are heapified

## Algorithm
```c
heapify(array, size, i)
    set i as largest
    leftChild = 2i + 1
    rightChild = 2i + 2
    
    if leftChild > array[largest]
        set leftChildIndex as largest
    if rightChild > array[largest]
        set rightChildIndex as largest

    swap array[i] and array[largest]

MaxHeap(array, size)
    loop from the first index of non-leaf node down to zero
        call heapify
```

### insert
```c
if there is no node
    create a newNode
else (a node is already present)
    insert the newNode at the end (last node from left to right)

heapify the array
```

### delete
```c
if nodeToBeDeleted is the leafNode
    remove the node
else swap nodeToBeDeleted with the lastLeafNode
    remove noteToBeDeleted

heapify the array
```

### peek (max/min)
```c
return rootNode
```
