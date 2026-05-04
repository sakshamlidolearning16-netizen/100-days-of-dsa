#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node{
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int x){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop(){
    if(top == NULL) return 0;
    struct node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int evaluate(char* exp){
    int i;
    char* token = strtok(exp, " ");
    
    while(token != NULL){
        
        if(isdigit(token[0]) || (token[0]=='-' && isdigit(token[1]))){
            push(atoi(token));
        }
        else{
            int b = pop();
            int a = pop();
            
            if(token[0] == '+') push(a + b);
            else if(token[0] == '-') push(a - b);
            else if(token[0] == '*') push(a * b);
            else if(token[0] == '/') push(a / b);
        }
        
        token = strtok(NULL, " ");
    }
    
    return pop();
}

int main(){
    char exp[100];
    
    fgets(exp, sizeof(exp), stdin);
    
    int result = evaluate(exp);
    
    printf("%d", result);
    
    return 0;
}