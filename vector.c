#include "vector.h"

// Initialize a vector to be empty
// Pre: 'vector' != NULL
void vector_init(Vector *vector) {
    vector->top = 0;
    vector->size = 10;
    vector->data = malloc(sizeof(void*) * (vector->size));
}

// Deallocate internal structures of the vector
// Note: the user is responsible for deleting all values
// Note: the user is responsible for deleting the actual vector if it was dynamically allocated
void vector_delete(Vector *vector) {
    
}

// Insert a new element at the end of the vector
// Pre: 'vector' != NULL
void vector_push(Vector *vector, void *value) {
    if (vector->top == vector->size) {
        vector->size = vector->size * 2;
        realloc(vector->data, sizeof(void*) * vector->size);
    } 
    vector->data[vector->top] = value;
    vector->top++;
}

// Remove the last element in the vector and return the value
// Pre: the vector is non-empty, 'vector' != NULL
void *vector_pop(Vector *vector) {

}

// Return the number of elements in the vector
// Pre: 'vector' != NULL
size_t vector_size(const Vector *vector) {

}

// Return the current capacity of the vector
// Pre: 'vector' != NULL
size_t vector_capacity(const Vector *vector) {

}

// Return the value at the given index
// Pre: index < vector_size(vector)
void *vector_get_element(const Vector *vector, size_t index) {

}

// Return a pointer to the underlying array
void **vector_get_array(const Vector *vector) {
    return vector->data;
}

int main(){
    Vector v;
    vector_init(&v);
    vector_get_array(&v);
    
    }