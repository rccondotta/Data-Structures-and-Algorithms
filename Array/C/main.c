#include <stdio.h>
#include <stdlib.h>

// Simple Implementation
typedef struct {
    int* data;
    int len;
    int cap;
} MyArray;

// creates a new array with a given initial capacity
MyArray* my_array_create(int initial_cap) {
    MyArray* arr = (MyArray*)malloc(sizeof(MyArray));
    arr->data = (int*)malloc(initial_cap * sizeof(int));
    arr->len = 0;
    arr->cap = initial_cap;
    return arr;
}

// destroys an array, deallocating its memory
void my_array_destroy(MyArray* arr) {
    free(arr->data);
    free(arr);
}

// adds an element to the end of the array
void my_array_push_back(MyArray* arr, int x) {
    if (arr->len == arr->cap) {
        arr->cap *= 2;
        arr->data = (int*)realloc(arr->data, arr->cap * sizeof(int));
    }
    arr->data[arr->len++] = x;
}

// removes the last element of the array
void my_array_pop_back(MyArray* arr) {
    if (arr->len > 0) {
        arr->len--;
    }
}

// returns the element at a given index
int my_array_get(MyArray* arr, int idx) {
    return arr->data[idx];
}

// returns the size of the array
int my_array_size(MyArray* arr) {
    return arr->len;
}

// returns the capacity of the array
int my_array_capacity(MyArray* arr) {
    return arr->cap;
}

int main() {
    MyArray* arr = my_array_create(2);
    my_array_push_back(arr, 1);
    my_array_push_back(arr, 2);
    my_array_push_back(arr, 3);

    for (int i = 0; i < my_array_size(arr); i++) {
        printf("%d ", my_array_get(arr, i));
    }
    printf("\n");

    my_array_pop_back(arr);
    for (int i = 0; i < my_array_size(arr); i++) {
        printf("%d ", my_array_get(arr, i));
    }
    printf("\n");

    my_array_destroy(arr);
    return 0;
}
