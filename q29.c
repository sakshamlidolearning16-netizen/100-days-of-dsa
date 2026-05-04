#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n, k;
    scanf("%d", &n);

    struct node *head = NULL, *temp = NULL, *newnode;

    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL)
            head = temp = newnode;
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    scanf("%d", &k);

    if(head == NULL || k == 0)
        return 0;

    int len = 1;
    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
        len++;
    }

    k = k % len;
    if(k == 0)
        goto print;

    temp->next = head;

    temp = head;
    for(int i = 0; i < len - k - 1; i++)
        temp = temp->next;

    head = temp->next;
    temp->next = NULL;

print:
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}