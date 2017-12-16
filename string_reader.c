#include <stdio.h>
#include "vector.h"

int main (char *argc, char* argv[]){
    char const* const fname = argv[1];
    FILE* file = fopen(fname, "r");
    char line[256];
    
    Vector v;
    vector_init(&v);

    while(fgets(line,sizeof(line), file)){
        vector_push(&v, &line); 
    }


    while(vector_size(&v)){
        printf("%s", (char*) vector_pop(&v));
    }

    fclose(file);

    return 0;

}
