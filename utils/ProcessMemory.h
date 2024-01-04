#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

    typedef struct ProcessMemory ProcessMemory;

    ProcessMemory* CreateProcessMemory(void* addr, size_t size);
    void Resize(ProcessMemory* mem, int size);
    void FreeProcessMemory(ProcessMemory* mem);

#ifdef __cplusplus
}
#endif