#include <stdio.h>
#include <ctype.h>

int main() {
    char a[10];
    int flag = 1, i = 1;

    printf("\nEnter an identifier: ");
    fgets(a, sizeof(a), stdin);

    // Remove newline if present
    if (a[0] != '\0' && a[strlen(a)-1] == '\n')
        a[strlen(a)-1] = '\0';

    if (isalpha(a[0])) {
        while (a[i] != '\0') {
            if (!isdigit(a[i]) && !isalpha(a[i])) {
                flag = 0;
                break;
            }
            i++;
        }
    } else {
        flag = 0;
    }

    if (flag == 1)
        printf("\nValid identifier\n");
    else
        printf("\nNot a valid identifier\n");

    return 0;
}
