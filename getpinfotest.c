#include "types.h"
#include "stat.h"
#include "pstat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    if(argc <= 1) {
        printf(2, "No pid provided!\n");
    }
    else {
        int x = atoi(argv[1]);
        printf(2, "Printing info for pid %d:\n", x);
        struct proc_stat info;
        if(getpinfo(&info, x) == 1) {
            printf(2, "pid: %d\nruntime: %d\nnum_run: %d\n", info.pid, info.runtime, info.num_run);
        }
        else {
            printf(2, "Failed!\n");
        }

    }
    exit();
}