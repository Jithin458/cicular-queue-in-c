Circular Queue Implementation in C

This repository contains an implementation of a Circular Queue in C, which provides efficient enqueue and dequeue operations using an array-based circular buffer.

Features

Dynamic memory allocation for the queue

Supports enqueue and dequeue operations

Handles overflow and underflow conditions

Implements a circular buffer to efficiently use memory

Peek function to check the front element

Display function to print the queue contents

Proper memory management with a cleanup function

Usage

Compilation

To compile the program, use:

gcc circular_queue.c -o circular_queue

Running the Program

Execute the compiled program:

./circular_queue

Example Output

Enqueued: 10
Enqueued: 20
Enqueued: 30
Enqueued: 40
Enqueued: 50
Queue is full, cannot enqueue 60
Queue:
10
20
30
40
50
Front: 10
dequeued: 10
dequeued: 20
Queue:
30
40
50
Enqueued: 60
Enqueued: 70
Queue:
30
40
50
60
70

Functions

queue* create_queue(int capacity);

Creates a circular queue with the given capacity.

void enqueue(queue* q, int data);

Adds an element to the queue if it is not full.

int dequeue(queue* q);

Removes an element from the queue if it is not empty.

int peek(queue* q);

Returns the front element without removing it.

void display(queue* q);

Displays the elements in the queue.

void free_queue(queue** q);

Frees allocated memory and resets the queue.

Contributing

Feel free to fork this repository, improve the code, and submit a pull request!

License

This project is open-source and available under the MIT License.

