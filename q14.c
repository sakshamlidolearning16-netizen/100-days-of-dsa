#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n][n];
    int isIdentity = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if((i == j && a[i][j] != 1) || (i != j && a[i][j] != 0))
                isIdentity = 0;
        }
    }

    if(isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}