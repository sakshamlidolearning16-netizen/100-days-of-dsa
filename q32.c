#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value){
    if(top < MAX-1){
        stack[++top] = value;
    }
}

void pop(){
    if(top != -1){
        top--;
    }
}

int main(){
    int n, m, value;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &value);
        push(value);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++){
        pop();
    }

    for(int i = top; i >= 0; i--){
        printf("%d ", stack[i]);
    }

    return 0;
}