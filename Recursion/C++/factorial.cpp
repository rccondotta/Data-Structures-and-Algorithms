#include <iostream>

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
    int number=5;
    int result;

    result = findfactorialRecursive(number);
    std::cout << "The factorial of " << number << " is " << result << std::endl;

    result = findfactorialIterative(number);
    std::cout << "The factorial of " << number << " is " << result << std::endl;
    return 0;
}
