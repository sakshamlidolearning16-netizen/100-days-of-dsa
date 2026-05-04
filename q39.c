#include <stdio.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i)
{
    while(i > 0)
    {
        int parent = (i - 1) / 2;
        if(heap[parent] > heap[i])
        {
            swap(&heap[parent], &heap[i]);
            i = parent;
        }
        else
            break;
    }
}

void heapifyDown(int i)
{
    while(2*i + 1 < size)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = left;

        if(right < size && heap[right] < heap[left])
            smallest = right;

        if(heap[i] > heap[smallest])
        {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        }
        else
            break;
    }
}

void insert(int x)
{
    heap[size] = x;
    heapifyUp(size);
    size++;
}

int extractMin()
{
    if(size == 0)
        return -1;

    int min = heap[0];
    heap[0] = heap[size-1];
    size--;

    heapifyDown(0);

    return min;
}

int peek()
{
    if(size == 0)
        return -1;
    return heap[0];
}

int main()
{
    int N, x;
    char op[20];

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%s", op);

        if(strcmp(op,"insert") == 0)
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op,"extractMin") == 0)
        {
            printf("%d\n", extractMin());
        }
        else if(strcmp(op,"peek") == 0)
        {
            printf("%d\n", peek());
        }
    }

    return 0;
}