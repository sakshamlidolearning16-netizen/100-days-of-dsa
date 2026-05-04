#include <stdio.h>

int main()
{
    int m, n;
    int a[100][100];
    int symmetric = 1;

    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    if(m != n)
    {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i][j] != a[j][i])
            {
                symmetric = 0;
                break;
            }
        }
        if(!symmetric)
            break;
    }

    if(symmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}