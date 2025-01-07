// Implementation of Linear Queue.

#include <stdio.h>
#define MAX 5
struct LinearQueue
{
    int FRONT;
    int REAR;
    int DATA[MAX];
};

typedef struct LinearQueue LQ;

void enqueue(LQ *Q, int element)
{
    if (Q->REAR == MAX - 1)
        printf("Queue is FULL\n");
    else
    {
        Q->REAR++;
        Q->DATA[Q->REAR] = element;
        printf("Element was ENQUEUED\n");
    }
}

int dequeue(LQ *Q)
{
    int element = -1;
    if (Q->FRONT > Q->REAR)
        printf("Queue is EMPTY\n");
    else
    {
        element = Q->DATA[Q->FRONT];
        Q->FRONT++;
    }
    return element;
}

int main()
{
    int choice, data;
    LQ Q = {0, -1};
    do
    {
        printf("1. Enqueue\n2. Dequeue\n3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &data);
            enqueue(&Q, data);
            break;
        case 2:
            data = dequeue(&Q);
            if (data != -1)
                printf("DEQUEUED element is %d\n", data);
            break;
        case 3:
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 3);
    return 0;
}