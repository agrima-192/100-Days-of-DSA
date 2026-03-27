#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Pair {
    struct Node* node;
    int hd;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    struct Pair q[1000];
    int front = 0, rear = 0;
    int hdArr[1000];
    int valArr[1000];
    int count = 0;

    q[rear].node = root;
    q[rear].hd = 0;
    rear++;

    while (front < rear) {
        struct Pair cur = q[front++];
        struct Node* temp = cur.node;
        int hd = cur.hd;

        hdArr[count] = hd;
        valArr[count] = temp->data;
        count++;

        if (temp->left != NULL) {
            q[rear].node = temp->left;
            q[rear].hd = hd - 1;
            rear++;
        }
        if (temp->right != NULL) {
            q[rear].node = temp->right;
            q[rear].hd = hd + 1;
            rear++;
        }
    }

    int minHd = 0, maxHd = 0;
    for (int i = 0; i < count; i++) {
        if (hdArr[i] < minHd) minHd = hdArr[i];
        if (hdArr[i] > maxHd) maxHd = hdArr[i];
    }

    for (int i = minHd; i <= maxHd; i++) {
        int printed = 0;
        for (int j = 0; j < count; j++) {
            if (hdArr[j] == i) {
                printf("%d ", valArr[j]);
                printed = 1;
            }
        }
        if (printed) printf("\n");
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    verticalOrder(root);

    return 0;
}
