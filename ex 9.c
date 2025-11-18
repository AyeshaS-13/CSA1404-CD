#include <stdio.h>
#include <string.h>

#define SIZE 50

int main() {
    int num;
    char production[10][SIZE];

    printf("Enter number of productions: ");
    scanf("%d", &num);

    printf("Enter productions (Example: E->E-A|B):\n");
    for (int i = 0; i < num; i++) {
        scanf("%s", production[i]);
    }

    for (int i = 0; i < num; i++) {
        printf("\nGRAMMAR: %s\n", production[i]);

        char A = production[i][0];   // Left-hand side non-terminal
        char rhs[SIZE];
        strcpy(rhs, production[i] + 3); // Copy everything after "->"

        char alpha[10][SIZE], beta[10][SIZE];
        int aCount = 0, bCount = 0;

        char *token = strtok(rhs, "|");

        while (token != NULL) {
            if (token[0] == A) {  
                // Left recursive alpha: A -> Aα
                strcpy(alpha[aCount++], token + 1);
            } else {
                // Non-left-recursive beta
                strcpy(beta[bCount++], token);
            }
            token = strtok(NULL, "|");
        }

        if (aCount == 0) {
            printf("→ Not Left Recursive.\n");
        } 
        else {
            printf("→ Left Recursive.\n");
            printf("\nGrammar without Left Recursion:\n");

            // A -> βA'
            printf("%c -> ", A);
            for (int k = 0; k < bCount; k++) {
                printf("%s%c'", beta[k], A);
                if (k != bCount - 1) printf(" | ");
            }

            printf("\n%c' -> ", A);

            // A' -> αA' | E
            for (int k = 0; k < aCount; k++) {
                printf("%s%c' | ", alpha[k], A);
            }
            printf("E\n");  // E = epsilon
        }
    }

    return 0;
}
