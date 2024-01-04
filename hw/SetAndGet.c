#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

#define StartProcess(f) f

int TestAndSet(int* val) {
    int temp = *val;
    *val = 0;
    // printf("%d ", val);
    return temp;
}

const int n = 5;
int dua[] = { 1,1,1,1,1 };

// int lp[] = { 0,0,0,0,0 };
int p[] = { 0,0,0,0,0 };

int Wait(int i) {
    if (dua[i] && dua[(i + 1) % n]) return TestAndSet(dua + i) && TestAndSet(dua + (i + 1) % n);
    return 0;
}

char Print(int a) { return a ? '*' : ' '; }
void Test() {

    for (int i = 0; i < n; i++) p[i] = Wait(i);

    printf("            1.(%d)             \n", p[0]);
    printf("\n");

    printf("      1.%d          2.%d       \n", dua[0], dua[1]);
    printf("\n");

    printf("5.(%d)                       2.(%d)\n", p[4], p[1]);
    printf("\n");

    printf("   5.%d                 3.%d   \n", dua[4], dua[2]);
    printf("\n");

    printf("      4.(%d)    4.%d    3.(%d)       \n", p[3], dua[3], p[2]);
    printf("\n");

    for (int i = 0; i < n;i++) if (p[i] == 1 && rand() % 2 == 0) {
        dua[i] = 1, dua[(i + 1) % n] = 1;
        p[i] = 0;
    }


    sleep(1);
}


void P(int i) {
    while (1) {
        // TestAndSet sẽ để biến là true mỗi khi được gọi và trả về giá trị của biến lúc chưa đổi.
        // 0 || 0 = 0 -> (1, 1): 2 đũa ở bên ko có người dùng và để là 1 ý chỉ có người chuẩn bị dùng. 
        // 0 || 1 = 1 -> (1, 1): có 1 đũa ở bên cạnh, một đũa nữa đang được dùng, điều kiện đang đúng nên là phải chờ.
        // 1 || 0 = 1 -> (1, 1)
        // 1 || 1 -> (1, 1): Vì cả 2 đũa đều đang được dùng rồi nên là phải chờ.
        while (p[i]);

        // sleep(1); // làm việc nguy hiểm

        dua[i] = dua[(i + 1) % n] = 1;

        // sleep(1); // làm việc khác
    }
}

int main() {
    srand(time(NULL));
    // lock = false;
    for (int i = 0;; ++i) {
        printf("%d\n", i);
        Test();

    }

    // printf("%d\n", dua[0]);
    // TestAndSet(&dua[0]);
    // printf("%d\n", dua[0]);
}