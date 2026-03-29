#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* buildTree(int arr[], int n) {
    if (n <= 0 || arr[0] == -1) return NULL;
    
    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int head = 0, tail = 0;
    queue[tail++] = root;
    
    int i = 1;
    while (head < tail && i < n) {
        struct Node* curr = queue[head++];
        
        if (i < n) {
            if (arr[i] != -1) {
                curr->left = newNode(arr[i]);
                queue[tail++] = curr->left;
            }
            i++;
        }
        
        if (i < n) {
            if (arr[i] != -1) {
                curr->right = newNode(arr[i]);
                queue[tail++] = curr->right;
            }
            i++;
        }
    }
    free(queue);
    return root;
}

void printRightView(struct Node* root, int n) {
    if (!root) return;

    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int head = 0, tail = 0;
    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head;

        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = queue[head++];

            if (i == levelSize - 1) {
                printf("%d ", curr->data);
            }

            if (curr->left) queue[tail++] = curr->left;
            if (curr->right) queue[tail++] = curr->right;
        }
    }
    free(queue);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    int *arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    printRightView(root, n);

    free(arr);
    return 0;
}
