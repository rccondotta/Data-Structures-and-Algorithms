#include <stdio.h>

int findfactorialRecursive(int number) {

    if (number == 0) {
        return 1;
    }

    return number * findfactorialRecursive(number - 1);
}

int findfactorialIterative(int number) {

    int result = 1;
    for (int i = 1; i <= number; i++) {
        result *= i;
    }

    return result;
}

int main() {
    int number, result;
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    result = findfactorialRecursive(number);
    printf("The factorial of %d is %d\n", number, result);
    result = findfactorialIterative(number);
    printf("The factorial of %d is %d\n", number, result);
    return 0;
}