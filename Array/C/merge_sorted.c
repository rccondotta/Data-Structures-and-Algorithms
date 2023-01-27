#include <stdio.h>
#include <stdlib.h>

#include <string.h>

/*
Time complexity: O(m+n) because we are iterating through both arrays once.

Space complexity: O(m+n) because we are creating an additional array of size m+n to store the merged result.
*/
void mergeSortedArrays(int a[], int m, int b[], int n) {
    int i = 0, j = 0, k = 0;
    int c[m + n];
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
    for (i = 0; i < m + n; i++) {
        a[i] = c[i];
    }
}

int main() {
    int a[] = {0, 3, 4, 31};
    int m = sizeof(a) / sizeof(a[0]);
    int b[] = {4, 5, 30};
    int n = sizeof(b) / sizeof(b[0]);

    mergeSortedArrays(a, m, b, n);

    for (int i = 0; i < m + n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
