#include "types.h"
#include "pstat.h"
#include "stat.h"
#include "user.h"

int NTEST = 4;

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
    printf(2, "this is %d with j = %d run %d times with total runtime: %d and total waittime: %d\n", stat.pid, j, stat.num_run, stat.runtime, stat.wtime);
}

void launchtest(int fcfs) {
    for(int i=0; i<NTEST; i++) {
        int pid = fork();
        if(pid == 0) {
            if(i < 2) loop(50000);
            else{
                if(fcfs == 1) loop(5000);
                else loop(50000);
            }
            exit();
        }
    }
    wait();
    exit();
}

int main(int argc, char *argv[]) {
    printf(2, "Usage: testingloop <no of loops> <FCFS or REST> <-1 to wait>\n");
    // if(argc > 1) printf(2, "%s\t", argv[1]);
    // if(argc > 2) printf(2, "%s\t", argv[2]);
    // if(argc > 3) printf(2, "%s\t", argv[3]);
    // if(argc > 3) printf(2, "%d\t", atoi(argv[3]));
    // printf(2, "\n");
    if(argc > 1) {
        NTEST = atoi(argv[1]);
    }
    if (fork() == 0) {
        if(argc > 2 && argv[2][0] == 'F')   launchtest(1);
        else launchtest(0);
        exit();
    }
    if(argc >= 3 && argv[3][0] == '-' && argv[3][1] == '1'){
        printf(2, "Will wait\n");
        int rtime, wtime;
        waitx(&wtime, &rtime);

        printf(2, "Test finshed with wtime: %d and rtime: %d\n", wtime, rtime);
    }
    exit();
}