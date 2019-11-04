#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    if(argc <= 1) {
        printf(2, "Please enter a command after 'time'\n");
        exit();
    }
    else {
        int pid = fork();
        if(pid == 0) {
            exec(argv[1], &argv[2]);
            printf(2, "Error executing %s\n", argv[1]);
        }
        else if(pid > 0) {
            int rtime, wtime;
            waitx(&wtime, &rtime);
            printf(1, "wTime is %d and rTime is %d\n", wtime, rtime);
            exit();
        }
        else {
            printf(2, "Fork Error!");
            exit();
        }
    }
}