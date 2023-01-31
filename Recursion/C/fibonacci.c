#include <stdio.h>

int fibonacciIterative(int n) {
    int a = 0, b = 1, c, i;

    if(n == 0)
        return a;

    for(i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int fibonacciRecursive(int n) {
    if(n == 0 || n == 1)
        return n;

    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}

int main() {
    int n = 10;
    printf("Fibonacci number at position %d (iterative) is: %d\n", n, fibonacciIterative(n));
    printf("Fibonacci number at position %d (recursive) is: %d\n", n, fibonacciRecursive(n));
    return 0;
}
