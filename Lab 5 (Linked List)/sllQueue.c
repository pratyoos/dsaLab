// Implementation of Queue using Singly Linked List.

#include <stdio.h>  
#include <stdlib.h>

struct SLL
{
    int data;
    struct SLL *next;
};

struct SLL *front = NULL;
struct SLL *rear = NULL;

struct SLL *createNode(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL *)malloc(sizeof(struct SLL));

    if (NewNode == NULL)
        return NULL;

    else
    {
        NewNode->data = element;
        NewNode->next = NULL;
        return NewNode;
    }
}

void enqueue(int element)
{
    struct SLL *NewNode = createNode(element);
    if (NewNode == NULL)
        printf("Memory allocation failed.\n");
    else
    {
        if (front == NULL)
        {
            front = rear = NewNode;
        }
        else
        {
            rear->next = NewNode;
            rear = NewNode;
        }
        printf(" %d was enqueued into the queue.\n", rear->data);
    }
}

int dequeue()
{
    struct SLL *temp;
    int element = -1;
    if (front == NULL)
        printf("Queue is empty.\n");

    else
    {
        temp = front;
        front = front->next;
        element = temp->data;
        free(temp);
    }
    return element;
}

void display()
{
    struct SLL *temp;
    if (front == NULL)
        printf("Queue is empty.\n");
    else
    {
        temp = front;
        while (temp != NULL)
        {
            printf(" %d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int choice, element;
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be enqueued: ");
            scanf("%d", &element);
            enqueue(element);
            break;

        case 2:
            element = dequeue();
            if (element != -1)
                printf(" %d was dequeued from the queue.\n", element);
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}