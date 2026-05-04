#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    return stack[top--];
}

char peek(){
    return stack[top];
}

int precedence(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

int main(){
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    scanf("%s", infix);

    for(i = 0; infix[i] != '\0'; i++){
        
        if(isalnum(infix[i])){
            postfix[j++] = infix[i];
        }
        else if(infix[i] == '('){
            push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(peek() != '('){
                postfix[j++] = pop();
            }
            pop();
        }
        else{
            while(top != -1 && precedence(peek()) >= precedence(infix[i])){
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    while(top != -1){
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("%s", postfix);

    return 0;
}