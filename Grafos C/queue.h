typedef struct queue{
    int capacity;
    int length;
    int first;
    int *q;
    int free_i;
} *Queue;

void dynamizeQueue (Queue *q);
void undynamizeQueue (Queue *q);

int queueEmpty (Queue q);
int queueFront (Queue q);
int queueSize (Queue q);

Queue initQueue (int size);
void clearQueue (Queue *q);
void delQueue (Queue *q);

int queueDequeue (Queue *q, int *x);
void queueEnqueue (Queue *q, int x);

void printQueue (Queue q);
