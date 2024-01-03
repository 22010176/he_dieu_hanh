#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include <sys/wait.h>

int flags[2] = { 0,0 };             // { 0,0 }, 0
int turn = 0;
int time = 0;

void P0() {
  flags[0] = turn = 1;             // { 1,0 }, 1 : p0 vao khu vuc nguy hiem, luot p1
  printf("%d. f0: %d f1: %d t: %d\n", ++time, flags[0], flags[1], turn);
  // Neu p1 dang hoat dong va p1 dang tiep can khu vuc nguy hiem.
  // Lap cho den khi dieu kien ko thoa man | (0 && 1) = 0
  while (flags[1] && turn) printf("%d. f0: %d f1: %d t: %d\n", ++time, flags[0], flags[1], turn);

  // doan nguy hiem
  flags[0] = 0;                    // { 0,0 }, 1 : p0 thoat khu vuc nguy hiem, luot p1
  printf("%d. f0: %d f1: %d t: %d\n", ++time, flags[0], flags[1], turn);
  // phan con lai
}
void P1() {
  flags[1] = 1, turn = 0;          // { 0,1 }, 0 : p1 vao khu vuc nguy hiem, luot p0
  printf("%d. f0: %d f1: %d t: %d\n", ++time, flags[0], flags[1], turn);

  // Neu p0 dang hoat dong va p0 dang tiep can khu vuc nguy hiem.  
  // Lap cho den khi dieu kien ko thoa man | (0 && !0) == 0;
  while (flags[0] && !turn) printf("%d. f0: %d f1: %d t: %d\n", ++time, flags[0], flags[1], turn);

  // doan nguy hiem
  flags[1] = 0;                    // { 0,0 }, 0 : p1 thoat khu vuc nguy hiem, luot p0
  printf("%d. f0: %d f1: %d t: %d\n", ++time, flags[0], flags[1], turn);
  // phan con lai
  printf("\n\n");
}

int main() {
  while (1) {
    int pid = fork();
    if (pid < 0) {
      printf("Could not initialize");
      exit(-1);
    }
    else if (pid == 0) P0();
    else if (pid > 0) P1();
    if (time == 10) break;
  }
}