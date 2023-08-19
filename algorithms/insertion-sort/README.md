# Insertion Sort

Insertion sort is a sorting algorithm that places an unsorted element at its suitable place in each iteration

Insertion sort works similarly as we sort cards in our hand in a card game

we assume that the first card is already sorted then, we select an unsorted card. if the unsorted card is greater than the card in hand, it is placed on the right otherwise, to the left. in the same way, other unsorted cards are taken and put in their right place.

a similar approach is used by insertion sort

## Algorithm
1. the first element in the array is assumed to be sorted. take the second element and store it separately in key
    1. compare key with the first element. if the first element is greater than key, then key is placed in front of the first element
2. take the third element and compare it with the elements on the left of it. placed it just behind the element smaller than it. if there is no element smaller than it, then place it at the beginning of the array
3. similarly , place every unsorted element at its correct position 


## Implementation

```python
def insertSort(a):
    """BEHAVIOUR: run the algorithm on the integer array a, sorting it in place

    PRCONDITION: array a contains len(a) integer values

    POSCONDITION: array a contains the same integer values as before, but now they are sorted in ascending order """

    for i from 1 included to len(a) excluded:
        # ASSERT: the first i positions are already sorted
        # insert a[i] where it belongs withinn a[0:1]
        j = i - 1
        while j >= 0 and a[j] > a[j + 1]:
            swap(a[j], a[j + 1])
            j = j - 1
```

```python
def insertSort(a):
    for i from 1 included to len(a) excluded:
        key = a[i]
        # ASSERT: the first i positions are already sorted
        # insert a[i] where it belongs withinn a[0:1]
        j = i - 1
        while j >= 0 and a[j] > key:
            a[j + 1] = a[j]
            j = j - 1
        a[j + 1] = key
```

## Insertion Sort Complexity

| Time Complexity | |
| :--- | :---: |
| Best | O(n) |
| Worst | O(n^2) |
| Average | O(n^2) |
| Space Complexity | O(1) |

## Applications

* the array has a small number of elements
* there are only a few elements left to be sorted
