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

struct node* mergeLists(struct node *l1, struct node *l2) {
    struct node *head = NULL, *tail = NULL, *temp;

    while(l1 && l2) {
        if(l1->data <= l2->data) {
            temp = l1;
            l1 = l1->next;
        } else {
            temp = l2;
            l2 = l2->next;
        }
        temp->next = NULL;
        if(head == NULL) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    if(l1)
        tail->next = l1;
    if(l2)
        tail->next = l2;

    return head;
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct node *list1 = createList(n);

    scanf("%d", &m);
    struct node *list2 = createList(m);

    struct node *merged = mergeLists(list1, list2);

    while(merged) {
        printf("%d ", merged->data);
        merged = merged->next;
    }

    return 0;
}