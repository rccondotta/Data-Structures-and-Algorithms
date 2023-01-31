#include <iostream>
#include <string>

std::string reverseStringIterative(std::string input) {
    std::string reversed_str = "";

    for (int i = input.length() - 1; i >= 0; i--) {
        reversed_str += input[i];
    }

    return reversed_str;
}

std::string reverseStringRecursive(std::string input) {
    if (input.empty()) {
        return input;
    }
    else {
        return reverseStringRecursive(input.substr(1)) + input[0];
    }
}

int main() {
    std::cout << reverseStringIterative("yoyo mastery") << std::endl;
    std::cout << reverseStringRecursive("yoyo mastery") << std::endl;

    return 0;
}
