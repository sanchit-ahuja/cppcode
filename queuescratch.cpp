#include<bits/stdc++.h>
using namespace std;

struct Queue
{
    int front, rear, size;
    int* arr;
    unsigned capacity;
};


struct Queue* createQueue(unsigned capacity) 
{ 
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0;  
    queue->rear = capacity - 1;  // This is important, see the enqueue 
    queue->arr = (int*) malloc(queue->capacity * sizeof(int)); 
    return queue; 
} 
  