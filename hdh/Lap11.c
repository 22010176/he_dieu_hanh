/*
Viết chương trình C mô phỏng quá trình quản lý bộ nhớ theo hình thức phân trang.

THUẬT TOÁN:
- Bước 1: Xác định kích thước trang, kích thước bảng trang, số lượng trang trong bảng trang.
- Bước 2: Nhập vào địa chỉ cơ sở của các trang trong bảng trang.
- Bước 3: Nhập vào địa chỉ logic và dữ liệu của địa chỉ đó.
- Bước 4: Chuyển đổi địa chỉ logic thành địa chỉ vật lý.
- Bước 5: Hiển thị kết quả.
*/

#include <stdio.h>
#include<stdio_ext.h>

#define PAGE_SIZE                                   100
#define PAGE_TABLE_SIZE                             128

struct pentry { int no; int start_addr; } ptable[PAGE_TABLE_SIZE];

char memory[PAGE_SIZE * PAGE_TABLE_SIZE];

int get_physical_address(int logical_address) {
    int page_no = logical_address / PAGE_SIZE;
    int offset = logical_address % PAGE_SIZE;

    return ptable[page_no].start_addr + offset;
}

int main() {
    int entry_flag = 0, translate_flag = 0, phy_addr, logical_addr;
    char data, choice;
    int n, i;
    printf("\nEnter the number of pages to allocate: ");
    scanf("%d", &n);

    for (i = 0;i < n;i++) {
        printf("\nEnter Starting Address for Page %d: ", i);
        scanf("%d", &ptable[i].start_addr);
        ptable[i].no = i;
    }

    while (entry_flag == 0) {
        printf("\nEnter the logical address of data to be modified: ");
        scanf("%d", &logical_addr);

        printf("\nEnter the data to be set at the given location: ");
        __fpurge(stdin);
        scanf("%c", &data);

        phy_addr = get_physical_address(logical_addr);
        memory[phy_addr] = data;

        printf("\nData successfully stored at physical address %d. \nModify more data? (y/n) ", phy_addr);
        __fpurge(stdin);
        scanf("%c", &choice);
        if (choice == 'n') entry_flag = 1;
    }

    while (translate_flag == 0) {
        printf("\nEnter the logical address to be translated: ");
        scanf("%d", &logical_addr);

        phy_addr = get_physical_address(logical_addr);
        data = memory[phy_addr];
        printf("\nLogical Address %d = Physical Address %d. Data is %c", logical_addr, phy_addr, data);

        printf("\nContinue? (y/n) ");
        __fpurge(stdin);
        scanf("%c", &choice);
        if (choice == 'n') translate_flag = 1;
    }
    return 0;
}