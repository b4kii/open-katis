#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

Node *insertAtHead(int value) {
    Node *result = (Node *) malloc(sizeof(Node));

    result->value = value;
    result->next = NULL;

    return result;
}

int lastValue(Node *head) {
    Node *temp = head;
    int val;

    while (temp) {
        val = temp->value;
        temp = temp->next;
    }
    return val;
}

void showList(Node *head) {
    Node *temp = head;
    while (temp) {
        printf("%d", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {

    Node *head = NULL;
    Node *temp;
    for (int i = 0; i < 5; i++) {
        temp = insert(i);
        temp->next = head;
        head = temp;
    }

    // showList(head);
    printf("%d\n", lastValue(head));

    return 0;
}