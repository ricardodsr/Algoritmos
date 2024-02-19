#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* Change the size of the array. Based on the C Vector post implementation*/
void dynamizeQueue (Queue *q) {
    int *new = (int *) malloc (sizeof(int) * 2 * (*q) -> capacity);
    int i, j;
    for (i = 0, j = ( (*q) -> first); i < (*q) -> length; i++, j = (j+1)%( (*q) -> capacity) )
        new[i] = (*q)->q[j];
    free( (*q) -> q);
    (*q) -> q = new;
    (*q) -> capacity *= 2;
    (*q) -> first = 0;
    (*q) -> free_i = i;
    (*q) -> length = i;
}

void undynamizeQueue (Queue *q) {
    int *new = (int *) malloc (sizeof(int) * ((*q) -> capacity)/2);
    int i, j;
    for (i = 0, j = ( (*q) -> first); i < (*q) -> length; i++, j = (j+1)%( (*q) -> capacity) )
        new[i] = (*q)->q[j];
    free( (*q) -> q);
    (*q) -> q = new;
    (*q) -> capacity /= 2;
    (*q) -> first = 0;
    (*q) -> free_i = i;
    (*q) -> length = i;
}

int queueEmpty (Queue q) {
    return q -> length == 0;
}

int queueFront (Queue q) {
    if (! queueEmpty(q))
        return q -> q[ q -> first ];
    else
        return -1;
}

int queueSize (Queue q) {
    return q -> length;
}

Queue initQueue (int size) {
    Queue q = (Queue) malloc(sizeof(struct queue));
    int* a = (int*) malloc( sizeof(int)*size);

    q->capacity = size;
    q->length = 0;
    q->first = 0;
    q -> free_i = 0;
    q->q = a;

    return q;
}

void clearQueue (Queue *q) {
    (*q) -> q = (int *) realloc( (*q) -> q, sizeof(int) );
    (*q) -> q = NULL;
    (*q) -> capacity = 1;
    (*q) -> length = 0;
    (*q) -> first = 0;
    (*q) -> free_i = 0;
}


void delQueue (Queue *q) {
    free((*q)->q);
    (*q) -> q = NULL;
    (*q) -> capacity = -1;
    (*q) -> length = 0;
    (*q) -> first = 0;
    (*q) -> free_i = 0;
    free(*q);
}

int queueDequeue (Queue *q, int *x) {
    int result = 0;
    if (!queueEmpty(*q)) {

        *x = (*q) -> q[ (*q) -> first ];
        (*q) -> first = ( (*q) -> first + 1) % ( (*q) -> capacity );
        (*q) -> length--;

        if ( (*q) -> length <= ( (*q) -> capacity / 2 ) )
            undynamizeQueue(q);

        result = 1;
    }

    return result;
}

void queueEnqueue (Queue *q, int x) {
        (*q) -> q[(*q)->free_i] = x;

        (*q) -> free_i = ((*q) -> free_i+1) % ((*q) -> capacity);
        (*q) -> length++;

        if ( (*q) -> length >= ( (*q) -> capacity / 2 ) )
            dynamizeQueue(q);
}

void printQueue (Queue q) {
    int i, j;

    if (q->length <= 0) {
        printf("EMPTY\n");
        return ;
    }

    printf("CAP: %d\nSIZE: %d\nFIRST: %d\n", q->capacity, q->length, q->first);

    for (i = (q -> first), j = 0; j < q->length ; i = (i+1) % (q->capacity), j++)
        printf("%d, ", q->q[i]);
    putchar('\n');
}


/*int main() {
    int x;
    Queue q = initQueue(5);
    printQueue(q);

    queueEnqueue(&q, 1);
    queueEnqueue(&q, 2);
    queueEnqueue(&q, 3);
    printQueue(q); // should be 1, 2, 3

    queueDequeue(&q, &x);
    printQueue(q); // should be 2, 3

    queueDequeue(&q, &x);
    printQueue(q); // should be 3

    queueEnqueue(&q, 4);
    printQueue(q); // should be 3, 4

    clearQueue(&q); // should print EMPTY
    printQueue(q);

    delQueue(&q);
    printQueue(q); // should print EMPTY


    return 0;
}*/
