#include <stdio.h>
#include <ctype.h>
#include <string.h>

int limit, x = 0;
char production[10][10], array[10];

void find_first(char ch);
void find_follow(char ch);
void Array_Manipulation(char ch);

int main()
{
    int count;
    char option, ch;

    printf("\nEnter Total Number of Productions: ");
    scanf("%d", &limit);

    for (count = 0; count < limit; count++)
    {
        printf("Production [%d]: ", count + 1);
        scanf("%s", production[count]);
    }

    do
    {
        x = 0;
        printf("\nEnter Non-Terminal to find FOLLOW: ");
        scanf(" %c", &ch);

        find_follow(ch);

        printf("FOLLOW(%c) = { ", ch);
        for (count = 0; count < x; count++)
            printf("%c ", array[count]);
        printf("}\n");

        printf("Press Y to continue: ");
        scanf(" %c", &option);

    } while (option == 'y' || option == 'Y');

    return 0;
}

void find_follow(char ch)
{
    int i, j;

    // Rule: Add $ for start symbol
    if (production[0][0] == ch)
        Array_Manipulation('$');

    for (i = 0; i < limit; i++)
    {
        int length = strlen(production[i]);

        for (j = 2; j < length; j++)
        {
            if (production[i][j] == ch)
            {
                // CASE 1: A → αBβ : FOLLOW(B) += FIRST(β)
                if (j + 1 < length)
                {
                    find_first(production[i][j + 1]);
                }

                // CASE 2: A → αB or A → αBε : FOLLOW(B) += FOLLOW(A)
                if (j + 1 == length && ch != production[i][0])
                {
                    find_follow(production[i][0]);
                }
            }
        }
    }
}

void find_first(char ch)
{
    int k;

    // FIRST of terminal
    if (!isupper(ch))
    {
        Array_Manipulation(ch);
        return;
    }

    // FIRST of non-terminal
    for (k = 0; k < limit; k++)
    {
        if (production[k][0] == ch)
        {
            // A → $
            if (production[k][2] == '$')
            {
                find_follow(production[k][0]);
            }
            // A → a...
            else if (!isupper(production[k][2]))
            {
                Array_Manipulation(production[k][2]);
            }
            else
            {
                find_first(production[k][2]);
            }
        }
    }
}

void Array_Manipulation(char ch)
{
    int count;

    for (count = 0; count < x; count++)
        if (array[count] == ch)
            return;

    array[x++] = ch;
}
