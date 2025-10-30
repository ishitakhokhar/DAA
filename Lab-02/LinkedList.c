#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

// Insert at the beginning
void insertAtBeginning(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("%d inserted at beginning.\n", data);
}

// Insert at the end
void insertAtEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%d inserted at end.\n", data);
}

// Delete from the beginning
void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    else
    {
        struct Node *temp = head;
        int deletedData = temp->data;
        head = head->next;
        free(temp);
        printf("%d deleted from beginning.\n", deletedData);
    }
}

// Delete from the end
void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL)
    {
        printf("%d deleted from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    printf("%d deleted from end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}
void traverse()
{
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtBeginning(5);

    traverse();

    deleteFromBeginning();
    deleteFromEnd();

    traverse();

    return 0;
}