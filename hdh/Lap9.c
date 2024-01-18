/*
Viết chương trình C mô phỏng thực hiện lập lịch CPU theo thuật toán thực hiện công việc ngắn nhất trước tiên (SJF).

Thuật toán SJF: bộ lập lịch CPU sẽ chọn các tiến trình lần lượt có thời gian sử dụng CPU ít nhất để thực hiện trước.

Thuật toán như sau:

- Bước 01: Đưa vào số tiến trình.
- Bước 02: Đưa vào số pid và thời gian sử dụng CPU của từng tiến trình.
- Bước 03: Ban đầu, thời gian chờ đợi của tiến trình có thời gian thực hiện ngắn nhất là 0 và tổng thời gian thực hiện của tiến trình này thời gian sử dụng của tiến trình này.
- Bước 04: Tính toán tổng thời gian thực hiện và thời gian chờ của các tiến trình còn lại.
- Bước 05: Thời gian chờ của một tiến trình là tổng thời gian của các tiến trình đã thực hiện trước đó.
- Bước 06: Tổng thời gian của tiến trình được tính bằng cách cộng thời gian chờ và thời gian thực hiện của tiến trình đó.
- Bước 07: Tổng thời gian chờ được tính bằng cách cộng thời gian chờ của mỗi tiến trình.
- Bước 08: Tổng thời gian quay vòng được tính bằng cách cộng tất cả tổng thời gian của mỗi tiến trình.
- Bước 09: Tính thời gian chờ trung bình bằng cách chia tổng thời gian chờ cho tổng số tiến trình.
- Bước 10: Tính thời gian quay vòng trung bình bằng cách chia tổng thời gian quay vòng cho tổng số tiến trình.
- Bước 11: Hiển thị kết quả ra màn hình.
*/

#include<stdio.h>

struct ff { int pid, ser, wait; } p[20];
struct ff tmp;

void main() {
    int i, n, j, tot = 0, totwait = 0, tturn = 0;
    float avwait, aturn;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    for (i = 0;i < n;i++) {
        printf("Enter pid of process %d: ", i + 1);
        scanf("%d", &p[i].pid);
        printf("Enter service time of process %d: ", i + 1);
        scanf("%d", &p[i].ser);
        p[i].wait = 0;
    }

    for (i = 0;i < n - 1;i++)
        for (j = i + 1;j < n;j++)
            if (p[i].ser > p[j].ser) {
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }

    printf("PID\tSER\tWAIT\tTOT\n");
    for (i = 0;i < n;i++) {
        p[i].wait = tot;
        tot = tot + p[i].ser;
        tturn = tturn + tot;
        totwait = totwait + p[i].wait;
        printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].ser, p[i].wait, tot);
    }
    avwait = totwait * 1.0 / n;
    aturn = tturn * 1.0 / n;
    printf("TOTAL WAITING TIME: %d\n", totwait);
    printf("AVERAGE WAITING TIME: %4.2f\n", avwait);
    printf("TOTAL TURNAROUND TIME: %d\n", tturn);
    printf("AVERAGE TURNAROUND TIME: %4.2f\n", aturn);
}