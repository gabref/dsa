#include "test.h"
#include "insertion-sort.h"

void run_all_tests() {
    int arr[6] = {8, 7, 2, 4, 10, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, size);
    insertion_sort(arr, size);
    print_array(arr, size);
}
