#include <stdio.h>
#include <stdlib.h>

#define size 100
int Queue[size];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if (rear == size - 1)
    {
        printf("Queue Overflow\n");
    }
    else if (front == -1)
    {
        front = 0;
        rear++;
        Queue[rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}
int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue underflow\n");
        return -1;
    }
    else
    {
        int dequeuedValue = Queue[front];
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
        printf("%d dequeued from queue\n", dequeuedValue);
        return dequeuedValue;
    }
}
int peek()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    return Queue[front];
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Front element is %d\n", peek());

    dequeue();

    dequeue();
    dequeue();

    return 0;
}