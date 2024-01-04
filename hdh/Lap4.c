/*
Tạo ra tiến trình con từ tiến trình cha và kiểm tra pid của tiến trình con thông qua biến pid được gán thông qua việc gọi lệnh fork().
Thuật toán:
- Bước 1: Bắt đầu chương trình và tạo ra một tiến trình con bằng lệnh fork().
- Bước 2: Để tiến trình tra sleep trong khoảng 10s.
- Bước 3: Trong tiến trình con, in ra màn hình giá trị pid tương ứng với tiến trình con bằng lệnh getpid.
- Bước 4: Đưa tiến trình con sleep khoảng 5s.
- Bước 5: Lặp lại việc in ra pid của tiến trình con và tiến trình cha.
- Bước 6: Sau đó đưa tiến trình cha sleep khoảng 10s và in pid của nó ra màn hình.
- Bước 7: Dừng chương trình.
*/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main() {
    int pid;
    pid = fork();
    if (pid < 0) {
        printf("cannot create the process");
        exit(-1);
    }
    if (pid == 0) {
        printf("\n Child Process\n");
        printf("\n Child Process id is %d ", getpid());
        printf("\n Its parent process id is %d", getppid());
        sleep(5);
        printf("\n Child process after sleep=5");
        printf("\n Child Process id is %d ", getpid());
        printf("\n Its parent process id is %d\n\n", getppid());
        exit(0);
    }
    else {
        printf("\n Parent process");
        sleep(10);
        printf("\n Child Process id is %d ", getpid());
        printf("\n Its parent process id is %d", getppid());
        printf("\n Parent terminates\n");
    }
}