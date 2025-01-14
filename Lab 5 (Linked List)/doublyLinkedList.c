// Implementation of Doubly Linked List.

#include <stdio.h>
#include <stdlib.h>

struct DLL {
    int data;
    struct DLL *next;
    struct DLL *prev;
};

struct DLL *first, *last = NULL;

struct DLL* createNode(int element) {
    struct DLL *NewNode;
    NewNode = (struct DLL*)malloc(sizeof(struct DLL));
    if (NewNode == NULL)
        return NULL;
    else {
        NewNode->data = element;
        NewNode->next = NULL;
        NewNode->prev = NULL;
        return NewNode;
    }
}

void insertAtBeginning(int element) {
    struct DLL *NewNode = createNode(element);
    if (NewNode == NULL)
        printf("Memory allocation failed.\n");
    else {
        if (first == NULL) {
            first = last = NewNode;
        } else {
            NewNode->next = first;
            first->prev = NewNode;
            first = NewNode;
        }
        printf(" %d was inserted at the beginning.\n", first->data);
    }
}

void insertAtEnd(int element) {
    struct DLL *NewNode = createNode(element);
    if (NewNode == NULL)
        printf("Memory allocation failed.\n");
    else {
        if (first == NULL) {
            first = last = NewNode;
        } else {
            last->next = NewNode;
            NewNode->prev = last;
            last = NewNode;
        }
        printf(" %d was inserted at the end.\n", last->data);
    }
}

void insertAtSpecificPos(int element, int pos) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct DLL *NewNode = createNode(element);
    if (NewNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    if (pos == 1) {
        NewNode->next = first;
        if (first != NULL)
            first->prev = NewNode;
        first = NewNode;
        if (last == NULL)
            last = NewNode;
    } else {
        struct DLL *temp = first;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        NewNode->next = temp->next;
        NewNode->prev = temp;
        if (temp->next != NULL)
            (temp->next)->prev = NewNode;
        temp->next = NewNode;
        if (NewNode->next == NULL)
            last = NewNode;
    }
    printf(" %d was inserted at %dth position.\n", element, pos);
}

int deleteFromBeginning() {
    struct DLL *temp;
    int element = -1;
    if (first == NULL) {
        printf("List is empty.\n");
    } else {
        temp = first;
        element = temp->data;
        first = first->next;
        if (first != NULL)
            first->prev = NULL;
        else
            last = NULL;
        free(temp);
    }
    return element;
}

int deleteFromEnd() {
    struct DLL *temp;
    int element = -1;
    if (last == NULL) {
        printf("List is empty.\n");
    } else {
        temp = last;
        element = temp->data;
        last = last->prev;
        if (last != NULL)
            last->next = NULL;
        else
            first = NULL;
        free(temp);
    }
    return element;
}

void deleteFromSpecificPos(int pos) {
    if (pos < 1) 
        printf("Invalid position.\n");
    if (first == NULL) 
        printf("List is empty.\n");
    struct DLL *temp;
    if (pos == 1) {
        temp = first;
        first = first->next;
        if (first != NULL)
            first->prev = NULL;
        else
            last = NULL;
    } else {
        temp = first;
        for (int i = 1; i < pos; i++)
            temp = temp->next;

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        if (temp == last)
            last = temp->prev;
    }
    printf(" %d was removed from position %d.\n", temp->data, pos);
    free(temp);
}

void display() {
    struct DLL *temp;
    if (first == NULL)
        printf("List is empty.\n");
    else {
        temp = first;
        while (temp != NULL) {
            printf(" %d <-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int data;
    insertAtBeginning(100);
    display();
    insertAtEnd(200);
    display();
    insertAtBeginning(500);
    display();

    data = deleteFromBeginning();
    if (data != -1) {
        printf(" %d was deleted from the beginning.\n", data);
    }
    display();
    data = deleteFromEnd();
    if (data != -1) {
        printf(" %d was deleted from the end.\n", data);
    }
    display();

    // insertAtSpecificPos(4, 2);
    // display();

    // deleteFromSpecificPos(3);
    // display();

    return 0;
}