#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node* createNode(int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int val)
{
    if(root == NULL)
        return createNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void inorder(struct node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int n, x;
    scanf("%d",&n);

    struct node* root = NULL;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        root = insert(root, x);
    }

    inorder(root);

    return 0;
}