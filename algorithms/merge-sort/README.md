# Merge Sort

Merge Sort is one of the most popular sorting algorithms that is based on the principle of Divide and Conquer Algorithm.

Here, a problem is divided into multiple sub-problems. Each sub-problems is solved individually. Finally, sub-problems are combined to form the final solution.

## Merge Sort Algorithm

```c
MergeSort(A, p, r):
    if p > r
        return
    q = (p + r) / 2
    mergeSort(A, p, q)
    mergeSort(A, q + 1, r)
    merge(A, p, q, r)
```

### The merge step of merge sort

* Have we reached the end of any of the arrays?
    1. No
        * compare current elements of both arrays
        * copy smaller element into sorted array
        move pointer of element containing smaller element
    2. Yes
        * copy all remaining elements of non-empty array

### algorithm
1. create copies of the subarrays `L <- A[p:q]` `M <- A[q + 1: r]`
2. create 3 pointers i, j and k
    a. `i` maintains current index of `L`, starting at 1
    b. `j` maintains current index of `M`, starting at 1
    c. `k` maintains current index of `A[p:q]`, starting at p
3. until we reach the end of either `L` or `M`, pick the larger among the elements from `L` and `M` and place them in the correct position at `A[p:q]`
4. when we run out of elements in either `L` or `M`, pick up the remaining elements and put in `A[p:q]`

## Implementation

```c
#include <stdio.h>

// merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
    // create L = A[p:q], M = A[q+q:r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];

    for (int j = 0; j < n2; j++)
        M[j] = A[q + j + 1];

    // maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // until we reach either end of either L or M, pick larger among 
    // elements L and M and place them in the correct position at A[p:r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // when we run out of elements in either L or M
    // pick up the remaining elements and put in A[p:r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) 
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {7, 3, 12, 4, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    printf("Sorted array: \n");
    printArray(arr, size);

    return 0;
}
```


```python
def mergeSort(array):
    if len(array) > 1:

    # r is the point where the array is divided into two subarrays
    r = len(array) // 2
    L = array[:r]
    M = array[r:]

    # sort the two halves
    mergeSort(L)
    mergeSort(M)

    i = j = k = 0

    # until we reach either end of either L or M, pick larger among 
    # elements L and M and place them in the correct position at A[p:r]
    while i < len(L) and j < len(M):
        if L[i] < M[j]:
            array[k] = L[i]
            i += 1
        else:
            array[k] = M[j]
            j += 1
        k += 1

    # when we run out of elements in either L or M,
    # pick up the remaining elements and put in A[p:r]
    while i < len(L):
        array[k] = L[i]
        i += 1
        k += 1
    while i < len(M):
        array[k] = M[j]
        j += 1
        k += 1

def printList(array):
    for i in range(len(array)):
        print(array[i], end=' ')
    print()

if __name__ == '__main__':
    array = [6, 5, 12, 10, 9, 1]
    mergeSort(array)
    printList(array)
```

## Insertion Sort Complexity

| Time Complexity | |
| :--- | :---: |
| Best | O(n * log n) |
| Worst | O(n * log n) |
| Average | O(n * log n) |
| Space Complexity | O(n) |

## Applications

* inversion count problem
* external sorting
* e-commerce applications
