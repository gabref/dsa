# Bubble Sort

Bubble sort is a sorting algorithm that compares two adjacent elements and swaps them until they are in the intended order.

Just like the movement of air bubbles in the water that rise up to the surface, each element of the array move to the end in each iteration. Therefore, it is called a **bubble sort**.

## Algorithm

1. First Iteration (Compare and Swap)
    1. starting from the first index, compare the first and the second elements
    2. if the first element is greater than the second element, they are swapped
    3. now, compare the second and the third elements. swap them if they are not in order
    4. the above process goes on until the last element
2. Remaining iteration
    1. The same process goes on for the remaining iterations
        After each iteration, the largest element among the unsorted elements is placed at the end

```c
bubbleSort(array)
    for i < -1 to indexOfLastUnsortedElement - 1
        if leftElement > rightElement
            swap leftElement and rightElement
end bubbleSort
```

## Code

```c
#include <stdio.h>

void bubbleSort(int array[], int size) {
    // access each array element
    for (int step = 0; step < size; step++) {
        // loop to compare array elements
        for (int i = 0; i < size - step - 1; i++) {
            // compare two adjacent elements
            // change > to < to sort in descending order
            if (array[i] > array[i + 1]) {
                // swapping occurs if elements are not in the intended order
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

void printArray(int array[]; int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {-2, 45, 0, 11, -9};
    int size = sizeof(data) / sizeof(data[0]);

    bubbleSort(data, size);
    printArray(data, size);
}
```

## Optmized Bubble Sort

If the array is already sorted, no need to keep iterating. chech that by checking if there were any swapping

```c
void bubbleSort(int array[], int size) {
    // access each array element
    for (int step = 0; step < size; step++) {
        int swapped = 0;
        // loop to compare array elements
        for (int i = 0; i < size - step - 1; i++) {
            // compare two adjacent elements
            // change > to < to sort in descending order
            if (array[i] > array[i + 1]) {
                // swapping occurs if elements are not in the intended order
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}
```

## Bubble Sort Complexity

| Time Complexity | |
| :--- | :---: |
| Best | O(n) |
| Worst | O(n^2) |
| Average | O(n^2) |
| Space Complexity | O(1) |
| Optimed | O(2) |

### Complexity in Detail

| Cycle | Number of Comparisons |
| :--- | :---: |
| 1st | (n - 1) |
| 2st | (n - 2) |
| 3st | (n - 3) |
| ... | ... |
| last | (n - 2) |

$(n - 1) + (n - 2) + (n - 3) + ... + 1 = n (n - 1) / 2$

## Application
* complexity does not matter
* short and simple code is preferred
