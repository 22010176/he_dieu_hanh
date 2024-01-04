#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define StartProcess(f) f

int TestAndSet(int* val) {
    int temp = *val;
    *val = 0;
    return temp;
}

const int n = 5;
int dua[] = { 1,1,1,1,1 };              // đũa
int p[] = { 0,0,0,0,0 };                // Nhà triết gia

/*
!(1 && 1) = !1 = 0 -> ( 0, 0 ) * (dừng vòng lặp (dừng chờ) do cả 2 bên đã có đũa, nhà triết gia bắt đầu ăn )

Chỉ cập nhật khi cả 2 đũa đều tồn tại, ko thì giữ nguyên trạng thái.
!(1 && 0) = !0 = 1 -> ( 1, 0 )
!(0 && 1) = !0 = 1 -> ( 0, 1 )
!(0 && 0) = !0 = 1 -> ( 0, 0 )


(1  1) =  0 -> ( 0, 0 ) -> (1, 1) *
(1  0) =  1 -> ( 0, 0 )
(0  1) =  1 -> ( 0, 0 )
(0  0) =  1 -> ( 0, 0 )

(1  1) =  1 -> ( 1, 1 )
(1  0) =  1 -> ( 1, 1 )
(0  1) =  1 -> ( 1, 1 )
(0  0) =  0 -> ( 1, 1 ) -> (0, 0)*

(1  1) =  0 -> ( 1, 1 ) *
(1  0) =  1 -> ( 1, 1 )
(0  1) =  1 -> ( 1, 1 )
(0  0) =  1 -> ( 1, 1 )

(1  1) =  1 -> ( 0, 0 )
(1  0) =  1 -> ( 0, 0 )
(0  1) =  1 -> ( 0, 0 )
(0  0) =  0 -> ( 0, 0 ) *

*/
int Wait(int i) {
    int result = dua[i] && dua[(i + 1) % n];
    if (result) TestAndSet(&dua[i]), TestAndSet(&dua[(i + 1) % n]);
    return result;
}

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