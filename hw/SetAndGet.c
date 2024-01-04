#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

#define StartProcess(f) f

int TestAndSet(int* val) {
    int temp = *val;
    *val = 1;
    return temp;
}

const int n = 5;
int dua[] = { 1,1,1,1,1 };              // đũa
int p[] = { 0,0,0,0,0 };                // Nhà triết gia


/*
!(1 && 1) = !1 = 0 -> ( 1, 1 ) * (dừng vòng lặp)
!(1 && 0) = !0 = 1 -> ( 1, 1 )
!(0 && 1) = !0 = 1 -> ( 1, 1 )
!(0 && 0) = !0 = 1 -> ( 1, 1 )
*/

int Wait(int i) { return !(TestAndSet(dua + i) && TestAndSet(dua + (i + 1) % n)); }
void DangerJob() { sleep(2); }
void UpdateState(int i) { dua[i] = dua[(i + 1) % n] = 1; }
void SaveJob() {}

void P(int i) {
    while (1) {
        while (Wait(i));
        DangerJob();

        UpdateState(i);

        SaveJob();
    }
}

int main() {
    for (int i = 0; i < n; i++) StartProcess(P(i));
}