#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define StartProcess(f) f

#define CHUA_AN_XONG                    0
#define CO_DU_HAI_DUA                   1
#define HOAN_THANH                      2

#define DUA_DANG_DUNG                   0
#define DUA_KO_DUNG                            1    

int TestAndSet(int* val, int value) {
    int temp = *val; *val = value;
    return temp;
}

int n = 5;

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
    int temp = TestAndSet(&dua[i], !res) && TestAndSet(&dua[(i + 1) % n], !res);

    return temp;
}

void DangerJob(int i, int* dua, int* p) {
    p[i] = CO_DU_HAI_DUA;
    printf("Dang an\n");

}
void UpdateState(int i, int* dua, int* p) {
    dua[i] = dua[(i + 1) % n] = DUA_KO_DUNG;
}

void SaveJob(int i, int* dua, int* p) {
    p[i] = HOAN_THANH;
    printf("An Xong\n\n");

}

void P(int i, int* dua, int* p) {
    if (p[i] == HOAN_THANH) return;

    printf("%d.\n", i);

    while (Wait(i, dua, p)); // Nghĩ
    DangerJob(i, dua, p); // Ăn
    UpdateState(i, dua, p); // Ăn Xong
    SaveJob(i, dua, p);
}

int main() {
    // srand(time(NULL));

    int dua[] = { DUA_KO_DUNG,DUA_KO_DUNG,DUA_KO_DUNG,DUA_KO_DUNG,DUA_KO_DUNG };

    int* p = { CHUA_AN_XONG, CHUA_AN_XONG, CHUA_AN_XONG, CHUA_AN_XONG, CHUA_AN_XONG };

    StartProcess(P(0, dua, p));
    StartProcess(P(1, dua, p));
    StartProcess(P(2, dua, p));
    StartProcess(P(3, dua, p));
    StartProcess(P(4, dua, p));

}
