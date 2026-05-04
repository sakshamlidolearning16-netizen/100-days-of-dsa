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

struct node* queue[100];
int front = 0, rear = -1;

void enqueue(struct node* x){
    queue[++rear] = x;
}

struct node* dequeue(){
    return queue[front++];
}

int isEmpty(){
    return front > rear;
}

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct node* nodes[n];

    for(int i=0;i<n;i++)
    {
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        if(nodes[i] != NULL)
        {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];
            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    struct node* root = nodes[0];

    if(root == NULL)
        return 0;

    enqueue(root);

    while(!isEmpty())
    {
        struct node* temp = dequeue();
        printf("%d ", temp->data);

        if(temp->left != NULL)
            enqueue(temp->left);

        if(temp->right != NULL)
            enqueue(temp->right);
    }

    return 0;
}