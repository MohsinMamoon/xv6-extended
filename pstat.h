struct proc_stat {
  int pid;
  int runtime;
  int num_run;
  int ctime;
  int wtime;
  char name[16];
  #ifdef MLFQ
  int current_queue;
  int ticks[5];
  #endif
};
