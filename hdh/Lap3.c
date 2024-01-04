/*
Viết chương trình C, trong đó từ tiến trình cha, tạo một tiến trình con, để theo dõi được tiến trình con hoạt động, chúng ta có thể tạm dừng tiến trình con bằng lệnh sleep().

Thuật toán:
- Bước 1: Khởi tạo chương trình
- Bước 2: Tạo tiến trình sử dụng fork() và gán cho một biến pid.
- Bước 3: Nếu pid < 0, in ra thông báo không tạo được tiến trình, nếu pid = 0 thì tạo tiến trình con, nếu pid > 0 thì thực hiện công việc trong tiến trình con (in ra thông báo tiến trình con đã được tạo)
- Bước 4: Dừng tiến trình con bằng lệnh sleep khoảng 2 đơn vị thời gian CPU.
- Bước 5: Dừng chương trình.
*/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main() {
    int id;
    id = fork();
    if (id < 0) {
        printf("cannot create the process");
        exit(-1);
    }
    if (id == 0) {
        sleep(10);
        printf("child process \n");
        exit(0);
    }
    else {
        printf("parent process \n");
    }
}