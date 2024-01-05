#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <sys/mman.h>
#include <sys/wait.h>
#include <bits/mman-linux.h>

#define StartProcess(f) f

#define NOT_FINISHED        0
#define TWO_CHOPSTICKS      1
#define FINISHED            2

#define USED                0
#define FREE                1    

int TestAndSet(int* val, int value) {
    int temp = *val; *val = value;
    return temp;
}

int n = 5;
int dua[] = { FREE,FREE,FREE,FREE,FREE };                                                           // đũa
int p[] = { NOT_FINISHED,NOT_FINISHED,NOT_FINISHED,NOT_FINISHED,NOT_FINISHED };                     // Nhà triết gia

/*
!(1 && 1) = !1 = 0 -> ( 0, 0 ) * (dừng vòng lặp (dừng chờ) do cả 2 bên đã có đũa, nhà triết gia bắt đầu ăn )

Chỉ cập nhật khi cả 2 đũa đều tồn tại, ko thì giữ nguyên trạng thái.
!(1 && 0) = !0 = 1 -> ( 1, 0 )
!(0 && 1) = !0 = 1 -> ( 0, 1 )
!(0 && 0) = !0 = 1 -> ( 0, 0 )
*/

int Wait(int i, int* dua, int* p) {

    int res = dua[i] && dua[(i + 1) % n];
    printf("Dang Nghi ");
    printf("%-2d %-2d %-2d %-2d %-2d\n", dua[0], dua[1], dua[2], dua[3], dua[4]);

    int temp = TestAndSet(&dua[i], !res) && TestAndSet(&dua[(i + 1) % n], !res);
    munmap(dua, n * sizeof(int));

    return temp;
}

void DangerJob(int i, int* dua, int* p) {
    p[i] = TWO_CHOPSTICKS;
    munmap(p, sizeof(int) * 5);
    sleep(1);
    printf("Dang an\n");

}
void UpdateState(int i, int* dua, int* p) {
    dua[i] = dua[(i + 1) % n] = FREE;
    munmap(dua, n * sizeof(int));

}

void SaveJob(int i, int* dua, int* p) {
    p[i] = FINISHED;
    munmap(p, sizeof(int) * 5);
    // sleep(2);
    printf("An Xong\n\n");
    // sleep(2);
}

void P(int i, int* dua, int* p) {
    if (p[i] == FINISHED) return;

    printf("%d.\n", i);

    while (Wait(i, dua, p)); // Nghĩ

    DangerJob(i, dua, p); // Ăn

    UpdateState(i, dua, p); // Ăn Xong

    SaveJob(i, dua, p);

}

int main() {
    // srand(time(NULL));

    int* dua = mmap(NULL, n * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | 0x20, 0, 0);
    for (int i = 0; i < n; i++) dua[i] = FREE;
    munmap(dua, sizeof(int) * n);
    // memcpy(dua, (int*) { FREE, FREE, FREE, FREE, FREE }, sizeof(int)* n);

    int* p = mmap(NULL, n * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | 0x20, 0, 0);
    for (int i = 0; i < n; i++) p[i] = NOT_FINISHED;
    munmap(p, sizeof(int) * n);
    // memcpy(p, (int*) { NOT_FINISHED, NOT_FINISHED, NOT_FINISHED, NOT_FINISHED, NOT_FINISHED }, sizeof(int)* n);

    int mainProgram = fork();

    if (mainProgram < 0) {
        printf("Failed.");
        exit(-1);
    }
    else if (mainProgram == 0) {
        for (int i = 0; i < n; i++) {
            if (fork() == 0) P(i, dua, p);
        }
        // wait(NULL);
    }
    else if (mainProgram > 0) {
        wait(NULL);
        printf("Done");
    }




    // for (int i = 0; i < n; i++) StartProcess(P(i));
}
