/*
Viết chương trình C mô phỏng quản lý bộ nhớ theo hình thức tổ chức phân đoạn bộ nhớ.

THUẬT TOÁN:
- Bước 1: Xác định kích thước bộ nhớ cấp cho tiến trình.
- Bước 2: Xác định số đoạn cần cấp.
- Bước 3: Xác định kích thước của đoạn và địa chỉ cơ sở của đoạn.
- Bước 4: Kiểm tra khả năng cấp phát của đoạn có hợp lệ hay không?
- Bước 5: Thực hiện việc kiểm tra địa chỉ logic được nhập vào thông qua giá trị Offset.
- Bước 6: Tính địa chỉ vật lý.
- Bước 7: Hiển thị kết quả ra màn hinh.
*/

#include <stdio.h>

int main() {
    int number_segments, memory_size, x = 0;

    printf("Enter the memory size: ");
    scanf("%d", &memory_size);

    printf("Enter the no.of segments: ");
    scanf("%d", &number_segments);

    int segments[number_segments], address[number_segments];

    for (int i = 0;i < number_segments;++i) {
        printf("enter the segment size of %d: ", i + 1);
        scanf("%d", segments + i);
        x += segments[i];
        if (x > memory_size) {
            printf("memory full segment %d is not allocated\n", i + 1);
            x -= segments[i]; segments[i] = 0;
        }
        else {
            printf("enter the base address of this segment of %d: ", i + 1);
            scanf("%d", address + i);
        }
    }

    printf("-----OPERATIONS------\n");
    int proccess_number, offset, running = 1;
    while (running == 1) {
        printf("enter the no.of operations: "), scanf("%d", &proccess_number);
        printf("enter the offset: "), scanf("%d", &offset);

        if (segments[proccess_number - 1] == 0) printf("segment is not allocated\n");
        else if (offset > segments[proccess_number - 1]) printf("out of range!..\n");
        else {
            printf("the segment %d the physical address is ranged from %d to %d\n", proccess_number, address[proccess_number - 1], address[proccess_number - 1] + segments[proccess_number - 1]);
            printf("the address of operation is %d\n", address[proccess_number - 1] + offset);
        }

        printf("press 1 to continue - other numbers to quit: ");
        scanf("%d", &running);
    }
}