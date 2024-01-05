#pragma once

#ifndef _UTIL_H
#define _UTIL_H

#include <string.h>
#include <malloc.h>
#include <sys/mman.h>

#ifndef MAP_ANON
#define MAP_ANON 0x20
#endif

void resize(void** addr, size_t size);
void Realloc(void* _add, size_t size);
void* GetMem(void* data, size_t len);
void SaveMem(void* _addr, char* val, size_t len);
void printArr(char* arr, int len);

#endif