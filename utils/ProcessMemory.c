#include "ProcessMemory.h"

struct ProcessMemory { void* addr; size_t size; };

ProcessMemory* CreateProcessMemory(void* addr, size_t size) {
    return memcpy(malloc(sizeof(ProcessMemory)), (ProcessMemory*) { addr, size }, sizeof(ProcessMemory));
}

void Resize(ProcessMemory* mem, int size) {
    resize(&mem->addr, size);
    mem->size = size;
};

void FreeProcessMemory(ProcessMemory* mem) {
    free(mem->addr);
    free(mem);
}


