
#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
int n;

void enqueue(int x)
{
    if((rear + 1) % n == front)
        return; // Queue Full

    if(front == -1)
        front = 0;

    rear = (rear + 1) % n;
    queue[rear] = x;
}

void dequeue()
{
    if(front == -1)
        return; // Queue Empty

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % n;
    }
}

void display()
{
    if(front == -1)
        return;

    int i = front;

    while(1)
    {
        printf("%d ", queue[i]);
        if(i == rear)
            break;
        i = (i + 1) % n;
    }
}

int main()
{
    int m, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        dequeue();
    }

    display();

    return 0;
}
