#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int getHeight(struct Node* node) {
    if (node == NULL) {
        return -1;
    }
    
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    int n, val;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node* root = NULL;
    
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &val) == 1) {
            if (root == NULL) {
                root = newNode(val);
            }
        }
    }

    printf("%d\n", getHeight(root));

    return 0;
}
