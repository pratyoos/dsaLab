// Implementation of Circular Queue.

#include<stdio.h>
#define MAX 5
struct CircularQueue
{
    int FRONT;
    int REAR;
    int DATA[MAX];
};

typedef struct CircularQueue CQ;

void enqueue(CQ *Q, int element)
{
    if (Q->FRONT == (Q->REAR+1) % MAX)
        printf("Queue is FULL\n");
    else
    {
        Q->DATA[Q->REAR] = element;
        Q->REAR = (Q->REAR+1)% MAX;
        printf("Element was ENQUEUED\n");
    }
}

int dequeue(CQ *Q)
{
    int element = -1;
    if(Q->FRONT == Q->REAR)
        printf("Queue is EMPTY\n");
    else
    {
        element = Q->DATA[Q->FRONT];
        Q->FRONT = (Q->FRONT + 1)% MAX;
    }
    return element;
}

int main()
{
    int choice, data;
    CQ Q = {0,0};
    do
    {
        printf("1. Enqueue\n2. Dequeue\n3. Exit\n");
        printf("Choice: ");
        scanf("%d",&choice);
        switch(choice)
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
        }
    } while (choice!=3);
    return 0;
}