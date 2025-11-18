#include <stdio.h>

int main() {
    char str[100];
    int words = 0, lines = 1, characters = 0;

    printf("Enter text (end with ~):\n");

    scanf("%[^~]", str);   // Read until ~

    for (int i = 0; str[i] != '\0'; i++) {

        if (str[i] == ' ') {
            words++;
        }
        else if (str[i] == '\n') {
            lines++;
            words++;   // New line means new word starts
        }
        else {
            characters++;
        }
    }

    if (characters > 0)
        words++;

    printf("Total number of words : %d\n", words);
    printf("Total number of lines : %d\n", lines);
    printf("Total number of characters : %d\n", characters);

    return 0;
}
 
