#include <stdio.h>
#include <stdlib.h>

// Basic Linked List Structure
struct LinkedList {
    int data; // for storing numbers
    struct LinkedList *next; // for storing the address of the next node
};

typedef struct LinkedList LL;

void insertElementAtFirst(LL **first, LL **last, int data) {
    LL *newNode = (LL *)malloc(sizeof(LL));
    newNode->data = data;
    newNode->next = NULL;

    if(*first == NULL) {
        *first = *last = newNode;
    } else {
        newNode->next = *first;
        *first = newNode;
    }
}

void insertElementAtLast(LL **first, LL **last, int data) {
    LL *newNode = (LL *)malloc(sizeof(LL));
    newNode->data = data;
    newNode->next = NULL;

    if(*first == NULL) {
        *first = *last = newNode;
    } else {
        (*last)->next = newNode;
        *last = newNode;
    }
}

void insertElementAtPosition(LL **first, LL **last, int data, int position) {
    LL *newNode = (LL *)malloc(sizeof(LL));
    newNode->data = data;
    newNode->next = NULL;

    if(*first == NULL) {
        *first = *last = newNode;
    } else {
        LL *temp = *first;
        for(int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void removeFirstElement(LL **first, LL **last) {
    if(*first == NULL) {
        printf("List is empty\n");
    } else {
        LL *temp = *first;
        *first = (*first)->next;
        free(temp);
    }
}

void removeLastELement(LL **first, LL **last) {
    if(*first == NULL) {
        printf("List is empty\n");
    } else {
        LL *temp = *first;
        while(temp->next != *last) {
            temp = temp->next;
        }
        temp->next = NULL;
        free(*last);
        *last = temp;
    }
}

void removeElementAtPosition(LL **first, LL **last, int position) {
    if(*first == NULL) {
        printf("List is empty\n");
    } else {
        LL *temp = *first;
        for(int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        LL *temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }
}


int main() {
    LL *first, *last;
    first = last = NULL; 

    // Inserting the first element
    // insertElementAtFirst(&first, &last, 10);
    // insertElementAtFirst(&first, &last, 20);
    // insertElementAtFirst(&first, &last, 30);
    // insertElementAtFirst(&first, &last, 40);


    // Inserting element at last
    // insertElementAtLast(&first, &last, 30);
    // insertElementAtLast(&first, &last, 40);

    // Inserting element at a specific position
    // insertElementAtPosition(&first, &last, 50, 2);
    // insertElementAtPosition(&first, &last, 60, 4);

    // Removing the first element
    // removeFirstElement(&first, &last);

    // Removing the last element
    // removeLastELement(&first, &last);

    // Removing the element at a specific position
    // removeElementAtPosition(&first, &last, 2);

    // printing the elements in the list
    for(LL *i = first; i != NULL; i = i->next) {
        printf("%d\n", i->data);
    }

    return 0;
}