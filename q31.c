#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

int main() {
    int n;
    scanf("%d", &n);

    while(n--) {
        int choice, value;
        scanf("%d", &choice);

        if(choice == 1) {
            scanf("%d", &value);
            if(top == MAX - 1)
                printf("Stack Overflow\n");
            else
                stack[++top] = value;
        }
        else if(choice == 2) {
            if(top == -1)
                printf("Stack Underflow\n");
            else
                printf("%d\n", stack[top--]);
        }
        else if(choice == 3) {
            if(top == -1)
                printf("Stack Underflow\n");
            else {
                for(int i = top; i >= 0; i--)
                    printf("%d ", stack[i]);
                printf("\n");
            }
        }
    }

    return 0;
}