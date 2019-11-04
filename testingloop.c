#include "types.h"
#include "stat.h"
#include "user.h"

void loop(void) {
    volatile int i = 0, j = 0;
    for(i=0; i<4000000000; i++) 
    {
        j++;
    }
    printf(2, "this is j %d\n", j);
}


int main() {
    int pid;
    pid = fork();
    if(pid == 0) 
    {
        loop();
        exit();
    }
    else
    {
        printf(2, "I am the parent and I am exiting\n");
        exit();
    }
}