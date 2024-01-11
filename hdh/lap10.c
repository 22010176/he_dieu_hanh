#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef enum PID_STATUS PID_STATUS;
enum PID_STATUS { WAITING, RUNNING, FINISH, IO_BLOCK };

typedef struct Process PID;
struct Process { int ID, time; PID_STATUS status; unsigned int remain, finish_time; };

PID* CreatePid(int ID, int time);
PID* InputPid();

char* GetLine(char** Headers, int len, int space_end, int space_start);
char* GetTable(char** Headers, int Header_len, void** Data, int Data_len, char* (*format_data)(void* data));

void Swap(void** a, void** b);
void Sorting(void* Data, int len, int (*compare)(void* a, void* b));

int main() {}

void* resize(void** _Src) {
    void* temp = *_Src;

}

PID* CreatePid(int ID, int time) { return memcpy(malloc(sizeof(PID)), (PID*) { ID, time, WAITING, 0, 0 }, sizeof(PID)); };
PID* InputPid() {
    printf("Nhap vao ID cua PID: ");
    int id; scanf("%d", &id);

    printf("Nhap vao thoi gian cua PID: ");
    int time; scanf("%d", &time);

    return CreatePid(id, time);
};

char* GetLine(char** Headers, int len, int space_end, int space_start) {

};
char* GetTable(char** Headers, int Header_len, void** Data, int Data_len, char* (*format_data)(void* data)) {};

void Swap(void** a, void** b) { void* temp = *a;*a = *b, * b = temp; }
void Sorting(void* Data, int len, int (*compare)(void* a, void* b)) {
    for (int i = 0; i < len; i++) for (int j = 0; j < len; j++)
        if (compare(Data + i, Data + j)) Swap(Data + i, Data + j);
};