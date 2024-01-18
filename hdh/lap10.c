/*
Viết một chương trình C để mô phỏng lập lịch CPU theo thuật toán RR (Round Robin).
MÔ TẢ VẤN ĐỀ:
Thuật toán RR sử dụng một lát thời gian gọi là thời gian lượng tử tq. Tiến trình được phân bổ theo tq, nếu thời gian phục vụ tiến trình nhỏ hơn tq thì bản thân tiến trình sẽ tự nguyện giải phóng CPU. Bộ lập lịch sau đó sẽ tiến hành tiến trình tiếp theo trong hàng đợi sẵn sàng. Tiến trình hiện tại sẽ thực hiện quá trình chuyển đổi ngữ cảnh thực hiện và chuyển về cuối hàng đợi sẵn sàng. Nếu sự sử dụng CPU của tiến trình hiện đang chạy lâu hơn tq thì bộ đếm thời gian sẽ tắt và gây ra gián đoạn cho hệ điều hành.

THUẬT TOÁN:

- Bước 1: Khởi tạo cấu trúc các tiến trình
- Bước 2: Nhận các thông số đầu vào tiến trình từ người dùng: pid, thời gian đến, thời gian thực hiện, thời gian lượng tử.
- Bước 3: Tính toán thời gian chờ đối với các tiến trình
   i) Thời gian chờ cho lần đầu tiên của một tiến trình a được tính như sau: a[i].waittime = a[i].arrivetime
   ii) Thời gian chờ cho phần còn lại của tiến trình được tính như sau:
       a) Nếu thời gian lượng tử tq < thời gian thực hiện còn lại của tiến trình: a[i].waittime += tq
       b) Ngược lại nếu thời gian lượng tử tq > thời gian còn lại của tiến trình: a[i].waittime += tremaining
- Bước 4: Tính thời gian chờ đợi trung bình và thời gian thực hiện trung bình
- Bước 5: Hiên thị kết quả ra màn hình.
*/

#include<stdio.h>
#define N 20
struct RR { int pid; float tser, twait, tarriv; } p[N];
struct RR tmp;

float tq;
int Np;

int NumOfP() {
    int n;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    return n;
}

void inputRR() {
    int i, j;
    Np = NumOfP();
    printf("Enter time quantum of RR Algorithm: ");
    scanf("%f", &tq);
    for (i = 0;i < Np;i++) {
        printf("Enter pid of process %d: ", i + 1);
        scanf("%d", &p[i].pid);
        if (i == 0) p[i].tarriv = 0;
        else {
            printf("Enter arrive time of process %d: ", i + 1);
            scanf("%f", &p[i].tarriv);
        }
        printf("Enter service time of process %d: ", i + 1);
        scanf("%f", &p[i].tser);
        p[i].twait = 0;
    }
    //sort by time arrive of processes
    for (i = 0;i < Np - 1;i++)
        for (j = i + 1;j < Np;j++)
            if (p[i].tarriv > p[j].tarriv) {
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
}

void RRAlgorithm() {
    int i, j, Count = Np;
    float tremain[N], t = 0, tr;
    for (i = 0;i < Np;i++)
        tremain[i] = p[i].tser;
    while (Count > 0) {
        for (i = 0;i < Np;i++) {
            if ((p[i].tarriv <= t) && (tremain[i] > 0)) {
                if (tremain[i] > tq)
                    tr = tq;
                else tr = tremain[i];
                tremain[i] -= tr;
                t += tr;
                for (j = 0;j < Np;j++)
                    if ((j != i) && (tremain[i] > 0))
                        p[j].twait += tr;
                if (tremain[i] == 0) {
                    Count--;
                    p[i].twait -= p[i].tarriv;
                }
                printf("|P%0d=%0.2f", p[i].pid, tr);
            }
        }
    }
    printf("|\n");
}

void main() {
    int i;
    float totwait = 0, tturn = 0, avwait, aturn;

    inputRR();
    RRAlgorithm();

    for (i = 0;i < Np;i++) {
        totwait += p[i].twait;
        tturn += p[i].twait + p[i].tser;
    }

    avwait = totwait / Np;
    aturn = tturn / Np;

    printf("TOTAL WAITING TIME: %4.2f\n", totwait);
    printf("AVERAGE WAITING TIME: %4.2f\n", avwait);
    printf("TOTAL TURNAROUND TIME: %4.2f\n", tturn);
    printf("AVERAGE TURNAROUND TIME: %4.2f\n", aturn);
}