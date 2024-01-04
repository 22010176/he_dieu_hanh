#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>

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
    int pid = fork();
    // waitpid(0, NULL, 0);
    // waitpid(pid, NULL, 0);
    // sleep(1);

    wait(NULL);
    // printf("%d %d\n", pid, a);
    if (pid == 0) {
        _p("%d. %9d %d\n", 1, pid, getpid());
        c += 10;
        exit(0);
    }
    else if (pid > 0) {
        _p("%d. %9d %d\n", 2, pid, getpid());
    }
    printf("c = %d\n", c);
    // printf("\n");


}

int main() {
    ChildProcess();
    printf("%d\n", c);
}