#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

bool chopsticks[5] = { false }; // Mỗi triết gia đều có một chiếc đĩa

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
    // Kiểm tra xem có thể lấy hai chiếc đĩa hay không
    while (Test_and_Set(&chopsticks[philosopher_id]) || Test_and_Set(&chopsticks[(philosopher_id + 1) % 5])) {
        // Nếu không thể lấy được hai đĩa, triết gia phải đợi
        // Trạng thái 0 0 sẽ dừng vòng lặp.
        printf("Triet gia %d dang doi.\n", philosopher_id + 1);
    }
}

void put_chopsticks(int philosopher_id) {
    // Trả lại đĩa sau khi đã ăn xong
    chopsticks[(philosopher_id + 1) % 5] = chopsticks[philosopher_id] = false;
}

void* dining_philosophers(void* philosopher_id) {
    int id = *(int*)philosopher_id;

    for (int i = 0; i < 20; i++) {
        think(id);

        take_chopsticks(id);            // Hàm đợi
        eat(id);                        // Hàm nguy hiểm 

        put_chopsticks(id);             // Hàm thay đổi trạng thái
    }

    return NULL;
}

int main() {
    pthread_t philosophers[5];

    for (int i = 0; i < 5; i++) {
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&philosophers[i], NULL, dining_philosophers, id);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}