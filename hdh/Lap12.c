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

int main()
{
    int n, nm, p, x = 0, y = 1, of, i;
    printf("Enter the memory size: ");
    scanf("%d", &nm);
    printf("Enter the no.of segments: ");
    scanf("%d", &n);
    int s[n], t[n];
    for (i = 0;i < n;i++)
    {
        printf("enter the segment size of %d: ", i + 1);
        scanf("%d", &s[i]);
        x += s[i];
        if (x > nm)
        {
            printf("memory full segment %d is not allocated\n", i + 1);
            x -= s[i];
            s[i] = 0;
        }
        else {
            printf("enter the base address of this segment of %d: ", i + 1);
            scanf("%d", &t[i]);
        }
    }
    printf("-----OPERATIONS------\n");
    while (y == 1)
    {
        printf("enter the no.of operations: ");
        scanf("%d", &p);
        printf("enter the offset: ");
        scanf("%d", &of);
        if (s[p - 1] == 0)
        {
            printf("segment is not allocated\n");
        }
        else if (of > s[p - 1])
        {
            printf("out of range!..\n");
        }
        else
        {
            printf("the segment %d the physical address is ranged from %d to %d\n the address of operation is %d\n", p, t[p - 1], t[p - 1] + s[p - 1], t[p - 1] + of);
        }
        printf("press 1 to continue - other numbers to quit: ");
        scanf("%d", &y);
    }
}