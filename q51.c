
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

struct node* LCA(struct node* root, int n1, int n2)
{
    if(root == NULL)
        return NULL;

    if(n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);

    if(n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);

    return root;
}

int main()
{
    int n, x, n1, n2;
    scanf("%d",&n);

    struct node* root = NULL;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        root = insert(root, x);
    }

    scanf("%d %d",&n1,&n2);

    struct node* ans = LCA(root, n1, n2);

    if(ans != NULL)
        printf("%d", ans->data);

    return 0;
}
