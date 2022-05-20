#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *top = NULL;

// void push(int value) {
//     Node *newNode;
//     newNode = (Node *) malloc(sizeof(Node));
//     newNode->value = value;

//     if (top == NULL) {
//         newNode->next = NULL;
//     } else {
//         newNode->next = top;
//     }
//     top = newNode;
// }

// int pop() {
//     if (top == NULL) {
//         printf("Stack underflow\n");
//     } else {
//         Node *temp = top;
//         int tempData = top->value;
//         top = top->next;
//         free(temp);
//         return tempData;
//     }
// }

void push(Node **stack, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;

    if (*stack == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = *stack;
    }
    *stack = newNode;
}

int pop(Node **stack) {
    if (*stack == NULL) {
        printf("Stack is empty\n");
    } else {
        Node *temp = *stack;
        int tempData = (*stack)->value;
        *stack = (*stack)->next;
        free(temp);
        return tempData;
    }
}

void showStack(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}

int main() {
    // for (int i = 0; i < 5; i++) {
    //     push(i);
    // }
    // showStack(top);
    // printf("\n");
    // pop();
    // pop();
    // showStack(top);

    Node *stack = NULL;
    for (int i = 0; i < 5; i++) {
        push(&stack, i);
    }
    showStack(stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    printf("\n");
    showStack(stack);

    return 0;
}