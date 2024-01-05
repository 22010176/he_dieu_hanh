#include <stdio.h>
#include <sys/mman.h>
#include <bits/mman-linux.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void* GetMem(size_t size) {
    return mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED | 0x20, 0, 0);
}

int main() {
    int Number = 5;
    int* ptr = mmap(NULL, Number * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | 0x20, 0, 0);

    if (ptr == MAP_FAILED) {
        printf("Mapping Failed\n");
        return 1;
    }

    for (int i = 0; i < Number; i++) ptr[i] = i + 7;


    printf("Initial array's values:");
    for (int i = 0; i < Number; i++) printf(" %d", ptr[i]);

    printf("\n");
    pid_t child_pid = fork();

    if (child_pid == 0) {
        // child
        for (int i = 0; i < Number; i++) ptr[i] = ptr[i] * 5;

        munmap(ptr, Number * sizeof(int));
    }
    else {
        // parent
        wait(NULL);
        printf("\nParent:\n");
        printf("Updated array's values:");
        for (int i = 0; i < Number; i++) printf(" %d", ptr[i]);
        printf("\n");
    }



    // if (err != 0) {
    //     printf("Unmapping Failed\n");
    //     return 1;
    // }
    return 0;
}