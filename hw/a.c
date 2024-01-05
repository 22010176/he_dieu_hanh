#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>


#define StartProcess(x)  x

bool chopsticks[5] = { false }; // Mỗi triết gia đều có một chiếc đũa

int Test_and_Set(bool* target) {
    // Lệnh Test_and_Set kiểm tra và thiết lập một biến bool là true
    // Nếu target ban đầu là false, nó sẽ được thiết lập thành true và hàm trả về false
    // Nếu target ban đầu đã là true, lệnh sẽ trả về true
    bool initial = *target;
    *target = true;
    return initial;
}

void eat(int philosopher_id) {
    printf("Triet gia %d dang an com.\n", philosopher_id + 1);
}

void think(int philosopher_id) {
    printf("Triet gia %d dang nghi.\n", philosopher_id + 1);
}

void take_chopsticks(int philosopher_id) {
    // Kiểm tra xem có thể lấy hai chiếc đũa hay không
    while (Test_and_Set(&chopsticks[philosopher_id]) || Test_and_Set(&chopsticks[(philosopher_id + 1) % 5])) {
        // Nếu không thể lấy được hai đũa, triết gia phải đợi
        // Trạng thái 0 0 sẽ dừng vòng lặp.
        printf("Triet gia %d dang doi.\n", philosopher_id + 1);
    }
}

void put_chopsticks(int philosopher_id) {
    // Trả lại đũa sau khi đã ăn xong
    chopsticks[(philosopher_id + 1) % 5] = chopsticks[philosopher_id] = false;
}

void philosophers(int philosopher_id) {
    int id = philosopher_id;

    for (int i = 0; ; i++) {
        think(id);

        take_chopsticks(id);            // Hàm đợi
        eat(id);                        // Hàm nguy hiểm 

        put_chopsticks(id);             // Hàm thay đổi trạng thái
    }

    // return NULL;
}

int main() {}