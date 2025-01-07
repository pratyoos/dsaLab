// Implmentation of singly linked list.

#include<stdio.h>
#include<stdlib.h>

struct SLL
{
    int data;
    struct SLL *next;
};

struct SLL *first, *last = NULL;

struct SLL* createNode(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));

    if(NewNode==NULL)
        return NULL;

    else
    {
        NewNode->data = element;
        NewNode->next = NULL;
        return NewNode;
    }
}

void insertAtBeginning(int element)
{
    struct SLL *NewNode = createNode(element);
    if(NewNode == NULL)
        printf("Memory allocation failed.\n");
    else
    {
        if(first == NULL)
        {
            first = last = NewNode;
        }
        else
        {
            NewNode->next = first;
            first = NewNode;
        }
        printf(" %d was inserted into the beginning of linked list.\n", first->data);
    }
}

void insertAtEnd(int element)
{
    struct SLL *NewNode = createNode(element);
    if(NewNode == NULL)
        printf("Memory allocation failed.\n");
    else
    {
        if(first == NULL)
        {
            first = NewNode;
            last = NewNode;
        }
        else
        {
            last->next = NewNode;
            last = NewNode;
        }
        printf(" %d was inserted into the end of linked list.\n", last->data);
    }
}

void insertAtSpecificPos(int element, int pos)
{
    struct SLL *NewNode = createNode(element);
    struct SLL *temp;
    if(NewNode == NULL)
        printf("Memory allocation failed.\n");

    if(pos == 1)
    {
        NewNode->next = first;
        first = NewNode;
    }

    else
    {
        temp = first;
        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp -> next;
        }
        NewNode->next = temp->next;
        temp->next = NewNode;
    }
    printf(" %d was inserted at %dth position\n", element, pos);
}

int deleteFromBeginning()
{
    struct SLL *temp;
    int element = -1;
    if(first == NULL)
        printf("List is empty");
    
    else if(first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    }

    else
    {
        temp = first;
        first = first ->next;
        element = temp->data;
        free(temp);
    }
    return element;
}

int deleteFromEnd()
{
    struct SLL *temp;
    int element = -1;
    if(first == NULL)
        printf("List is empty");
    
    else if(first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        element = temp -> data;
        free(temp);
    }

    else
    {
        temp = first;
        while (temp->next != last)
            temp = temp -> next;     
        last = temp;
        temp = temp -> next;
        element = temp -> data;
        free(temp);
        last -> next = NULL;
    }
    return element;
}


void deleteFromSpecificPos(int pos)
{
    struct SLL *temp, *tempp;

    if (first == NULL)
    {
        printf("List is empty.\n");
    }

    else if(first->next == NULL)
    {
        temp = first;
        temp = NULL;
        first = last = NULL;
    }

    else
    {
        temp = first;
        for (int i = 1; i < pos - 1 ; i++)
        {
            temp = temp -> next;
        }
        tempp = temp -> next;
        temp -> next = tempp -> next;
        free(tempp);   
    }
    printf(" The element from %dth position was removed.\n", pos);
}

void display()
{
    struct SLL *temp;
    if(first == NULL)
        printf("List is empty.");
    else
    {
        temp = first;
        do
        {
            printf(" %d -> ", temp -> data);
            temp = temp -> next;
        } while (temp != NULL);
        printf("NULL\n ");
    }
}

int main()
{
    int data;

    insertAtBeginning(100);
    display();

    insertAtEnd(200);
    display();
    
    // data = deleteFromBeginning();
    // if (data != -1)
    // {
    //     printf(" %d was deleted from the beginning.\n", data);
    // }
    // display();

    // data = deleteFromEnd();
    // if (data != -1)
    // {
    //     printf(" %d was deleted from the end.\n", data);
    // }
    // display();

    insertAtSpecificPos(4,2);
    display();

    deleteFromSpecificPos(3);
    display();
    return 0;
}