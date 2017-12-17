#include <stdio.h>
#include "vector.h"

int main (char *argc, char* argv[]){
    char const* const fname = argv[1];
    FILE* file = fopen(fname, "r");
    char line[256];
    char lines[1000][256];
    
    int count=0;


    Vector v;
    vector_init(&v);

    while(fgets(line,sizeof(line), file)){
        char* pntr=linemem(line);
        vector_push(&v, pntr); 
    }

    
    while(vector_size(&v)){
        printf("%s", (char*) vector_pop(&v));
    }

    fclose(file);

    return 0;

}


    void linemem(char* line){
        void *a = malloc(sizeof(char*)*256);
        memcpy(a, line, sizeof(char*)*256);
        return a;
    }