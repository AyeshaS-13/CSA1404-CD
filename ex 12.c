#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[100];
int i = 0;

int E();
int EP();
int T();
int TP();
int F();

int main() 
{
    printf("Recursive Descent Parsing for Grammar:\n");
    printf("E  -> T E'\n");
    printf("E' -> + T E' | ε\n");
    printf("T  -> F T'\n");
    printf("T' -> * F T' | ε\n");
    printf("F  -> (E) | id\n\n");

    printf("Enter the string: ");
    scanf("%s", input);

    i = 0;

    if (E() && input[i] == '\0') {
        printf("\nString is accepted\n");
    } 
    else {
        printf("\nString is NOT accepted\n");
    }

    return 0;
}

// E → T E'
int E() {
    if (T()) {
        if (EP())
            return 1;
    }
    return 0;
}

// E' → + T E' | ε
int EP() {
    if (input[i] == '+') {
        i++;
        if (T())
            return EP();
        return 0;
    }
    return 1;  // epsilon
}

// T → F T'
int T() {
    if (F()) {
        if (TP())
            return 1;
    }
    return 0;
}

// T' → * F T' | ε
int TP() {
    if (input[i] == '*') {
        i++;
        if (F())
            return TP();
        return 0;
    }
    return 1; // epsilon
}

// F → (E) | ID
int F() {
    if (input[i] == '(') {
        i++;
        if (E()) {
            if (input[i] == ')') {
                i++;
                return 1;
            }
        }
        return 0;
    }
    else if (isalpha(input[i])) {  // ID
        i++;
        return 1;
    }
    return 0;
}
