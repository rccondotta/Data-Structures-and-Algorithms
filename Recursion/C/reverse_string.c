#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverseStringIterative(char* input) {
    int length = strlen(input);

    char reversed_str[length + 1];
    for (int i = 0; i < length; i++) {
        reversed_str[i] = input[length - i - 1];
    }
    reversed_str[length] = '\0';

    strcpy(input, reversed_str);
}

void reverseStringRecursive(char* input) {
    if (*input == '\0') {
        return;
    }

    reverseStringRecursive(input + 1);

    printf("%c", *input);
}


int main() {
    char input[] = "yoyo mastery";
    reverseStringIterative(input);
    printf("%s\n", input);

    char str[] = "yoyo mastery";
    reverseStringRecursive(str);
    printf("\n");

    return 0;
}
