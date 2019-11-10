#include "types.h"
#include "stat.h"
#include "pstat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    if(argc <= 1) {
        printf(2, "No pid provided!\n");
        printf(2, "Usage: getpinfotest <pid>\n");
    }
    else {
        int x = atoi(argv[1]);
        printf(2, "Printing info for pid %d [", x);
        struct proc_stat info;
        if(getpinfo(&info, x) == 1) {
            printf(2, "%s]:\n", info.name);
            printf(2, "pid: %d\nruntime: %d\nnum_run: %d\n", info.pid, info.runtime, info.num_run);
            #ifdef MLFQ
            printf(2, "current_queue: %d\nticks on 0: %d 1: %d 2: %d 3: %d 4: %d\n", info.current_queue, info.ticks[0], info.ticks[1], info.ticks[2], info.ticks[3], info.ticks[4]);
            #endif
        }
        else {
            printf(2, "Failed!\n");
        }

    }
    exit();
}