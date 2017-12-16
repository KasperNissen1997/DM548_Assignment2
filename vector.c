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
    vector->top = 0;
    vector->size = 0;
    free(vector->data);
}

// Insert a new element at the end of the vector
// Pre: 'vector' != NULL
void vector_push(Vector *vector, void *value) {
    if (vector->top == vector->size) {
        vector->size *= 2;
        realloc(vector->data, sizeof(void*) * vector->size);
    }
    
    vector->data[vector->top] = value;
    vector->top++;
}

// Remove the last element in the vector and return the value
// Pre: the vector is non-empty, 'vector' != NULL
void* vector_pop(Vector *vector) {


    vector->top--;
    return vector->data[vector->top];
}

// Return the number of elements in the vector
// Pre: 'vector' != NULL
size_t vector_size(const Vector *vector) {
    return vector->top;
}

// Return the current capacity of the vector
// Pre: 'vector' != NULL
size_t vector_capacity(const Vector *vector) {
    return vector->size;
}

// Return the value at the given index
// Pre: index < vector_size(vector)
void* vector_get_element(const Vector *vector, size_t index) {
    return vector->data[index];
}

// Return a pointer to the underlying array
void** vector_get_array(const Vector *vector) {
    return (vector->data);
}

// TEMP METHOD - REMOVE WHEN DONE
// Tries to push an integer to the given vector
void testVector(Vector *vector, int testData) {
    printf("Pushing %i to the given vector...\n", testData);

    void* pTest = (void*) testData;
    vector_push(vector, pTest);

    if (vector->data[vector->top - 1] == pTest) {
        printf("The push was succesfull!\n\n");
    } else {
        printf("The push was NOT succesfull...\n\n");
    }
}


// TEMP METHOD - REMOVE WHEN DONE
// Performs various tests to check the programs functionality
int main() {
    Vector v;
    Vector *pv = &v;

    vector_init(pv);

    testVector(pv, 12);
    testVector(pv, 15);
    testVector(pv, 8);
    testVector(pv, 22);
    testVector(pv, 12);
    testVector(pv, 15);
    testVector(pv, 8);
    testVector(pv, 22);
    testVector(pv, 12);
    testVector(pv, 15);
    testVector(pv, 8);
    testVector(pv, 22);

    for (int i = pv->top; i > 1; i--) {
        printf("Popping: %i...\n", vector_pop(pv));
    }

    printf("Capacity, Size: %i, %i...\n", vector_capacity(pv), vector_size(pv));

    return (0);
}