#include <stdio.h>
#include <string.h>
#include "vector.h"

/*
int main (char *argc, char* argv[]) {
    char const* const fileName = argv[1];
    FILE* file = fopen(fileName, "r");
    char line[256];
    
    Vector v;
    vector_init(&v);

    while(fgets(line, sizeof(line), file)){
        vector_push(&v, &line); 
    }

    printf("%s", (char*) v.data[v.top]);
    
    while(vector_size(&v)){
        printf("%s", (char*) vector_pop(&v));
    }

    fclose(file);

    return 0;
}
*/

int main(char *argc, char* argv[]) {
    FILE *pFile = fopen(argv[1], "r");
    size_t *buffer = (size_t) 0;
    char *line = NULL;

    Vector v;
    Vector *pv = &v;

    vector_init(pv);

    while ((getline(&line, &buffer, pFile)) != -1) {


        vector_push(pv, (void *) assignNewStringPointer(line));

        printf("Getting element at [0]: %s", vector_get_element(pv, 0));
    }

    for (int i = pv->top; i > 0; i--) {
        printf("Popping: %s", (char *) vector_pop(pv));
    }
    
    printf("Done mah nignog");

    fclose(pFile);
    if (line)
        free(line);

    return 0;
}

void assignNewStringPointer(char *line) {
    void *newLine = malloc(strlen(line) + 1);
    memcpy(newLine, line, strlen(line));
    return newLine;
}