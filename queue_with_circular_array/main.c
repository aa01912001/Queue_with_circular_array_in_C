/*
Date: 2020/02/02
Author: Ian
Object: implement circular queue
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE 100
int FRONT = 0;
int REAR = 0;
int TAG = 0; // tag variable is a flag to determine if queue is currently full or not.

int* create(void);
int isFull(void);
int isEmpty(void);
void enqueue(int [], int);
int dequeue(int []);

int* create(void){ // dynamically allocate memory for queue.
    return (int *)malloc(sizeof(int)*MAX_QUEUE);
}

int isFull(void){ // determine if queue is full.
    return FRONT==REAR && TAG==1;
}

int isEmpty(void){ // determine if queue is empty.
    return FRONT==REAR && TAG==0;
}

void enqueue(int queue[], int item){ // insert an item into queue.
    if(isFull()){
        printf("Queue is full!!\n");
        return;
    }
    REAR = (REAR + 1) % MAX_QUEUE;
    queue[REAR] = item;
    if(FRONT == REAR) TAG = 1; // if FRONT == REAR after inserting item, set TAG = 1.
    printf("insert %d into queue[%d]\n", item, REAR);
    return;
}

int dequeue(int queue[]){ // take an item from queue.
    if(isEmpty()){
        printf("Queue is empty!!\n");
        exit(1);
    }
    FRONT = (FRONT + 1) % MAX_QUEUE;
    int item = queue[FRONT];
    if(FRONT==REAR) TAG = 0; // if FRONT == REAR after taking item, set TAG = 0.
    printf("take %d from queue[%d]\n", item, FRONT);
    return item;
}

int main()
{
    int *queue = create();

    int i;
    for(i=1; i<=100; i++){ // insert 100 items.
        enqueue(queue, i);
    }

    enqueue(queue, 100);

    for(i=1; i<=100; i++){ // take 100 items.
        dequeue(queue);
    }

    dequeue(queue);

    free(queue); // release memory occupied by queue.
    return 0;
}
