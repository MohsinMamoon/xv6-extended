#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    if(argc <= 2) {
        printf(2, "Too few arguments!\n");
    }
    else {
        int prior = atoi(argv[1]);
        int pid = atoi(argv[2]);
        int old_prior = set_priority(prior, pid);
        if(old_prior != -1) {
            printf(1, "Priority of pid %d changed from %d to %d\n", pid, old_prior, prior);
        }
        else {
            printf(2, "There was an error!\n");
        }
    }
    exit();
}