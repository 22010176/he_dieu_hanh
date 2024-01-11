#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <bits/mman-linux.h>
// #include "utils/utils.h"
#ifndef MAP_ANON
#define MAP_ANON 0x20
#endif
#define _p printf

bool lock = true;
int c = 90;
bool TestAndSet(bool* val) {
    bool temp = *val;
    *val = true;
    return temp;
}

void P(int i, void (*F)(), void(*f)()) {
    while (TestAndSet(&lock));
    F();
    lock = false;
    f();
}

void ChildProcess() {
    int* val = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, 0, 0);
    *val = 0;

    int pid = fork();

    wait(NULL);
    // printf("%d %d\n", pid, a);
    if (pid == 0) {
        printf("Child\n");
        *val = 10;
        printf("con: %d\n", *val);
    }
    else if (pid > 0) {
        wait(NULL);
        // _p("%d\n", *val);
        printf("cha: %d\n", *val);
    }
    munmap(val, sizeof(int));
}

int main() {
    ChildProcess();

}