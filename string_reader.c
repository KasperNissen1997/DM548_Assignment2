#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vector.h"

/*void myArrSort(Vector *v) {
    void data = vector_get_array(v);

    for (int size = vector_size(v); size > 0; size--) {
        data[size]
    }
}*/

/* qsort C-string comparison function */ 
int cstring_cmp(const void *a, const void *b) 
{ 
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib); 
}

int main(int *argc, char *argv[]) {
    // Opens the file, asserts memory for the filebuffer and -
    // prepares an address for the read files to be stored at
    FILE *pFile = fopen(argv[1], "r");
    size_t *buffer = (size_t) 0;
    char *line = NULL;

    // Constructs the to-be-utilized vector
    Vector v;
    // Stores the address of the newly constructed vector
    Vector *pv = &v;

    // Initializes the newly constructed vector
    vector_init(pv);

    while ((getline(&line, &buffer, pFile)) != -1) {
        vector_push(pv, (void *) assignNewStringPointer(line));
        
        // TODO: Delete this, meant for testing only
        // printf("Getting element at [0]: %s", vector_get_element(pv, 0));
    }

    // TODO: Delete this, meant for testing only
    for (int i = pv->top; i > 0; i--) {
        printf("Element at [%i]: %s", i - 1, (char *) vector_get_element(pv, i - 1));
    }

    qsort(vector_get_array(pv), pv->top, sizeof(char *), cstring_cmp);

    // TODO: Delete this, meant for testing only
    for (int i = pv->top; i > 0; i--) {
        printf("Element at [%i]: %s", i - 1, (char *) vector_get_element(pv, i - 1));
    }

    fclose(pFile);

    if (line)
        free(line);

    return 0;
}

// Gives the string found at the given address its own address
void assignNewStringPointer(char *line) {
    // Asserts enough memory for the entirity of the next string to be read
    // TODO: Explain why a single extra byte is added
    void *newLine = malloc(strlen(line) + 1);
    // void *newLine = malloc(sizeof(char) * 256);

    // Copies the contents of the 'line' address to the new address at 'newLine'
    memcpy(newLine, line, strlen(line));
    // memcpy(newLine, line, sizeof(char) * 256);

    // Returns the new address
    return newLine;
}