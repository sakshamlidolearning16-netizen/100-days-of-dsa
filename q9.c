#include <stdio.h>

int main() {
    char s[100];
    scanf("%s", s);

    int i = 0, j = 0;
    while (s[j] != '\0')
        j++;
    j--;

    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }

    printf("%s\n", s);
    return 0;
}