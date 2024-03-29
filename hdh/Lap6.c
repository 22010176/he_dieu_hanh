/*
Sử dụng lệnh wait() để dừng tạm thời tiến trình.
Thuật toán:
- Bước 1: Bắt đầu chương trình, khai báo và khởi tạo giá trị cho một biến.
- Bước 2: Tạo tiến trình con sử dụng lệnh fork().
- Bước 3: Kiểm tra xem có tạo được tiến trình hay không, tiến trình con được tạo khi pid = 0.
- Bước 4: Nếu tiến trình con được tạo thì cho tiến trình con in ra màn hình giá trị biến đã được khai báo, sau đó thay đổi giá trị của biến rồi kết thúc tiến trình con.
- Bước 5: Nếu không phải tiến trình cha thì phải đợi tiến trình con kết thúc hẳn.
- Bước 6: Kết thúc chương trình.
*/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int i = 10;
void main() {
    int pid = fork();
    if (pid == 0) {
        printf("initial value of i %d \n ", i);
        i += 10;
        printf("value of i %d \n ", i);
        printf("child terminated \n");
    }
    else {
        wait(0);
        printf("value of i in parent process %d\n", i);
    }
}