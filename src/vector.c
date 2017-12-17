#include "vector.h"

// Initialize a vector to be empty
// Pre: 'vector' != NULL


/*
Initializes a vector with a size of ten, with an integer  pointing to its next empty space.
Allocates memory for as many void pointers as the size of the vector, void is used because it allows for 
*/
void vector_init(Vector *vector) {
    vector->top = 0;
    vector->size = 10;
    vector->data = malloc(sizeof(void*) * (vector->size));
}

// Deallocate internal structures of the vector
// Note: the user is responsible for deleting all values
// Note: the user is responsible for deleting the actual vector if it was dynamically allocated

/*
Frees the memory which is allocated to its pointers, and frees the memory which is allocated to its data, and lastly sets top and size to NULL as the data now is empty.
*/

void vector_delete(Vector *vector) {
    for (int i = vector->top; i > 0; i--) {
        free(vector->data[i]);
    }

    free(vector->data);

    vector->top = NULL;
    vector->size = NULL;
}

// Insert a new element at the end of the vector
// Pre: 'vector' != NULL

/*
Takes a pointer to a vector and a pointer to a value.
before adding the value it checks if the array has reached size - 1, which means there is no more space in the array,
 and the arrays size and allocated memory should be doubled by using realloc.
*/

void vector_push(Vector *vector, void *value) {
    if (vector->top == vector->size) {
        vector->size *= 2;
        vector->data = realloc(vector->data, sizeof(void*) * vector->size);
    }

    vector->data[vector->top] = NULL;
    
    vector->data[vector->top] = value;
    vector->top++;
}

// Remove the last element in the vector and return the value
// Pre: the vector is non-empty, 'vector' != NULL

/*
Decrements top and whereafter it makes a pointer with which points to the element at the index which top is at.
afterwards it nulls the current pointer of data and returns the newly created pointer.
*/

void* vector_pop(Vector *vector) {
    vector->top--;

    void* pTemp = vector_get_element(vector, vector->top);

    vector->data[vector->top] = NULL;

    return pTemp;
}

// Return the number of elements in the vector
// Pre: 'vector' != NULL

/*
returns the number of elements in the vector by returning top, as that has the value of the next index which is empty,
 and since the array is 0 indexed the amount of elements will be equal to top.
*/

size_t vector_size(const Vector *vector) {
    return vector->top;
}

// Return the current capacity of the vector
// Pre: 'vector' != NULL


/*
returns size which is the value which represents the capacity of the vector.
*/
size_t vector_capacity(const Vector *vector) {
    return vector->size;
}

// Return the value at the given index
// Pre: index < vector_size(vector)

/*
returns the value at the given index
*/

void* vector_get_element(const Vector *vector, size_t index) {
    return vector->data[index];
}

// Return a pointer to the underlying array
// Pre: 'vector' != NULL

/*
returns the array which data points to
*/

void** vector_get_array(const Vector *vector) {
    return vector->data;
}