#include <stdio.h>
#include <stdlib.h>

#define Size 100
int Queue[Size];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % Size == front)
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % Size;
        Queue[rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue underflow\n");
        return -1;
    }
    else
    {
        int dequeuedValue = Queue[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % Size;
        }
        printf("%d dequeued from queue\n", dequeuedValue);
        return dequeuedValue;
    }
}

int peek()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        return Queue[front];
    }
}

int isEmpty()
{
    return front == -1;
}

int isFull()
{
    return (rear + 1) % Size == front;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Front element is %d\n", peek());

    dequeue();
    printf("Front element is %d\n", peek());

    dequeue();
    dequeue();

    if (isEmpty())
        printf("Queue is empty\n");

    return 0;
}
