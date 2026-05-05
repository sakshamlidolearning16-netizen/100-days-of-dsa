#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to mirror the tree recursively
void mirror(struct Node* node) {
    if (node == NULL) return;

    // Swap the pointers
    struct Node* temp = node->left;
    node->left = node->right;
    node->right = temp;

    // Recurse for children
    mirror(node->left);
    mirror(node->right);
}

// Standard Inorder Traversal
void printInorder(struct Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    if (n == 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Level-order construction using a queue-like array
    struct Node* root = newNode(arr[0]);
    struct Node* queue[n];
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n && head < tail) {
        struct Node* curr = queue[head++];

        if (curr != NULL) {
            // Assign left child
            curr->left = (i < n) ? newNode(arr[i++]) : NULL;
            if (curr->left) queue[tail++] = curr->left;

            // Assign right child
            curr->right = (i < n) ? newNode(arr[i++]) : NULL;
            if (curr->right) queue[tail++] = curr->right;
        }
    }

    mirror(root);
    printInorder(root);

    return 0;
}