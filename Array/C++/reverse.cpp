#include <iostream>
#include <algorithm>

using namespace std;

/*
Time Complexity: O(n/2) where n is the length of the input string.
This is because the std::reverse function iterates through half of the string, swapping the elements at the beginning and end, and moving towards the middle.

Space Complexity: O(1) as the method is modifying the original string passed as parameter and no new memory is allocated.
*/
std::string reverse(std::string str) {
    std::reverse(str.begin(), str.end());
    return str;
}

int main() {

    std::string rstring = reverse("Hey, how you doing");
    std::cout << rstring << std::endl;
}