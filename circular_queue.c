#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int *array;
    int size,capacity, front, rear;

}queue;

queue* create_queue(int capacity){
queue* q = (queue*)malloc(sizeof(queue));
if (!q) {
    printf("Memory allocation failed for queue\n");
    return NULL;
}
q->array = (int*)malloc(capacity * sizeof(int));
if (!q->array) { 
    printf("Memory allocation failed for queue array\n");
    free(q);
    return NULL;
}
q->capacity = capacity;
q->front = q->size=0;
q->rear = capacity-1;

return q;
}
int is_full(queue* q){
    return (q->size == q->capacity);
}
int is_empty(queue* q){
    return (q->size == 0);
}

void enqueue(queue* q,int data){
    if (is_full(q)){
        printf("Queue is full,cannot enqueue %d\n",data);
        return;
    }
    q->rear = (q->rear+1)%q->capacity;
    q->array[q->rear] = data;
    q->size++;
    printf("Enqueued: %d\n",data);
}

int dequeue(queue* q){
    if (is_empty(q)){
        printf("Queue is empty,cannot dequeue \n");
        return -1;
    }
    int data = q->array[q->front];
    q->size--;
    q->front = (q->front+1)%q->capacity;
    printf("dequeued: %d\n",data);
    return data;
}

int peek(queue* q){
    if(is_empty(q)){
        printf("Queue is empty!\n");
        return -1;
    }
 return q->array[q->front];
}

void display(queue* q){
    if (!q) {
        printf("Queue is not initialized.\n");
        return;
    }
    if(is_empty(q)){
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue:");
    for(int i=0;i<q->size;i++){
        int index= (q->front+i)%q->capacity;
        printf("\n%d",q->array[index]);
    }
    printf("\n");
}
void free_queue(queue** q) {
    if (*q) {
        free((*q)->array);
        free(*q);
        *q = NULL;
    }
}
    

int main() {
    queue* q = create_queue(5);
    if (!q) return 1;
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60); 
    display(q);
    printf("Front: %d\n",peek(q));
    dequeue(q);
    dequeue(q);
    display(q);
    enqueue(q, 60);
    enqueue(q, 70);
    display(q);
    free_queue(&q);
    display(q);
 
}
