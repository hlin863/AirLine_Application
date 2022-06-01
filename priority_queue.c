#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

struct PriorityQueue* createPriorityQueue(int capacity){
    struct PriorityQueue *queue = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    queue->priority = (int*)malloc(sizeof(int) * capacity);
    queue->data = (int*)malloc(sizeof(int) * capacity);
    queue->capacity = capacity;
    queue->index = 0;

    return queue;
}

struct PriorityQueue *destroyPriorityQueue(struct PriorityQueue* queue){
    queue->index = 0;

    return queue;
}

struct PriorityQueue *enqueue(struct PriorityQueue* queue, int value, int priority){
    if (queue->index == queue->capacity){ // when the priority queue is full. 
        queue->capacity *= 2;
        queue->priority = (int*)realloc(queue->priority, sizeof(int) * queue->capacity);
    }

    // compares priority with the existing priority values in the queue.
    // if the new priority is higher, the new priority value is inserted at the end of the queue.
    // if the new priority is lower, the new priority value is inserted at the beginning of the queue.
    for (int i = 0; i < queue->index; i++){
        if (priority > queue->priority[i]){
            for (int j = queue->index; j > i; j--){
                queue->priority[j] = queue->priority[j - 1];
                queue->data[j] = queue->data[j - 1];
            }
            queue->priority[i] = priority;
            queue->data[i] = value;
            queue->index++;
            return queue;
        }
    }

    // if the queue has been sorted in priority order
    queue->priority[queue->index + 1] = priority;
    queue->data[queue->index + 1] = value;

    queue->index++; // increments the index of the queue.

    return queue;

}

struct PriorityQueue *dequeue(struct PriorityQueue* queue){

    if (queue->index == 0){
        return queue;
    }

    queue->index--;

    return queue;

}

void displayPriorityQueue(struct PriorityQueue* queue){

    // displays the order of priority values in the queue.
    for (int i = 0; i < queue->index; i++){
        printf("%d ", queue->data[i]);
    }
    printf("\n");

}