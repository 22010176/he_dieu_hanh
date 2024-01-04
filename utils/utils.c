#include "utils.h"

void resize(void** addr, size_t size) {
    void* a = *addr;
    do a = realloc(a, size); while (!a);
    *addr = a;
}

