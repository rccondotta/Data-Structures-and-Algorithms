#include <stdio.h>
#include <stdlib.h>

#include <string.h>

/*
Time Complexity: O(n/2) where n is the length of the input string.
This is because the for loop iterates through half of the string, swapping the elements at the beginning and end, and moving towards the middle.

Space Complexity: O(1) as the method is modifying the original string passed as parameter and no new memory is allocated.
*/
void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main() {
    char test[] = "Hey, how you doing?";
    printf("Original string: %s\n", test);
    reverse(test);
    printf("Reversed string: %s\n", test);
    return 0;
}

