# Selecion Sort

Selection sort is a sorting algorithm that selects the smallest element from an unsorted list in each iteration and places that element at the beginning of the unsorted list.

Minimizes swap, but makes a lot of comparisons.

## Algorithm

1. set the first element as `minimum`
2. compare `minimum` with the second element. if the second element is smaller than `minimum`, assign the second element as `minimum`, until the last element.
3. after each iteration, `minimum` is placed in the front of the unsorted list
4. for each iteration, indexing starts from the first unsorted element. step 1 to 3 are repeated until all the elements are placed at their correct positions

## Implementation

```python
def selectSort(a):
    for k from 0 included to len(a) excluded:

        # find the smalledst element in a[k:END] and swap it into a[k]
        iMin = k
        for j from iMin + 1 included to len(a) excluded:
            if a[j] < a[iMin]:
                iMin = j
        swap(a[k], a[iMin])
```

## Selection Sort Complexity

| Time Complexity | |
| :--- | :---: |
| Best | O(n^2) |
| Worst | O(n^2) |
| Average | O(n^2) |
| Space Complexity | O(1) |

### Complexity in Detail

| Cycle | Number of Comparisons |
| :--- | :---: |
| 1st | (n - 1) |
| 2st | (n - 2) |
| 3st | (n - 3) |
| ... | ... |
| last | (n - 2) |

$(n - 1) + (n - 2) + (n - 3) + ... + 1 = n (n - 1) / 2$

## Applications

* a small list is to be sorted
* cost of swapping does not matter
* checking of all the elements is compulsory
* cost of writing to a memory matters like in flash memory (number of writes/swaps is O(n) as compared to O(n^2) of bubble sort)

