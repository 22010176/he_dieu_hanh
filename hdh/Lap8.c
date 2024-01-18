/*
Giải thuật mô phỏng:
- Bước 01: Tạo ra một số tiến trình.
- Bước 02: Lấy PID và thời gian phục vụ (thời gian CPU) đối với mỗi tiến trình.
- Bước 03: Ban đầu, thời gian chờ của tiến trình đầu tiên là bằng 0 và tổng thời gian của tiến trình đầu tiên là thời gian thực hiện của tiến trình đó.
- Bước 04: Tính toán tổng thời gian và thời gian thực hiện tiến trình đối với các tiến trình còn lại.
- Bước 05: Thời gian chờ của một tiến trình là tổng thời gian thực hiện của các tiến trình trước đó.
- Bước 06: Tổng thời gian của một tiến trình được tính bằng cách cộng thời gian chờ và thời gian thực hiện.
- Bước 07: Tổng thời gian chờ được tính bằng cách cộng thời gian chờ của các tiến trình.
- Bước 08: Tổng thời gian thực hiện được tính bằng cách cộng tất cả tổng thời gian của mỗi tiến trình..
- Bước 09: Thời gian chờ đợi trung bình được tính bằng cách lấy tổng thời gian chờ chia cho số tiến trình.
- Bước 10: Tính thời gian thực hiện trung bình bằng cách chia tổng thời gian thực hiện cho số tiến trình.
- Bước 11: Hiển thị kết quả ra màn hình.
*/

#include<stdio.h>
struct process { int id, wait, ser, tottime; } p[20];

void main() {
    int i, n, j, totalwait = 0, totalser = 0, avturn, avwait;
    printf("enter number of process: ");
    scanf("%d", &n);
    for (i = 1;i <= n;i++) {
        printf("Enter process_id: ");
        scanf("%d", &p[i].id);
        printf("Enter process service time: ");
        scanf("%d", &p[i].ser);
    }
    p[1].wait = 0;
    p[1].tottime = p[1].ser;
    for (i = 2;i <= n;i++) {
        for (j = 1;j < i;j++) {
            p[i].wait = p[i].wait + p[j].ser;
        }
        totalwait = totalwait + p[i].wait;
        p[i].tottime = p[i].wait + p[i].ser;
        totalser = totalser + p[i].tottime;
    }
    avturn = totalser / n;
    avwait = totalwait / n;
    printf("Id\tservice\twait\ttotal");
    for (i = 1;i <= n;i++) {
        printf("\n%d\t%d\t%d\t%d\n", p[i].id, p[i].ser, p[i].wait, p[i].tottime);
    }
    printf("average waiting time %d\n", avwait);
    printf("average turnaround time %d\n", avturn);
}