#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vector.h"

// Compares two strings against each other 
int myStrCmp(const void *str1, const void *str2) 
{
    // Creates pointers for use in the 'strcmp' method
    const char **pStr1 = (const char **)str1;
    const char **pStr2 = (const char **)str2;

    // Returns:
    //   < 0; if pStr1 is less than pStr2,
    //   == 0; if pStr1 is equal to pStr2,
    //   > 0; if pStr1 is greater than pStr2
    return strcmp(*pStr1, *pStr2); 
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

    // Reads lines from the file at the 'pFile' and pushes them to the vector 'v' at 'pv'
    while ((getline(&line, &buffer, pFile)) != -1) {
        vector_push(pv, (void *) assignNewStringPointer(line));
    }

    // Closes the stream from the file at 'pFile'
    fclose(pFile);

    // Releases memory if there is some memory left allocated in 'line'
    if (line)
        free(line);

    // Sorts the vector lexicographically by utilizing 'myStrCmp'
    qsort(vector_get_array(pv), pv->top, sizeof(char *), myStrCmp);

    // Prints out all the elements in the vector 'v' at 'pv'
    for (int i = 0; i < pv->top; i++) {
        printf("%s", vector_get_element(pv, i));
    }

    // Return 0 to indicate a succesfull main call
    return 0;
}

// Gives the string found at the given address its own address
void assignNewStringPointer(char *line) {
    // Asserts enough memory for the entirity of the next string to be read
    // TODO: Explain why a single extra byte is added
    void *newLine = malloc(strlen(line) + 1);
    // void *newLine = malloc(sizeof(char) * 256);

    // Copies the contents of the 'line' address to the new address at 'newLine'
    memcpy(newLine, line, strlen(line) + 1);
    // memcpy(newLine, line, sizeof(char) * 256);

    // Returns the new address
    return newLine;
}