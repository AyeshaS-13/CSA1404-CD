#include <stdio.h>
#include <string.h>

int main() {
    char string[50];
    int flag = 0;   // becomes 1 after first 'b'
    int i;

    printf("The grammar is: S -> aS | Sb | ab\n");
    printf("Enter the string to be checked:\n");
    scanf("%s", string);

    // String must start with 'a'
    if (string[0] != 'a') {
        printf("String not accepted\n");
        return 0;
    }

    for (i = 1; string[i] != '\0'; i++) {
        if (string[i] == 'a') {
            if (flag == 1) {  
                // 'a' after 'b' is not allowed
                printf("String not accepted\n");
                return 0;
            }
        }
        else if (string[i] == 'b') {
            flag = 1;  // once b appears, no more a allowed
        }
        else {
            // invalid character
            printf("String not accepted\n");
            return 0;
        }
    }

    // Must end with at least one b
    if (flag == 0) {
        printf("String not accepted\n");
        return 0;
    }

    printf("String accepted\n");
    return 0;
}
