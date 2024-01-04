/*
Viết chương trình C mô phỏng hoạt động của lênh "ls" trên dòng lệnh của Unix.
Thuật toán:
- Bước 1: Kiểm tra tham số đầu vào trên dòng lệnh xem có nhỏ hơn 2 hay không?

- Bước 2: Nếu đúng: in ra dòng báo lỗi và kết thúc vì không cung cấp thư mục đích.

- Bước 3: Nếu sai: tiếp tục kiểm tra xem tham số thứ 2 trên dòng lệnh có đúng là đường dẫn của một thư mục hợp lệ hay không?

- Bước 5: Nếu đúng thì liệt kê các nội dung của thư mục

- Bước 6: Nếu sai thì in ra dòng báo lỗi.
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>

// gcc Lap7.c -o Lap7 && ./Lap7 ./

void main(int argc, char* argv[]) {
    DIR* dp;
    struct dirent* dirp;
    if (argc < 2) {
        printf("\n You have provided only 1 argument\n");
        exit(1);
    }
    if ((dp = opendir(argv[1])) == NULL) {
        printf("\nCannot open %s file!\n", argv[1]);
        exit(1);
    }
    while ((dirp = readdir(dp)) != NULL) printf("%s\n", dirp->d_name);
    closedir(dp);
}