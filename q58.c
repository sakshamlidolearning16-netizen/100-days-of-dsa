#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Helper to create a node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Search function to find root index in Inorder array
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

// Core recursive function to build the tree
struct Node* buildTree(int in[], int pre[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return NULL;

    // Pick current node from Preorder traversal using preIndex
    struct Node* tNode = newNode(pre[(*preIndex)++]);

    // If this node has no children, return
    if (inStart == inEnd) return tNode;

    // Find the index of this node in Inorder traversal
    int inIndex = search(in, inStart, inEnd, tNode->data);

    // Build left and right subtrees
    tNode->left = buildTree(in, pre, inStart, inIndex - 1, preIndex);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);

    return tNode;
}

// Print Postorder traversal
void printPostorder(struct Node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int pre[n], in[n];
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);

    int preIndex = 0;
    struct Node* root = buildTree(in, pre, 0, n - 1, &preIndex);

    printPostorder(root);

    return 0;
}