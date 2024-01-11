/*
Sử dụng lệnh wait() để dừng tạm thời tiến trình.
Thuật toán:
- Bước 1: Bắt đầu chương trình, khai báo và khởi tạo giá trị cho một biến.
- Bước 2: Tạo tiến trình con sử dụng lệnh fork().
- Bước 3: Kiểm tra xem có tạo được tiến trình hay không, tiến trình con được tạo khi pid = 0.
- Bước 4: Nếu tiến trình con được tạo thì cho tiến trình con in ra màn hình giá trị biến đã được khai báo,
 sau đó thay đổi giá trị của biến rồi kết thúc tiến trình con.
- Bước 5: Nếu không phải tiến trình cha thì phải đợi tiến trình con kết thúc hẳn.
- Bước 6: Kết thúc chương trình.
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>


int e = 10;

int main(){
    int pid = fork();
    if(pid < 0){
        printf("bao loi");
        exit (-1);
    }else if(pid==0){
        // printf("tien trinh con");
        e = 20;        
        printf("con: %d\n", e);
        exit(1);
    }else{
        wait(NULL);
        // printf("tien trinh cha");
        printf("cha: %d\n", e);
        
    }
     
    return 0;
}