#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node{
    int data;
    struct node *left, *right;
};

struct node* createNode(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* queue[MAX];
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

int main(){
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct node* nodes[n];

    for(int i=0;i<n;i++){
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    for(int i=0;i<n;i++){
        if(nodes[i] != NULL){
            int l = 2*i + 1;
            int r = 2*i + 2;

            if(l < n) nodes[i]->left = nodes[l];
            if(r < n) nodes[i]->right = nodes[r];
        }
    }

    struct node* root = nodes[0];
    if(root == NULL) return 0;

    enqueue(root);

    int leftToRight = 1;

    while(!isEmpty()){
        int size = rear - front + 1;
        int level[size];

        for(int i=0;i<size;i++){
            struct node* temp = dequeue();

            int index = leftToRight ? i : (size - 1 - i);
            level[index] = temp->data;

            if(temp->left) enqueue(temp->left);
            if(temp->right) enqueue(temp->right);
        }

        for(int i=0;i<size;i++)
            printf("%d ", level[i]);

        leftToRight = !leftToRight;
    }

    return 0;
}