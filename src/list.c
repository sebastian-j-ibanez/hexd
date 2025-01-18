#include "list.h"
#include <stdio.h>

DynamicArray* new_dynamic_array(size_t elem_size, int capacity) {
    DynamicArray* d = malloc(sizeof(DynamicArray));
    d->length = 0;
    d->elem_size = elem_size;
    d->array = malloc(elem_size * capacity);
    d->capacity = capacity;
    return d;
}

// Get the ith element of the array.
void* get(DynamicArray* d, int i) {
    if (d != NULL && i >= 0 && i < d->length) {
        return d->array + (i * d->elem_size);
    }

    return NULL;
}

// Set the ith element of the array to a new value.
int set(DynamicArray* d, int i, void* new_value) {
    if (d != NULL && new_value != NULL && i >= 0 && i < d->length) {
        memcpy(d->array + (i * d->elem_size), new_value, d->elem_size);
        return 0;
    }
    return -1;
}

// Push back a new value to the array.
int push_back(DynamicArray* d, void* new_value) {
    if (d == NULL || new_value == NULL) { return -1; }

    if (d->length == d->capacity) {
        resize(d);
    }

    printf("set: %d\n", set(d, d->length, new_value));
    d->length++;

    return 0;
}

// Remove and return last element from array.
void* pop_back(DynamicArray* d) {
    if (d->length > 0) {
        return get(d, d->length--);
    }

    return NULL;
}

// Resize dynamic array
int resize(DynamicArray* d) {
    d->capacity *= CAPACITY_MULT;
    void* new_array = realloc(d->array, d->elem_size * d->capacity);
    if (new_array == NULL) {
        d->capacity /= CAPACITY_MULT;
        return -1;
    }
    d->array = new_array;
    return 0;
}