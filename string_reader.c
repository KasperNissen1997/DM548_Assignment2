#include <stdio.h>
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
    void *buffer = 0;
    char *line = NULL;

    Vector v;
    Vector *pv = &v;

    vector_init(pv);

    while ((getline(&line, &buffer, pFile)) != -1) {
        printf(line);

        vector_push(pv, &line);
    }

    printf("\n");

    for (int i = pv->top; i > 0; i--) {
        printf("Popping: %s...\n", vector_pop(pv));
    }
    
    printf("Done mah nignog");

    fclose(pFile);
    if (line)
        free(line);

    return 0;
}