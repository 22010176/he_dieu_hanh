#include "utils.h"

void resize(void** addr, size_t size) {
    void* a = *addr;
    do a = realloc(a, size); while (!a);
    *addr = a;
}

void* GetMem(void* data, size_t len) {
    void* _add = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED | 0x20, 0, 0); memcpy(_add, data, len);
    return _add;
}
void SaveMem(void* _addr, char* val, size_t len) {
    memcpy(_addr, val, len);
    munmap(_addr, len);
}
void printArr(char* arr, int len) {
    for (int i = 0; i < len; i++) printf("%-4x ", arr[i]);
    printf("\n");
}

void Realloc(void* _add, size_t size) {}