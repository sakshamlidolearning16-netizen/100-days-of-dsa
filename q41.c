#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if(rear == NULL)
    {
        front = rear = newnode;
        return;
    }

    rear->next = newnode;
    rear = newnode;
}

int dequeue()
{
    if(front == NULL)
        return -1;

    struct node *temp = front;
    int val = temp->data;

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
    return val;
}

int main()
{
    int N, x;
    char op[20];

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%s", op);

        if(strcmp(op,"enqueue") == 0)
        {
            scanf("%d", &x);
            enqueue(x);
        }
        else if(strcmp(op,"dequeue") == 0)
        {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}