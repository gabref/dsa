# Selecion Sort

Minimizes swap, but makes a lot of comparisons.

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
