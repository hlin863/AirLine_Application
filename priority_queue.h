#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

    struct PriorityQueue {
        int* priority;
        int* data;
        int capacity;
        int index;
    };

    struct PriorityQueue* createPriorityQueue(int capacity);

    struct PriorityQueue *destroyPriorityQueue(struct PriorityQueue* queue);

    struct PriorityQueue *enqueue(struct PriorityQueue* queue, int value, int priority);

    struct PriorityQueue *dequeue(struct PriorityQueue* queue);

    void displayPriorityQueue(struct PriorityQueue* queue);

#endif