/*
Time complexity of O(n)
Space complexity of O(1)
as we are using a constant-size array(hashmap) to store the characters.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int firstRecurringCharacter(int input[], int size) {
    bool map[256] = {false};
    for (int i = 0; i < size; i++) {
        if (map[input[i]])
            return input[i];
        map[input[i]] = true;
    }
    return 0;
}

int main() {
    int input[] = {2,5,1,2,3,5,1,2,4};
    int size = sizeof(input) / sizeof(input[0]);
    int result = firstRecurringCharacter(input, size);
    if(result == 0)
        printf("undefined");
    else
        printf("%d", result);

    int input1[] = {2,1,1,2,3,4,1,2,4};
    size = sizeof(input1) / sizeof(input1[0]);
    result = firstRecurringCharacter(input1, size);
    if(result == 0)
        printf("undefined");
    else
        printf("%d", result);

    int input2[] = {2, 3, 4, 5};
    size = sizeof(input2) / sizeof(input2[0]);
    result = firstRecurringCharacter(input2, size);
    if(result == 0)
        printf("undefined");
    else
        printf("%d", result);

    return 0;
}
