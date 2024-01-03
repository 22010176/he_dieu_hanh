#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include <sys/wait.h>

uint8_t flag[2] = { 0,0 };
uint32_t turn = 1;

void P0() {
    for (;;) {
        flag[0] = turn = 1;
        while (flag[1] && turn); // Lap cho den khi dieu kien ko thoa man
        // doan nguy hiem
        flag[0] = 0;
        // phan con lai
    }
}
void P1() {
    for (;;) {
        flag[1] = 1, turn = 0;
        while (flag[0] && !turn); // Lap cho den khi dieu kien ko thoa man
        // doan nguy hiem
        flag[1] = 0;
        // phan con lai
    }
}

int main() {
    flag[0] = flag[1] = turn = 0;
    int pid = fork();
    if (pid < 0) {
        printf("Could not initialize");
        exit(-1);
    }
    else if (pid == 0) P0();
    else if (pid > 0) P1();
}