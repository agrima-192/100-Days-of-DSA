#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    struct Node *head = NULL, *temp, *newNode;

    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    head = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d", &head->data);
    head->next = NULL;
    temp = head;

    for (int i = 1; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
