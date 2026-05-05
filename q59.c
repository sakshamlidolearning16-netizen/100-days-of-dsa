#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Helper to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Find index of root in the Inorder array
int findIndex(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

// Build the tree using Inorder and Postorder
struct Node* buildTree(int in[], int post[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) return NULL;

    // The root is the element at current postIndex in postorder array
    struct Node* root = newNode(post[(*postIndex)--]);

    if (inStart == inEnd) return root;

    // Find position of this root in inorder array to split subtrees
    int inIndex = findIndex(in, inStart, inEnd, root->data);

    /* 
       IMPORTANT: Build RIGHT subtree first because we are 
       moving backwards through the postorder array.
    */
    root->right = buildTree(in, post, inIndex + 1, inEnd, postIndex);
    root->left = buildTree(in, post, inStart, inIndex - 1, postIndex);

    return root;
}

// Print Preorder traversal
void printPreorder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int in[n], post[n];
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);

    int postIndex = n - 1;
    struct Node* root = buildTree(in, post, 0, n - 1, &postIndex);

    printPreorder(root);

    return 0;
}