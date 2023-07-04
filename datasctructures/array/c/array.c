#include "array.h"
#include <stdio.h>
#include <stdlib.h>

garray * garray_new(int capacity) {
    int true_capacity = garray_determine_capacity(capacity);
    garray *new_garray = (garray *) malloc(sizeof(garray));

    if (new_garray == NULL) {
        exit(EXIT_FAILURE);
    }

    int * new_data = (int *) malloc(sizeof(int) * true_capacity);

    new_garray->size = 0;
    new_garray->capacity = true_capacity;
    new_garray->data = new_data;

    return new_garray;
}

int garray_size(garray *arr) { return arr->size; }

int garray_capacity(garray *arr) { return arr->capacity; }

int garray_is_empty(garray * arr) {
    return arr->size == 0 ? 0 : 1;
}

void garray_destroy(garray *arr) {
    free(arr->data);
    free(arr);
}

void garray_push(garray * arr, int value) {
    garray_resize_for_size(arr, arr->size + 1);
    *(arr->data + arr->size) = value;
    arr->size++;
}

void garray_insert(garray * arr, int index, int value) {
    if (index < 0 || index >= arr->size) {
        fprintf(stderr, "Index out of bound\n");
        exit(EXIT_FAILURE);
    }
    garray_resize_for_size(arr, arr->size + 1);
    arr->size++;
    int i;
    for (i = arr->size - 1; i > index; i--)
        *(arr->data + i) = *(arr->data + i - 1);
    *(arr->data + i) = value;
}

void garray_prepend(garray * arr, int value) {
    garray_insert(arr, 0, value);
}

int garray_pop(garray * arr) {
    if (arr->size == 0) {
        fprintf(stderr, "Array empty\n");
        exit(EXIT_FAILURE);
    }
    int popped_value = *(arr->data + arr->size - 1);
    garray_resize_for_size(arr, arr->size - 1);
    arr->size--;
    return popped_value;
}

void garray_delete(garray * arr, int index) {
    // check if index is invalid
    if (index < 0 || index >= arr->size) {
        fprintf(stderr, "Index out of bound\n");
        exit(EXIT_FAILURE);
    }
    // shift elements to left
    for (int i = index; i < arr->size - 1; i++)
        *(arr->data + i) = *(arr->data + i + 1);
    // resize for size
    garray_resize_for_size(arr, arr->size - 1);
    // decrement size
    arr->size--;
}

void garray_remove(garray * arr, int value) {
    // loop through all array
    for (int i = 0; i < arr->size; i++) {
        if (*(arr->data + i) == value) {
            garray_delete(arr, i);
            i--; // recheck index that was deleted
        }
    }
}

int garray_find(garray * arr, int value) {
    for (int i = 0; i < arr->size; i++) {
        if (*(arr->data + i) == value) {
            return i;
        }
    }
    return -1;
}

int garray_at(garray * arr, int index) {
    if (index < 0 || index >= arr->size) {
        fprintf(stderr, "Index out of bound\n");
        exit(EXIT_FAILURE);
    }
    return *(arr->data + index);
}

void garray_print(garray * arr) {
    printf("\n**** Current Array ****\n");
    printf("Size: %d\n", arr->size);
    printf("Capacity: %d\n", arr->capacity);
    printf("Items: [");
    for (int i = 0; i < arr->size; i++) {
        printf("%d", *(arr->data + i));
        if (i != arr->size - 1) printf(", ");
    }
    printf("]\n");
}

// =================
// ===== UTILS =====
// =================

int garray_determine_capacity(int capacity) {
    if (capacity < K_MIN_CAPACITY) {
        fprintf(stderr, "Capacity cannot be less then K_MIN_CAPACITY: %d\n", K_MIN_CAPACITY);
        exit(EXIT_FAILURE);
    }
    int new_capacity = K_MIN_CAPACITY;
    while (capacity > new_capacity)
        new_capacity *= K_GROWTH;
    return new_capacity;
}

void garray_upsize(garray * arr) {
    int new_true_capacity = garray_determine_capacity(arr->capacity + 1);
    int *new_data = (int *) realloc(arr->data, sizeof(int) * new_true_capacity);
    check_address(new_data);
    arr->data = new_data;
    arr->capacity = new_true_capacity;
}

void garray_downsize(garray * arr) {
    int old_capacity = arr->capacity;
    int new_true_capacity = old_capacity / K_SHRINK;

    if (new_true_capacity < K_MIN_CAPACITY)
        new_true_capacity = K_MIN_CAPACITY;

    if (new_true_capacity != old_capacity) {
        int *new_data = (int *) realloc(arr->data, sizeof(int) * new_true_capacity);
        check_address(new_data);
        arr->data = new_data;
        arr->capacity = new_true_capacity;
    }
}

void garray_resize_for_size(garray *arr, int candidate_size) {
    if (arr->size < candidate_size) { // growing
        if (arr->size == arr->capacity)
            garray_upsize(arr);
    }
    else if (arr->size > candidate_size) // shrinking
        if (arr->size == arr->capacity / K_SHRINK)
            garray_downsize(arr);
    // if capacity == candidate_size do nothing
}

void check_address(void *arr) {
    if (arr == NULL) {
        fprintf(stderr, "Failed to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    return;
}
