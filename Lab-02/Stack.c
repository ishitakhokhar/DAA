#include <stdio.h>
#include <stdlib.h>

#define Size 100
int Stack[Size];
int top = -1;

void push(int value)
{
    if (top == Size - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        Stack[++top] = value;
        printf("%d pushed to stack\n", value);
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        int poppedValue = Stack[top--];
        printf("%d popped from stack\n", poppedValue);
        return poppedValue;
    }
}

int peep()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return Stack[top];
    }
}
void change(int positionFromTop, int newValue)
{
    int index = top - positionFromTop + 1;
    if (index < 0 || index > top)
    {
        printf("Invalid position: %d\n", positionFromTop);
    }
    else
    {
        printf("Value at position %d (index %d) changed from %d to %d\n",
               positionFromTop, index, Stack[index], newValue);
        Stack[index] = newValue;
    }
}
void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", Stack[i]);
        }
    }
}

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == Size - 1;
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    display();

    printf("\nPeep top element: %d\n", peep());

    printf("\nChanging 2nd element from top to 99:\n");
    change(2, 99);

    display();

    printf("\nPopping top element: %d\n", pop());

    display();

    return 0;
}