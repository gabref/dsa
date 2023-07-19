#include "test.h"
#include "hash.h"

void run_all_tests() {
    printf("\nBEGIN TESTS\n\n");

    ghash * table = ghash_create(10);

    assert(ghash_exists(table, "bottle") == 0);
    assert(ghash_exists(table, "ciao") == 0);

    ghash_add(table, "bottle", "garrafa");
    ghash_add(table, "hello", "oi");
    ghash_add(table, "bye", "tchau");
    ghash_add(table, "oil", "azeite");
    ghash_add(table, "person", "pessoa");
    ghash_add(table, "programmer", "programador");
    ghash_add(table, "engeneer", "engenheiro");
    ghash_add(table, "queue", "fila");
    ghash_add(table, "stack", "pilha");
    ghash_add(table, "keyboard", "teclado");
    ghash_add(table, "cup", "copo");
    ghash_add(table, "device", "dispositivo");

    ghash_print(table);

    assert(ghash_exists(table, "bottle") == 1);
    assert(ghash_exists(table, "ciao") == 0);

    assert(strcmp(ghash_get(table, "bottle"), "garrafa") == 0);
    assert(strcmp(ghash_get(table, "hello"), "oi") == 0);
    assert(strcmp(ghash_get(table, "person"), "pessoa") == 0);
    assert(strcmp(ghash_get(table, "han"), "pessoa") != 0);

    ghash_remove(table, "person");
    ghash_remove(table, "bottle");

    ghash_print(table);

    assert(strcmp(ghash_get(table, "person"), "pessoa") != 0);

    ghash_destroy(table);

    printf("\nAll tests ok\n\n");
}
