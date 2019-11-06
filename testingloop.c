#include "types.h"
#include "pstat.h"
#include "stat.h"
#include "user.h"

void loop(int mult) {
    volatile int i = 0, j = 0;
    struct proc_stat stat;
    mult = mult * 40000;
    getpinfo(&stat, getpid());
    printf(1, "I am %d with %d and ctime: %d\n", getpid(), mult, stat.ctime);
    for(i=0; i<mult/*400000000*/; i++) 
    {
        j++;
    }
    getpinfo(&stat, getpid());
    printf(2, "this is j: %d run %d times\n", j, stat.num_run);
}


int main() {
    int pid;
    pid = fork();
    if(pid == 0) 
    {
        loop(50000);
        exit();
    }
    else
    {
        int pid2;
        if((pid2 = fork()) == 0) {
            loop(50000);
            exit();
        } 
        else {
            int pid3;
            if((pid3 = fork()) == 0) {
                loop(50000);
                exit();
            }
            else {
                int pid4;
                if((pid4 = fork()) == 0) {
                    loop(50000);
                    exit();
                }
                else {
                    // printf(2, "I am the parent and I am exiting with children %d, %d, %d, %d\n", pid, pid2, pid3, pid4);
                    exit();
                }
            }
        }
    }
}