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
}