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
    if (vector->top == vector->size - 1) {
        vector->size *= 2;
        vector->data = realloc(vector->data, sizeof(void*) * vector->size);
    }
    
    vector->data[vector->top] = value;
    vector->top++;
}

// Remove the last element in the vector and return the value
// Pre: the vector is non-empty, 'vector' != NULL
void* vector_pop(Vector *vector) {
    vector->top--;

    void* pTemp = vector_get_element(vector, vector->top);

    vector->data[vector->top] = NULL;

    return pTemp;
}

// Return the number of elements in the vector
// Pre: 'vector' != NULL
size_t vector_size(const Vector *vector) {
    return vector->top - 1;
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
// Pre: 'vector' != NULL
void** vector_get_array(const Vector *vector) {
    return vector->data;
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
/*
int main() {
    Vector v;
    Vector *pv = &v;

    vector_init(pv);

    for (int i = 0; i < 50; i++) {
        testVector(pv, i);
    }

    printf("Getting element at [8] from vector.data: %i\n", vector_get_element(pv, 8));
    printf("Capacity, Size: %i, %i...\n", vector_capacity(pv), vector_size(pv));

    for (int i = pv->top; i > 0; i--) {
        printf("Popping: %i...\n", vector_pop(pv));
    }

    return 0;
}
*/