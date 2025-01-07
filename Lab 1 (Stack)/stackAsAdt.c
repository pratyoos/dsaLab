//Structure to represent a stack as an abstract data type (ADT).

#include <stdio.h>

#define SIZE 5

struct Stack {
    int data[SIZE];
    int top;
};

void initialize(struct Stack* s) {
    s->top = -1;
}

int is_full(struct Stack* s) {
    return s->top == SIZE - 1;
}

int is_empty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int value) {
    if (is_full(s)) {
        printf("Overflow!\n");
    } else {
        s->data[++s->top] = value;
    }
}

int pop(struct Stack* s) {
    if (is_empty(s)) {
        printf("Underflow!\n");
        return -1; // Return -1 if stack is empty
    } else {
        return s->data[s->top--];
    }
}

int peek(struct Stack* s) {
    if (is_empty(s)) {
        printf("Stack is empty!\n");
        return -1; // Return -1 if stack is empty
    } else {
        return s->data[s->top];
    }
}

int main() {
    struct Stack s;
    initialize(&s);

    int choice, value;

    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (is_full(&s)) {
                    printf("Stack full.\n");
                } else {
                    printf("Enter value: ");
                    scanf("%d", &value);
                    push(&s, value);
                }
                break;

            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Removed: %d\n", value);
                }
                break;

            case 3:
                value = peek(&s);
                if (value != -1) {
                    printf("Top: %d\n", value);
                }
                break;

            case 4:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}