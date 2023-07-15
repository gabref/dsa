#include "test.h"
#include "insertion-sort.h"

void run_all_tests() {
    printf("\n");

    int arr1[6] = {8, 7, 2, 4, 10, 3};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[1] = {8};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[10] = {8, -7, 3, 3, -4, 25, 30, 3, 4, 4};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    print_array(arr1, size1);
    insertion_sort(arr1, size1);
    print_array(arr1, size1);

    printf("\n");

    print_array(arr2, size2);
    insertion_sort(arr2, size2);
    print_array(arr2, size2);

    printf("\n");

    print_array(arr3, size3);
    insertion_sort(arr3, size3);
    print_array(arr3, size3);

    printf("\n");
}
