#include <iostream>
#include <vector>

using namespace std;

/*
Time complexity: O(m+n) because we are iterating through both arrays once.

Space complexity: O(m+n) because we are creating an additional vector of size m+n to store the merged result.
*/
void mergeSortedArrays(std::vector<int> &a, std::vector<int> &b) {
    int m = a.size();
    int n = b.size();
    int i = 0, j = 0, k = 0;

    std::vector<int> c(m + n);
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while (i < m) {
        c[k++] = a[i++];
    }

    while (j < n) {
        c[k++] = b[j++];
    }
    a = c;
}

int main() {
    std::vector<int> a = {0, 3, 4, 31};
    std::vector<int> b = {4, 5, 30};

    mergeSortedArrays(a, b);

    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }

    return 0;
}
