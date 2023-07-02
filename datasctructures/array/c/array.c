#include "array.h"
#include <stdio.h>
#include <stdlib.h>

garray * garray_new(int capacity) {
    fprintf(stderr, "testando mensagem erro\n");

    garray *new_garray = (garray *) malloc(sizeof(garray));

    if (new_garray == NULL) {
        exit(EXIT_FAILURE);
    }

    return new_garray;
}
