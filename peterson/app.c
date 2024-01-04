#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include <sys/wait.h>

int flags[2] = { 0,0 };             // { 0,0 }, 0
int turn = 0;
int time = 0;
int running[] = { 0,0 };

void Testing() { printf("%d. f0: %d f1: %d t: %d\n", ++time, flags[0], flags[1], turn); }

void P0() {
  while (1) {
    if (time == 5) break;

    flags[0] = turn = 1;             // { 1,0 }, 1 : p0 vao khu vuc nguy hiem, luot p1
    Testing();
    // Neu p1 dang hoat dong va p1 dang tiep can khu vuc nguy hiem.
    // Lap cho den khi dieu kien ko thoa man | (0 && 1) = 0
    while (flags[1] && turn) Testing();

    // doan nguy hiem
    flags[0] = 0;                    // { 0,0 }, 1 : p0 thoat khu vuc nguy hiem, luot p1
    Testing();
    // phan con lai

    printf("\n\n");
  }
}
void P1() {
  while (1) {

    flags[1] = 1, turn = 0;          // { 0,1 }, 0 : p1 vao khu vuc nguy hiem, luot p0
    Testing();

    // Neu p0 dang hoat dong va p0 dang tiep can khu vuc nguy hiem.  
    // Lap cho den khi dieu kien ko thoa man | (0 && !0) == 0;
    while (flags[0] && !turn) Testing();

    // doan nguy hiem
    flags[1] = 0;                    // { 0,0 }, 0 : p1 thoat khu vuc nguy hiem, luot p0
    Testing();
    // phan con lai
    // printf("\n\n");
    // ++running[1];
  }
}

int main() {
  int pid = fork();
  if (pid < 0) {
    printf("Could not initialize");
    exit(-1);
  }
  else if (pid == 0) P0();
  else if (pid > 0) P1();

  while (running[0] != running[1]);
  // if (time == 5) return 0;

}