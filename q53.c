#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node{
    int data;
    struct node *left, *right;
};

struct pair{
    struct node* node;
    int hd;
};

struct node* createNode(int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct pair queue[MAX];
int front = 0, rear = -1;

void enqueue(struct node* n, int hd){
    queue[++rear].node = n;
    queue[rear].hd = hd;
}

struct pair dequeue(){
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

    int result[2*MAX][MAX];
    int count[2*MAX] = {0};

    int offset = MAX;

    enqueue(nodes[0], 0);

    while(!isEmpty())
    {
        struct pair temp = dequeue();
        struct node* curr = temp.node;
        int hd = temp.hd + offset;

        result[hd][count[hd]++] = curr->data;

        if(curr->left)
            enqueue(curr->left, temp.hd - 1);

        if(curr->right)
            enqueue(curr->right, temp.hd + 1);
    }

    for(int i=0;i<2*MAX;i++)
    {
        if(count[i] > 0)
        {
            for(int j=0;j<count[i];j++)
                printf("%d ", result[i][j]);
            printf("\n");
        }
    }

    return 0;
}