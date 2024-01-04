/*
Viết chương trình tạo ra tiến trình để thực hiện một lệnh shell của Linux, Chẳng hạn thực thi lệnh: ls -lt

1/ Viết bằng C sử dụng system call bằng họ lệnh exec().

2/ Sử dụng Shell script
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    printf("hello world \n");
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        // child (new process)
        printf("hello, I am child \n");
        char* pathprogram = "/bin/ls";
        char* argopt = "-lt";
        char* argdes = ".";
        execl(pathprogram, pathprogram, argopt, argdes, NULL);
        printf("this shouldn't print out");

    }
    else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        printf("hello, I am parent\n");
    }
    return 0;
}