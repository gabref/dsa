# Insertion Sort

## Cost


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
