#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char input[20], stack[20];
int ip = 0, top = -1, len;

void check()
{
    // Reduce E -> a or b
    if (stack[top] == 'a' || stack[top] == 'b')
    {
        stack[top] = 'E';
        printf("\t\tE->%c", input[ip - 1]);
        return;
    }

    // Reduce E -> E+E
    if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '+' && stack[top - 2] == 'E')
    {
        top -= 2;
        stack[top] = 'E';
        stack[top + 1] = '\0';
        printf("\t\tE->E+E");
        return;
    }

    // Reduce E -> E/E
    if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '/' && stack[top - 2] == 'E')
    {
        top -= 2;
        stack[top] = 'E';
        stack[top + 1] = '\0';
        printf("\t\tE->E/E");
        return;
    }

    // Reduce E -> E*E
    if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '*' && stack[top - 2] == 'E')
    {
        top -= 2;
        stack[top] = 'E';
        stack[top + 1] = '\0';
        printf("\t\tE->E*E");
        return;
    }
}

int main()
{
    printf("\n\tSHIFT REDUCE PARSER");
    printf("\nGrammar:");
    printf("\nE -> E+E\nE -> E/E\nE -> E*E\nE -> a | b\n");

    printf("\nEnter input string: ");
    scanf("%s", input);

    len = strlen(input);

    printf("\nSTACK\t\tINPUT\t\tACTION");

    while (ip < len)
    {
        stack[++top] = input[ip];
        stack[top + 1] = '\0';

        printf("\n%s\t\t%s\t\tShift %c", stack, input + ip + 1, input[ip]);

        ip++;
        check();
    }

    // Final reduction
    while (top > 0)
    {
        printf("\n%s\t\t$\t\t", stack);
        check();
    }

    if (stack[0] == 'E')
        printf("\n%s\t\t$\t\tACCEPTED\n", stack);
    else
        printf("\nREJECTED");

    return 0;
}
