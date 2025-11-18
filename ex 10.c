#include <stdio.h>
#include <string.h>

int main() {
    char gram[50], part1[50], part2[50];
    char modifiedGram[50], newGram[50];
    int i = 0, j = 0, k = 0, pos = 0;

    printf("Enter Production (Format S->α|β): ");
    scanf("%s", gram);

    // Extract α (part1) and β (part2)
    while (gram[i] != '|' && gram[i] != '\0') {
        part1[j++] = gram[i];
        i++;
    }
    part1[j] = '\0';

    i++;  // skip '|'
    j = 0;
    while (gram[i] != '\0') {
        part2[j++] = gram[i++];
    }
    part2[j] = '\0';

    // Find common prefix
    i = 0;
    while (part1[i] == part2[i] && part1[i] != '\0') {
        modifiedGram[k++] = part1[i];
        i++;
    }

    if (k == 0) {
        printf("\nNo Left Factoring Needed.\n");
        return 0;
    }

    modifiedGram[k++] = 'X';  // S -> commonPrefixX
    modifiedGram[k] = '\0';
    pos = i;

    // Build X → remaining of part1 | remaining of part2
    k = 0;
    for (i = pos; part1[i] != '\0'; i++)
        newGram[k++] = part1[i];

    newGram[k++] = '|';

    for (i = pos; part2[i] != '\0'; i++)
        newGram[k++] = part2[i];

    newGram[k] = '\0';

    // Output
    printf("\nLeft Factored Grammar:\n");
    printf("S -> %s\n", modifiedGram);
    printf("X -> %s\n", newGram);

    return 0;
}
