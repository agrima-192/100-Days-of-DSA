#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int getCount(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void findIntersection(struct Node* head1, struct Node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d = abs(c1 - c2);

    struct Node* current1 = head1;
    struct Node* current2 = head2;

    if (c1 > c2) {
        for (int i = 0; i < d; i++) current1 = current1->next;
    } else {
        for (int i = 0; i < d; i++) current2 = current2->next;
    }

    while (current1 != NULL && current2 != NULL) {
        if (current1->data == current2->data) {
            printf("%d\n", current1->data);
            return;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    printf("No Intersection\n");
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* temp = newNode(val);
        if (!head1) head1 = tail1 = temp;
        else {
            tail1->next = temp;
            tail1 = temp;
        }
    }

    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        struct Node* temp = newNode(val);
        if (!head2) head2 = tail2 = temp;
        else {
            tail2->next = temp;
            tail2 = temp;
        }
    }

    findIntersection(head1, head2);

    return 0;
}

