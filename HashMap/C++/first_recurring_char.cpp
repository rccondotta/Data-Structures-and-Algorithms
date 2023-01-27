/*
Time complexity of O(n)
Space complexity of O(n)
as we are using an extra Hashmap to store the characters
*/
#include <iostream>
#include <unordered_map>
using namespace std;

char firstRecurringCharacter(int input[], int size) {
    unordered_map<int, int> map;
    for (int i = 0; i < size; i++) {
        if (map.count(input[i]) > 0) {
            return input[i];
        }
        else {
            map[input[i]] = i;
        }
    }

    return 0;
}

int main() {
    int input[] = {2,5,1,2,3,5,1,2,4};
    int size = sizeof(input) / sizeof(input[0]);
    int result = firstRecurringCharacter(input, size);
    if(result == 0)
        cout<<"undefined";
    else
        cout << result << endl;

    int input1[] = {2,1,1,2,3,4,1,2,4};
    size = sizeof(input1) / sizeof(input1[0]);
    result = firstRecurringCharacter(input1, size);
    if(result == 0)
        cout<<"undefined";
    else
        cout << result << endl;

    int input2[] = {2, 3, 4, 5};
    size = sizeof(input2) / sizeof(input2[0]);
    result = firstRecurringCharacter(input2, size);
    if(result == 0)
        cout<<"undefined";
    else
        cout << result;

    return 0;
}
