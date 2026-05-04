#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct node *head = NULL, *temp = NULL, *newnode;

    for(int i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    temp->next = head;

    temp = head;
    if(head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);
    }

    return 0;
}