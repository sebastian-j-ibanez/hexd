#include <stdlib.h>
#include <string.h>

#define CAPACITY_MULT 2

typedef struct DynamicArray {
    void* array;
    int length;
    size_t elem_size;
    int capacity;
} DynamicArray;

DynamicArray* new_dynamic_array(size_t elem_size, int capacity);

void* get(DynamicArray* d, int i);
int set(DynamicArray* d, int i, void* new_value);
int push_back(DynamicArray* d, void* new_value);
void* pop_back(DynamicArray* d);
int resize(DynamicArray* d);