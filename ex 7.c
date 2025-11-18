 #include <stdio.h>
#include <ctype.h>
#include <string.h>

void FIRST(char[], char);
void addToResultSet(char[], char);

int numOfProductions;
char productionSet[10][10];

int main() {
    int i;
    char choice, c;
    char result[20];

    printf("How many productions? : ");
    scanf("%d", &numOfProductions);

    printf("\nEnter productions (use $ for epsilon)\n");
    for (i = 0; i < numOfProductions; i++) {
        printf("Production %d: ", i + 1);
        scanf("%s", productionSet[i]);
    }

    do {
        printf("\nFind FIRST of: ");
        scanf(" %c", &c);

        FIRST(result, c);

        printf("\nFIRST(%c) = { ", c);
        for (i = 0; result[i] != '\0'; i++)
            printf("%c ", result[i]);
        printf("}\n");

        printf("\nPress Y to continue: ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void FIRST(char Result[], char c) {
    int i, j, k;

    char subResult[20];
    Result[0] = '\0';

    // Case 1: terminal
    if (!isupper(c)) {
        addToResultSet(Result, c);
        return;
    }

    // Case 2: non-terminal
    for (i = 0; i < numOfProductions; i++) {

        // Check productions
        if (productionSet[i][0] == c) {

            // If production is X -> $
            if (productionSet[i][2] == '$') {
                addToResultSet(Result, '$');
            } else {
                j = 2;

                while (productionSet[i][j] != '\0') {

                    // Clear subResult every time
                    subResult[0] = '\0';

                    FIRST(subResult, productionSet[i][j]);

                    // Add all elements of subResult
                    for (k = 0; subResult[k] != '\0'; k++)
                        addToResultSet(Result, subResult[k]);

                    // If epsilon is present → continue checking next symbol
                    int epsilonFound = 0;

                    for (k = 0; subResult[k] != '\0'; k++)
                        if (subResult[k] == '$')
                            epsilonFound = 1;

                    if (!epsilonFound)
                        break;

                    j++;
                }
            }
        }
    }
}

void addToResultSet(char Result[], char val) {
    int k;
    for (k = 0; Result[k] != '\0'; k++)
        if (Result[k] == val)
            return; // avoid duplicates

    Result[k] = val;
    Result[k + 1] = '\0';
}
