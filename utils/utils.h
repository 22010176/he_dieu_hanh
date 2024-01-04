#pragma once

#ifndef _UTIL_H
#define _UTIL_H

#include <stdlib.h>

#ifndef MAP_ANON
#define MAP_ANON 0x20
#endif

void resize(void** addr, size_t size);

#endif