#include "insertion-sort.h"

void insertion_sort(int * arr, int length) {
    for (int i = 1; i < length; i++) {
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[j + 1]) {
            // swap values
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            j--;
        }
    }
}

void print_array(int * arr, int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
