#include <stdio.h>
#include <stdlib.h>

struct SLL
{
    int data;
    struct SLL *next;
};

struct SLL *top = NULL;

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

void push(int element)
{
    struct SLL *NewNode = createNode(element);
    if (NewNode == NULL)
        printf("Memory allocation failed.\n");
    else
    {
        if (top == NULL)
            top = NewNode;
        else
        {
            NewNode->next = top;
            top = NewNode;
        }
        printf(" %d was pushed into the stack.\n", top->data);
    }
}

int pop()
{
    struct SLL *temp;
    int element = -1;
    if (top == NULL)
        printf("Stack is empty.\n");
    else
    {
        temp = top;
        top = top->next;
        element = temp->data;
        free(temp);
    }
    return element;
}

void display()
{
    struct SLL *temp;
    if (top == NULL)
        printf("Stack is empty.\n");
    else
    {
        temp = top;
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
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &element);
            push(element);
            break;

        case 2:
            element = pop();
            if (element != -1)
                printf(" %d was popped from the stack.\n", element);
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    return 0;
}