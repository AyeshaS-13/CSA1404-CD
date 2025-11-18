#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int words = 0, lines = 0, characters = 0;
    int inWord = 0;

    printf("Enter text (end input with ~):\n");
    scanf("%[^~]", str);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        characters++;

        if (ch == '\n')
            lines++;

        if (isspace(ch)) {
            inWord = 0;
        } else {
            if (inWord == 0) {
                words++;  // Found start of new word
            }
            inWord = 1;
        }
    }

    // Count last line if not empty
    if (characters > 0)
        lines++;

    printf("Total number of words: %d\n", words);
    printf("Total number of lines: %d\n", lines);
    printf("Total number of characters: %d\n", characters);

    return 0;
}
