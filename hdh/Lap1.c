/*
Bước 1: Bắt đầu chương trình.
Bước 2: Khai báo pid là số nguyên.
Bước 3: Tạo tiến trình sử dụng lệnh Fork.
Bước 4: Kiểm tra xem nếu pid nhỏ hơn 0 thì báo lỗi, nếu pid bằng không thì thực hiện lệnh của tiến trình con, nếu pid lớn hơn không thì tiến trình cha đợi tiến trình con thực hiện.
Bước 5: Kết thúc chương trình.
*/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main() {
    int id;
    id = fork();
    // sleep(10);
    if (id < 0) {
        printf("cannot create the file");
        exit(-1);
    }
    if (id == 0) {
        printf("child process \n");
        exit(0);
    }
    else {
        printf("parent process \n");
    }
}