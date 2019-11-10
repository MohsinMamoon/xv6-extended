
typedef struct queue {
    struct proc* arr[NPROC];
    int top;
    int tail;
}queue;

extern void enq(queue *que, struct proc* elem);//int *que, int elem, int *top, int *tail);
extern void deq(queue *que);//int *que, int *top, int *tail);
extern void print_q(queue *que);