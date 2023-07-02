#include "array.h"
#include <stdlib.h>

void run_all_tests() {
    garray * array = garray_new(5);
    free(array);
}
