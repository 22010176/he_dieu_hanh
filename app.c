#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <bits/mman-linux.h>

#include "utils/utils.h"


void Process(void* data) {
    // printf("Good\n");
    // wait(NULL);
    int a = 88;
    SaveMem(data, (char*)&a, 4);
    // printArr(data, 4);
}


int main() {
    // int d = 0x10560041;
    void* data = GetMem(NULL, 4);

    int child_pid = fork();
    if (child_pid == 0) {
        fork();
        Process(data);
    }
    else if (child_pid > 0) {
        wait(NULL);
        printArr(data, 4);
    }


}