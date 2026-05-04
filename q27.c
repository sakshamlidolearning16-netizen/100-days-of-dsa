#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;
    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

int length(struct node *head) {
    int count = 0;
    while(head) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct node *head1 = createList(n);

    scanf("%d", &m);
    struct node *head2 = createList(m);

    int l1 = length(head1);
    int l2 = length(head2);

    struct node *p1 = head1;
    struct node *p2 = head2;

    if(l1 > l2) {
        for(int i = 0; i < l1 - l2; i++)
            p1 = p1->next;
    } else {
        for(int i = 0; i < l2 - l1; i++)
            p2 = p2->next;
    }

    while(p1 && p2) {
        if(p1->data == p2->data) {
            printf("%d", p1->data);
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    printf("No Intersection");
    return 0;
}